/*
 * delete 和 new 的形式必须匹配(delete [] 和 new [])
 * 等级: 必须
 * 原因: delete 执行在 new[n] 的指针上时, 只会 delete 一个对象
 */

#include <iostream>
#include <string>

using namespace std;

struct Value {
    int num = 0;

    Value() = default;

    ~Value() {
        cout << "Delete " << num << endl;
    }
};


int main(int argc, char **argv) {
    Value *val_array = new Value[10];
    for (int i = 0; i < 10; i++) {
        val_array[i].num = i;
    }

    // 会出错! 应该使用 delete[]
    delete val_array;
}
