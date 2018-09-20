/*
 * const 和 pointer
 * 按照从右往左读的顺序
 *  - const T * 或者 T const * 是 pointer to a const T, T 是 const, 不能通过 pointer 修改 T, 但是 pointer 自己可以被修改(指向别的 T)
 *  - T * const 是 const pointer to a T, pointer 是 const, 可以通过 pointer 修改 T, 但是 pointer 自己不能被修改
 * 等级: 必须
 * 原因: const 和 pointer 的位置
 */

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char **argv) {
  uint16_t value = 1;

  uint16_t * value_p = &value;
  *value_p = 12;
  cout << boolalpha << (value == 12) << endl;

   uint16_t * const value_const_p = &value;
  *value_const_p = 13;
  uint16_t another_value = 1;
//  value_const_p = &another_value;

  const uint16_t * const_value_p = &value;
//  *const_value_p = 14;
  const_value_p = value_const_p;
}
