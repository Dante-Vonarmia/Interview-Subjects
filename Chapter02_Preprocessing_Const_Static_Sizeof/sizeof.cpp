#include "iostream"
using namespace std;

class Base
{
public:
	Base(int x) : a(x){} // 4
	~Base(){}

	void print() {
		cout << "base" << endl;
	}
private:
	int a;
};

class Derived : public Base
{
public:
	Derived(int x) : Base(x-1), b(x){} // 8
	~Derived(){}

	void print() {
		cout << "derived" << endl;
	}
private:
	int b;
};
class A
{
public:
	A(int x) : a(x){} // 4
	~A(){}
	virtual void print() {  // 4
		cout << "A" << endl;
	}
private:
	int a;
};
class B : public A
{
public:
	B(int x) : A(x-1), b(x){} // 8
	~B(){}

	virtual void print() { // 4
		cout << "B" << endl;
	}
private:
	int b;
};
int main(int argc, char const *argv[])
{
	Base obj1(1);
	cout << "size of Base obj is " << sizeof(obj1) << endl; // 4
	Derived obj2(2);
	cout << "size of Derived obj is " << sizeof(obj2) << endl; // 8

	A a(1);
	cout << "size of A obj is " << sizeof(a) << endl; // 16
	B b(2);
	cout << "size of B obj is " << sizeof(b) << endl; // 16
	return 0;
}