/*
 * vector reserve and iterator
 * 等级: 知晓
 * 原因:
 */

#include <vector>
#include <list>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

void PrintVector(const vector<int> vec) {
    cout << vec.size() << ": ";
    for (int i:vec) cout << i << " ";
    cout << endl;

}

void PrintArray(const int *arr, size_t size) {
    cout << size << ": ";
    for (size_t i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void MemCopy(int *arr, const vector<int>& vec) {
    memcpy(arr, vec.data(), vec.size() * sizeof(int));
    PrintArray(arr, 5);
}

int main(int argc, char **argv) {
    vector<int> a(5);
    vector<int> b(5, 1);

    PrintVector(a);

    a.insert(a.end(), b.begin(), b.end());
    PrintVector(a);

    copy(b.begin(), b.end(), a.begin());
    PrintVector(a);

    a.resize(0);
    PrintVector(a);

    b = {1, 2, 3, 4, -5};
    int c[5];
    memcpy(c, b.data(), b.size() * sizeof(int));
    PrintArray(c, 5);

    b = {-2, -3};
    MemCopy(c + 1, b);
    PrintArray(c, 5);
}
