/*
 * reinterpret_cast
 * 等级: 知晓
 * 原因: reinterpret_cast 只是把原指针所指向值的 bits 类型变为新的类型, bits 的值不变
 */

#include <vector>
#include <list>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

template<typename T>
string NumberToBits(T num, size_t bit_width) {
  list<char> bits;
  for (size_t i = 1; i < bit_width; i++) {
    if (num & 1) bits.push_front('1');
    else bits.push_front('0');
    if (i % 8 == 0) bits.push_front(' ');
    num = num >> 1;
  }
  return string(bits.begin(), bits.end());
}

int main(int argc, char **argv) {
  uint16_t value = 256;
  uint16_t *value_p = &value;
  auto value_p_i32 = reinterpret_cast<uint32_t *>(&value);
  auto value_p_i8 = reinterpret_cast<uint8_t *>(&value);
  cout << *value_p << endl;
  cout << *value_p_i32 << endl;
  cout << +*value_p_i8 << endl;

  cout << NumberToBits(value, 16) << endl;
  cout << NumberToBits(*value_p_i32, 32) << endl;
  cout << NumberToBits(*value_p_i8, 8) << endl;
}
