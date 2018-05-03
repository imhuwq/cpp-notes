/*
 * 父类的析构函数应当为虚函数
 * 等级: 必须
 * 原因: 当父类的析构函数不为虚函数时,如果通过父类指针删除子类对象,则不会调用子类的析构函数,造成子类资源没有被正确释放
 */


#include <iostream>

using namespace std;

class Base {
private:
public:
    Base() { cout << "Constructing Base..." << endl; }

    ~Base() { cout << "Destructing Base..." << endl; }  // 这是不推荐的做法
//    virtual ~Base() { cout << "Destructing Base..." << endl; }  // 这才是正确的做法

};

class Derived : public Base {
private:
public:
    Derived() { cout << "Constructing Derived..." << endl; }

    ~Derived() { cout << "Destructing Derived..." << endl; }
};


int main() {
    Derived *d = new Derived();
    Base *b = d;
    delete (b);
    return 0;
}
