/*
 * 复制构造函数必须以 reference 传参
 * 等级: 必须
 * 原因: 1. 否则在往复制构造函数传入参数时调用复制构造函数, 导致无限调用
 */


#include <string>
#include <iostream>

using namespace std;

template<typename T>
class KeyVal {
public:
    KeyVal(const string &key, const T &val) : key(key), val(val) {}

    KeyVal(const KeyVal &rhs) {
        key = rhs.key;
        val = rhs.val;
    }

    template <typename T_>
    friend ostream &operator<<(ostream &os, const KeyVal<T_> &kv);

private:
    string key;
    T val;
};

template <typename T>
ostream &operator<<(ostream &os, const KeyVal<T> &kv) {
    os << kv.key << ": " << kv.val;
}

int main(int argc, char **argv) {
    KeyVal<int> a("a", 1);
    KeyVal<int> b(a);

    cout << a << endl;
    cout << b << endl;
}