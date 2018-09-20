/*
 * std::move 对 vector 的操作
 * 一种是 A = move(B), 直接把 B 里面的元素 move 到 A, 操作完成后, B 为空, A 包含原来的元素, A 的 capacity 会自动适配
 * 一种是 move(B_first, B_end, A_first), 把 B 里面从 [B_first, B_end) 范围内的元素 move 到 A [A_first...end(A)) 范围内
 * 对于第二种操作, 有三点注意点:
 *  - A 的 capacity 要能容得下 move 进来的元素, 否则会异常
 *  - move 进来的元素数量为 min(B_end-B_first, end(A) - A_first), 如果 A_first == end(A), 则相当于没有任何元素 move 进来
 *  - move 后 B 里面的元素还可以获取, 但不保证和原来一样
 * 等级: 知晓
 * 原因: 正确使用 std API
 */

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

void show_vector_int(vector<int> vec, const string &vec_name) {
    cout << "Contents in " << vec_name << ": ";
    for (int n:vec) {
        cout << n << " ";
    }
    cout << endl;
}

void test_move_to_empty() {
    cout << "Testing move to empty..." << endl;
    vector<int> from = {1, 2, 3, 4};
    vector<int> empty = {};
    show_vector_int(from, "from");
    show_vector_int(empty, "empty");

    cout << "Capacity before move: from=" << from.capacity() << " empty=" << empty.capacity() << endl;
    empty = move(from);
    cout << "Capacity after move: from=" << from.capacity() << " empty=" << empty.capacity() << endl;
//    cout << "Access from after move: from[1]=" << from[1] << endl;  // causing SIGSEGV

    show_vector_int(from, "from");
    show_vector_int(empty, "empty");
    cout << endl;
}

void test_move_to_half_full() {
    cout << "Testing move to half full..." << endl;

    vector<int> from = {1, 2, 3, 4};
    vector<int> half = {6};
    show_vector_int(from, "from");
    show_vector_int(half, "half");

    cout << "Capacity before move: from=" << from.capacity() << " half=" << half.capacity() << endl;
    half = move(from);
    cout << "Capacity after move: from=" << from.capacity() << " half=" << half.capacity() << endl;
//    cout << "Access from after move: from[1]=" << from[1] << endl;  // causing SIGSEGV
    show_vector_int(from, "from");
    show_vector_int(half, "half");
    cout << endl;
}

void test_move_to_full() {
    cout << "Testing move into full..." << endl;

    vector<int> from = {1, 2, 3, 4};
    vector<int> full = {99, 99, 99, 99};
    show_vector_int(from, "from");
    show_vector_int(full, "full");

    cout << "Capacity before move: from=" << from.capacity() << " full=" << full.capacity() << endl;
//    move(begin(from), end(from), end(full));  // causing SIGABRT if move directly since full is ... full
    full.reserve(full.capacity() + from.capacity());
    move(begin(from), end(from), begin(full) + 2);
    cout << "Capacity after move: from=" << from.capacity() << " full=" << full.capacity() << endl;
    cout << "Access from after move: from[1]=" << from[1] << ". But it is not Guaranteed the same value before the move operation" << endl;

    show_vector_int(from, "from");
    show_vector_int(full, "full");
    cout << endl;
}

int main(int argc, char **argv) {
    test_move_to_empty();
    test_move_to_half_full();
    test_move_to_full();
}
