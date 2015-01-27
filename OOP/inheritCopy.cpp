// 写一个继承类的复制函数
// Q: 假如父类有似有成员，并且这些私有成员必须在调用派生类的复制构造函数时被初始化，在这种情况下又该怎么做呢？
// A: 编写继承类的复制函数有一个原则：使用父类的复制构造函数

#include "iostream"
#include "string.h"
using namespace std;

class Base
{
public:
	Base():i(0) // 默认普通构造函数
	{
		cout << "Base()" << endl;
	}
	Base(int n):i(n) // 普通构造函数
	{
		cout << "Base(int)" << endl;
	}
	Base(const Base &b):i(b.i) // 复制构造函数
	{
		cout << "Base(base&)" << endl;
	}
private:
	int i; // 私有成员
};

class Derived : public Base
{
public:
	Derived():Base(0), j(0) // 默认普通构造函数
	{
		cout << "Derived()" << endl;
	}
	Derived(int m, int n):Base(m), j(n) // 普通构造函数
	{
		cout << "Derived(int)" << endl;
	}
	Derived(Derived &obj) : Base(obj), j(obj.j) // Derived类复制构造函数 调用了Base的复制构造函数
	{
		cout << "Derived(Derived&)" << endl;
	}
private:
	int j;
};

int main(int argc, char const *argv[])
{
	Base b(1);
	Derived obj(2, 3);
	cout << "---------" << endl;
	Derived d(obj); // 调用Derived的复制构造函数
	cout << "---------" << endl;

	return 0;
}