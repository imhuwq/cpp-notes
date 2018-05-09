/*
 * 在复制赋值函数处理自赋值和异常
 * 等级: 必须
 * 原因: 1. Object a[2] = {obj1, obj1}, a[0] = a[1]
 *      2. 赋值失败要保证原状态有效
 */


#include <string>

using namespace std;

struct Value {
    int num;
    string str;

    explicit Value(int num, const string &str) : num(num), str(str) {}

    Value(const Value &rhs) {
        num = rhs.num;
        str = rhs.str;
    }
};

class Object {
public:
    string key;
    Value *val = nullptr;

    Object(const string &k, const Value &v) : key(k) {
        val = new Value(v);
    }

    Object(const Object &rhs) : key(rhs.key) {
        val = new Value(*rhs.val);
    }

    Object &operator=(const Object &rhs) {
        if (this == &rhs) return *this;

        // new 可能抛出异常, 所以先 new 再 delete, 最后再修改 key
        // 但是更合适的办法是有 shared_ptr 替代原始指针
        Value *temp_val = new Value(*rhs.val);
        delete val;
        val = temp_val;

        key = rhs.key;
        return *this;
    }
};

int main(int argc, char **argv) {
    Value val(2, "2");
    Value val2(val);

    Object obj("o", val);
    Object obj2(obj);
}
