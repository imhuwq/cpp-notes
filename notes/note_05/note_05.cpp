/*
 * 复制赋值函数返回指向自己的 reference
 * 等级: 推荐
 * 原因: 支持连续赋值 a = b = c
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

    KeyVal &operator=(const KeyVal &rhs) {
        key = rhs.key;
        val = rhs.val;
        return *this;
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
    KeyVal<int> c = b = a;

    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
}