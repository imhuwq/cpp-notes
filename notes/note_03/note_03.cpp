/*
 * 1. inline 函数会增加编译输出的体积大小
 * 2. 有时 inline 函数会失效
 * 3. inline 函数对后期开发和维护不那么友好
 * 等级: 知晓
 * 原因: 1. inline 函数会以函数体替换函数调用, 所以添加了编译大小
 *      2. 对 inline 函数取指针, 则编译器必须知晓 inline 函数的函数体.
 *      3. 复杂的 inline 函数也会忽略 inline 请求
 *      4. 因为 inline 函数没有自己的 symbol, 所以更新 inline 函数后需要重新编译所有使用到它的源码, 而不是重新连接
 *      5. 也因为 inline 函数没有自己的 symbol, 所以 GDB 不好进行调试
 */


#include <iostream>

using namespace std;

int main() {
    cout << "编译 note03_normal, note_03_inline, 注意它们可执行文件的大小." << endl;
    return 0;
}
