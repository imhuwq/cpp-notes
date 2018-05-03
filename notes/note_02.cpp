/*
 * 不要在构造函数和析构函数中调用虚函数
 * 等级: 必须
 * 原因: 1. 调用哪个版本的虚函数由对象运行时所属的类型决定
 *      2. 构造函数和析构函数执行期间,对象的类型为构造函数和析构函数所属的类,即使它们是由子类的构造/析构函数触发的
 *      3. 所以构造函数和析构函数中调用的虚函数为构造函数和析构函数所属的类,而不是子类
 */


#include <iostream>

using namespace std;

class Base {
private:
public:
    Base() {
        LogConstruction();  // 此处调用虚函数 LogConstruction 并不会被解析为子类的 LogConstruction, 因为在调用期间对象的类型为 Base
    }

    virtual ~Base() {
        LogDestruction();  // 此处调用虚函数 LogDestruction 并不会被解析为子类的 LogDestruction, 因为在调用期间对象的类型为 Base
    }

    virtual void LogConstruction() { cout << "Constructing Base..." << endl; }

    virtual void LogDestruction() { cout << "Destructing Base..." << endl; }

};

class Derived : public Base {
private:
public:
    Derived() {}

    ~Derived() {}

    virtual void LogConstruction() { cout << "Constructing Derived..." << endl; }

    virtual void LogDestruction() { cout << "Destructing Derived..." << endl; }
};


int main() {
    Derived *d = new Derived();
    Base *b = d;
    delete (b);
    return 0;
}
