int add_two(int a, int b) {
    int c = a + b;
    c = a * c + b;
    return c;
}

inline int inline_add_two(int a, int b) {
    int c = a + b;
    c = a * c + b;
    return c;
}

int main() {
    add_two(1, 2);
    return 0;
}
