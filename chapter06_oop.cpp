#include "iostream"
#include "string.h"
using namespace std;

/****************/
/* Interview 37 */
/****************/
// #include "malloc.h"
// #include "memory.h"
// // new 操作符重载的使用
// // 重载new操作符第一个参数必须是size_t类型的，且传入的值就是类的大小

// class Blanks // 类的大小为1
// {
// public:
// 	void *operator new(size_t stAllocateBlock, char chInit);
// };

// void *Blanks::operator new(size_t stAllocateBlock, char chInit)
// {
// 	void *pvTemp = malloc( stAllocateBlock);
// 	if (pvTemp != 0)
// 	{
// 		memset(pvTemp, chInit, stAllocateBlock);	// 用chInit初始化分配的内存
// 	}
// 	return pvTemp;
// }

// int main(int argc, char const *argv[])
// {
// 	Blanks *a5 = new(0xa5) Blanks; 	// 用Blanks对象地址初始化a5
// 	return a5 != 0;
// }

/****************/
/* Interview 36 */
/****************/
// Refer to ./String

/****************/
/* Interview 35 */
/****************/
// 对于下面的类MyString，要求重载一些运算符后可以计算表达式a=b+c；
// class MyString
// {
// public:
// 	MyString(char const *s)						// 参数为字符指针的构造函数
// 	{
// 		str = new char[strlen(s) + 1];
// 		strcpy(str, s);
// 	}
// 	~MyString()									// 析构函数释放str堆内存
// 	{
// 		delete[] str;
// 	}
// 	MyString & operator=(MyString &string)		// 赋值函数，重载 =
// 	{
// 		if (this == &string)
// 		{
// 			return *this;
// 		}
// 		if (str != NULL)						// 释放内存
// 		{
// 			delete[] str;
// 		}
// 		str = new char[strlen(string.str) + 1];	// 申请内存
// 		strcpy(str, string.str);				// 复制字符串内容
// 		return *this;
// 	}

// 	// (1) 重载 + (改变被加对象)
// 	MyString & operator+(MyString &string)
// 	{
// 		char *temp = str;
// 		str = new char[strlen(temp) + strlen(string.str) + 1];
// 		strcpy(str, temp);						// 复制第一个字符串
// 		delete[] temp;
// 		strcat(str, string.str);				// 连接第二个字符串
// 		return *this;							// 返回*this对象，它改变了被加对象的内容。
// 	}

// 	// (2) 重载 + (不改变被加对象) 
// 	// MyString & operator+(MyString &string)
// 	// {
// 	// 	MyString *pString = new MyString("");	// 堆内存中构造对象
// 	// 	pString -> str = new char[strlen(str) + strlen(string.str) + 1];
// 	// 	strcpy(pString->str, str);				// 复制第一个字符串
// 	// 	strcat(pString->str, string.str);		// 连接第二个字符串
// 	// 	return *pString;
// 	// }

// 	// friend MyString & operator+(MyString &left, MyString &right);

// 	void print()
// 	{
// 		cout << str << endl;
// 	}
// private:
// 	char *str;
// };

// // 友员 str: public access
// // (3) 重载 + (不改变被加对象)
// // MyString & operator+(MyString &left, MyString &right)
// // {
// // 	MyString *pString = new MyString("");
// // 	pString->str = new char[strlen(left.str) + strlen(right.str) + 1];
// // 	strcpy(pString->str, left.str);
// // 	strcat(pString->str, right.str);

// // 	return *pString;
// // }

// int main(int argc, char const *argv[])
// {
// 	MyString a("hello ");
// 	MyString b("world");

// 	MyString c("");
// 	c = c + a;
// 	c.print();
// 	c = c + b;
// 	c.print();

// 	c = a + b;
// 	a.print();
// 	c.print();

// 	return 0;
// }

/****************/
/* Interview 34 */
/****************/
// 重载和覆写有何区别
// 重载是指子类改写父类的方法
// 覆写是指同一个函数的不同版本之间参数不同

// 重载是编写一个与已有函数同名但是参数表不同的方法
// (1) 方法名必须相同。
// (2) 参数列表必须不相同，与参数列表顺序无关。
// (3) 返回值类型可以不相同。

// 覆写是派生类重写基类的虚函数
// (1) 只有虚方法和抽象方法才能够被覆写。
// (2) 相同的函数名。
// (3) 相同的参数列表。
// (4) 相同的返回值类型。

// 重载是一种语法规则，由编译器在编译阶段完成，不属于面向对象的编程；
// 覆写是由运行阶段决定的，是面向对象编程的重要特征

/****************/
/* Interview 33 */
/****************/
// (A) int calc(int, int)
// 	int calc(const int, const int)
// 	A: F

// (B) int get();
// 	double get();
// 	A: F

// (C) int *reset(int *);
// 	double *reset(double *);
// 	A: T

// (D) extern "C" int compute(int *, int);
// 	extern "C" double compute(double *, double);	// 只能有一个函数被指定为extern“C”。
// 	A: F

/****************/
/* Interview 32 */
/****************/
// Overload
// 函数重载是用来描述同名函数具有相同或者相似的功能， 但数据类型或者参数不同的函数管理操作。
// 函数名经过C++编译器处理后包含了原函数名、函数参数数量以及返回类型信息，而C语言不会对函数名进行处理。
// class Test
// {
// public:
// 	int add(int x, int y)	// 相加，传入参数以及返回值都是int
// 	{
// 		return x+y;
// 	}
// 	float add(float x, float y)	// 相加，传入参数以及返回值都是float
// 	{
// 		return x+y;
// 	}
// };

// int add(int x, int y)	// 相加，传入参数以及返回值都是int
// {
// 	return x+y;
// }
// float add(float x, float y)	// 相加，传入参数以及返回值都是float
// {
// 	return x+y;
// }

// int main(int argc, char const *argv[])
// {
// 	int i = add(1, 2);
// 	float f = add(1.1f, 2.2f);
// 	Test test;
// 	int i1 = test.add(3, 4);
// 	float f1 = test.add(3.3f, 4.4f);

// 	cout << "i = " << i << endl;
// 	cout << "f = " << f << endl;
// 	cout << "i1 = " << i1 << endl;
// 	cout << "f1 = " << f1 << endl;
// 	return 0;
// }

/****************/
/* Interview 31?? */
/****************/
// 临时对象
// 真正的临时对象是看不见的，它不会出现在程序代码中。 大多数情况下，它会影响程序执行的效率，所以有时想避免临时对象的产生。
// (1) 参数按值传递
// (2) 返回值按值传递
// class Test
// {
// public:
// 	Test():num(0) {}
// 	Test(int number):num(number) {}
// 	~Test()
// 	{
// 		cout << "destructor: this = " << this << ", num = " << num << endl;
// 	}
// 	void print()
// 	{
// 		cout << "num = " << num << endl;
// 	}
// private:
// 	int num;
// };

// // void fun1(Test &test)
// void fun1(Test test)	// 参数按值传递
// {
// 	test.print();
// }

// Test fun2()
// {
// 	Test t(3);
// 	return t;	// 返回值按值传递
// }

// int main(int argc, char const *argv[])
// {
// 	Test t1(1);

// 	fun1(t1);		// 对象传入
// 	fun1(2);		// 整型数2传入
// 	t1 = fun2();

// 	return 0;
// }

/* Result */
// num = 1
// destructor: this = 0xbfdf9748, num = 1	// 
// num = 2
// destructor: this = 0xbfdf9744, num = 2	// 
// destructor: this = 0xbfdf9740, num = 3	// 
// destructor: this = 0xbfdf974c, num = 3	// 

/****************/
/* Interview 30 */
/****************/
// C++静态成员和临时对象
// class human
// {
// public:
// 	human()
// 	{
// 		++human_num;
// 	}
// 	static int human_num;
// 	~human()
// 	{
// 		--human_num;
// 		print();
// 	}
// 	human (const human &h)
// 	{
// 		++human_num;
// 	}
// 	void print()
// 	{
// 		cout << "human num is: " << human_num << endl;
// 	}
// };

// int human::human_num = 0;

// // 在f1()函数内首先会调用复制构造函数生成一个临时对象
// // f1()函数内调用复制构造函数，给main的对象h2初始化（复制临时对象）。
// // f1()函数返回后，临时对象发生析构，此时human的静态成员human_num为0

// human f1(human x)
// {
// 	x.print();
// 	return x;
// }

// int main(int argc, char const *argv[])
// {
// 	human h1;
// 	h1.print();
// 	human h2 = f1(h1);
// 	h2.print();

// 	return 0;
// }

/****************/
/* Interview 29?? */
/****************/
// class A
// {
// public:
// 	A()
// 	{
// 		cout << "This is A construction" << endl;
// 	}
// 	virtual ~A()
// 	{
// 		cout << "This is A destruction" << endl;
// 	}
// 	A(A &a)
// 	{
// 		cout << "This is A copy Construction" << endl;
// 	}
// 	A& operator =(const A &a)
// 	{
// 		cout << "This is an assignment function" << endl;
// 		return *this;
// 	}
// };

// A fun()
// {
// 	A a;
// 	return a;
// }

// int main() {
// 	A a;
// 	a = fun();
// }

/****************/
/* Interview 28 */
/****************/
// C++类的临时对象
// 构造函数、析构函数和赋值函数的编写方法
// class B
// {
// public:
// 	B()
// 	{
// 		cout << "default constructor" << endl;
// 	}
// 	~B()
// 	{
// 		cout << "destructed" << endl;
// 	}
// 	B(int i) : data(i)
// 	{
// 		cout << "constructed by parameter " << data << endl;
// 	}
// 	B(const B &b)
// 	{
// 		cout << "copy constructor" << endl;
// 		data = b.data;
// 	}
// private:
// 	int data;
// };

// B Play(B b)
// {
// 	return b;
// }

// int main(int argc, char const *argv[])
// {
// 	B t1 = Play(5);
// 	B t2 = Play(t1);

// 	B o1 = Play(9);
// 	B o2 = Play(10);

// 	return 0;
// }

/* Result */
// constructed by parameter 5	2
// copy constructor				
// destructed					
// copy constructor				
// copy constructor				
// destructed					
// constructed by parameter 9	
// copy constructor				
// destructed					
// constructed by parameter 10	
// copy constructor				
// destructed					
// destructed					
// destructed					
// destructed					
// destructed					

/****************/
/* Interview 27 */
/****************/
// 了解C++类各成员函数的关系
// 构造函数、析构函数、赋值函数的关系
// class A
// {
// public:
// 	A()
// 	{
// 		cout << "Default constructor" << endl;
// 	}
// 	~A()
// 	{
// 		cout << "Destructor" << endl;
// 		cout << num << endl;
// 	}
// 	A(const A &a)
// 	{
// 		cout << "Copy constructor" << endl;
// 	}
// 	void operator =(const A &a) {
// 		cout << "Overload operator" << endl;
// 	}
// 	void SetNum(int n) {
// 		num = n;
// 	}
// private:
// 	int num;
// };

// int main(int argc, char const *argv[])
// {
// 	A a1;			// 定义了一个对象a1，调用的是默认的构造函数
// 	A a2(a1);		// 用a1初始化一个对象a2，调用的是复制构造函数
// 	A a3 = a1;		// 同上
// 	A &a4 = a1;		// a4对a1的一个引用
// 	a1.SetNum(1);	
// 	a2.SetNum(2);	
// 	a3.SetNum(3);	
// 	a4.SetNum(4);	

// 	return 0;
// }

/****************/
/* Interview 26 */
/****************/
// String的构造函数、析构函数和赋值函数

// (1) 普通构造函数: 这里判断了传入的参数是否为NULL。
// 	如果是NULL，初始化一个字节的字符串（包括结束符'\0'）；
// 	如果不是，分配足够大小长度的堆内存来保存字符串。
// (2) 复制构造函数: 只是分配足够大小长度的堆内存来保存字符串。
// (3) 析构函数: 如果私有成员 m_String 不为 NULL，释放 m_String 指向的堆内存，
// 	并且为了避免产生野指针，将 m_String 赋为NULL。
// (4) 赋值函数: 首先判断当前对象与引用传递对象是否是同一个对象，
// 	如果是，不做操作，直接返回；
// 	否则，先释放当前对象的堆内存，然后分配足够大小长度的堆内存复制字符串。

// 已知类String的原型为：
// class String
// {
// public:
// 	String(const char *str = NULL);				// 普通构造函数
// 	String(const String &other);				// 复制构造函数
// 	~String(void);								// 析构函数
// 	String & operator =(const String &other); 	// 赋值函数
// private:
// 	char *m_String;	// 私有成员，保存字符串
// };

// String::~String(void)
// {
// 	cout << "Destructing" << endl;
// 	if (m_String != NULL)	// 如果 m_String 不为 NULL，释放堆内存
// 	{
// 		delete[] m_String;
// 		m_String = NULL;	// 释放后置为 NULL
// 	}
// }

// String::String(const char *str)
// {
// 	cout << "constructing" << endl;
// 	if (str == NULL)			// 如果str为NULL，存空字符串" "
// 	{
// 		m_String = new char[1];	// 分配一个字节
// 		*m_String = '\0';		// 将值赋值为字符串结束符
// 	}
// 	else
// 	{
// 		m_String = new char[strlen(str) + 1];	// 分配空间容纳str内容
// 		strcpy(m_String, str);					// 复制str到私有成员
// 		cout << m_String << endl;
// 	}
// }

// String::String(const String &other)
// {
// 	cout << "constructing Copy" << endl;
// 	m_String = new char[strlen(other.m_String) + 1];	// 分配空间容纳str内容
// 	strcpy(m_String, other.m_String);					// 复制str到私有成员
// 	cout << m_String << endl;
// }

// String & String::operator = (const String &other)
// {
// 	cout << "Operate = Function" << endl;
// 	if (this == &other) // 如果对象与other是同一个对象，直接返回本身
// 	{
// 		return *this;
// 	}
// 	delete[] m_String;	// 释放堆内存
// 	m_String = new char[strlen(other.m_String) + 1];
// 	strcpy(m_String, other.m_String);
// 	cout << m_String << endl;
// 	return *this;
// }

// int main()
// {
// 	String a("hello"); 	// 调用普通构造函数
// 	String b("world"); 	// 调用复制构造函数
// 	String c(a); 		// 调用析构函数
// 	c = b; 				// 调用赋值函数

// 	return 0;
// }


/****************/
/* Interview 25 */
/****************/
// 复制构造函数与赋值函数有什么区别
// (1) 复制构造是一个对象来初始化一块内存区域，这块内存就是新对象的内存区。
	// class A;
	// A a;
	// A b=a;	// 复制构造函数调用
	// A b(a);	// 复制构造函数调用
	// // 赋值函数是对于一个已经被初始化的对象来进行operator=操作。
	// class A;
	// A a;
	// A b;
	// b = a; // 赋值函数调用

// (2) 一般来说是在数据成员包含指针对象的时候，应付两种不同的处理需求：
	// 一种是复制指针对象，
	// 一种是引用指针对象。
	// 复制构造函数在大多数情况下是复制，赋值函数则是引用对象。

// (3) 实现不一样。
	// 复制构造函数首先是一个构造函数，它调用的时候是通过参数传进来的那个对象初始化产生一个对象。
	// 赋值函数则是把一个对象赋值给一个原有的对象。
	// 所以，若原来的对象有内存分配，要先把内存释放掉，而且要检查两个对象是否为同一个对象。若是，则不需要做任何操作。

/****************/
/* Interview 24 */
/****************/
// 写一个继承类的复制函数
// Q: 假如父类有似有成员，并且这些私有成员必须在调用派生类的复制构造函数时被初始化，在这种情况下又该怎么做呢？
// A: 编写继承类的复制函数有一个原则：使用父类的复制构造函数
// class Base
// {
// public:
// 	Base():i(0) // 默认普通构造函数
// 	{
// 		cout << "Base()" << endl;
// 	}
// 	Base(int n):i(n) // 普通构造函数
// 	{
// 		cout << "Base(int)" << endl;
// 	}
// 	Base(const Base &b):i(b.i) // 复制构造函数
// 	{
// 		cout << "Base(base&)" << endl;
// 	}
// private:
// 	int i; // 私有成员
// };

// class Derived : public Base
// {
// public:
// 	Derived():Base(0), j(0) // 默认普通构造函数
// 	{
// 		cout << "Derived()" << endl;
// 	}
// 	Derived(int m, int n):Base(m), j(n) // 普通构造函数
// 	{
// 		cout << "Derived(int)" << endl;
// 	}
// 	Derived(Derived &obj) : Base(obj), j(obj.j) // Derived类复制构造函数 调用了Base的复制构造函数
// 	{
// 		cout << "Derived(Derived&)" << endl;
// 	}
// private:
// 	int j;
// };

// int main(int argc, char const *argv[])
// {
// 	Base b(1);
// 	Derived obj(2, 3);
// 	cout << "---------" << endl;
// 	Derived d(obj); // 调用Derived的复制构造函数
// 	cout << "---------" << endl;

// 	return 0;
// }

/****************/
/* Interview 23 */
/****************/
// 编译器与默认复制构造函数
// 如果用户没有自定义复制构造函数，并且代码中用到了复制构造函数。那么编译器就会生成默认的复制构造函数。
// 若用户定义了，那么编译器则不再生成。

// 如果用户定义了一个构造函数，且不是复制构造函数，而此时在代码中用到了复制构造函数，那么编译器也会生成默认的复制构造函数。
// 如果没有使用，则编译器就不会生成默认的复制构造函数。

/****************/
/* Interview 22 */
/****************/
// 深复制、浅复制
// 复制构造函数，由编译器用来完成一些基于同一类的其他对象的构件及初始化。
// 如果在类中没有显式地声明一个复制构造函数，那么，编译器会私下里制定一个函数来进行对象之间的位复制（bitwise copy）。
// 这个隐含的复制构造函数简单地关联了所有的类成员。
// 3种对象需要复制的情况。复制构造函数将会被调用。

// (1) 一个对象以值传递的方式传入函数体
// (2) 一个对象以值传递的方式从函数返回
// (3) 一个对象需要通<过另外一个对象进行初始化。

// class Test
// {
// public:
// 	int a;
// 	Test(int x)
// 	{
// 		a = x;
// 	}
// 	Test(Test &test) // 复制构造函数
// 	{
// 		cout << "copy construct" << endl;
// 		a = test.a;
// 	}
// };

// void fun1(Test test) // (1) 值传递传入函数体
// {
// 	cout << "fun1()..." << endl;
// }

// Test fun2() // (2) 值传递从函数体返回
// {
// 	Test t(2); // 临时对象
// 	cout << "fun2()..." << endl;
// 	return t;
// }

// int main()
// {
// 	Test t1(1);
// 	Test t2 = t1; // (3) 用t1对t2做初始化
// 	cout << "before fun1()..." << endl;
// 	fun1(t1);

// 	// Test t3 = fun2(); // error: no matching function for call to ‘Test::Test(Test)’
// 	cout << "after fun2()..." << endl;
// 	return 0;
// }

// 浅复制是指让新旧两个对象指向同一个外部的内容。 
// 深复制是指为新对象制作了外部对象的独立复制。

// class Test
// {
// public:
// 	char *buf;
// 	Test(void)	// 不带参数的构造函数
// 	{
// 		buf = NULL;
// 	}
// 	Test(const char* str)	// 带参数的构造函数
// 	{
// 		buf = new char[strlen(str) + 1]; // 分配堆内存
// 		strcpy(buf, str);	// 复制字符串
// 	}
// 	// 此时buf又分配了一块堆内存来保存 字符串，两个buf分别指向了不同的堆内存，析构时就不会发生程序崩溃。
// 	Test(Test &test)
// 	{
// 		buf = new char[strlen(test.buf) + 1];
// 		strcpy(buf, test.buf);
// 	}
// 	~Test()
// 	{
// 		if (buf != NULL)
// 		{
// 			delete buf;	// 释放buf指向的堆内存
// 			buf = NULL;
// 		}
// 	}
// };

// int main(int argc, char const *argv[])
// {
// 	Test t1("hello");
// 	Test t2 = t1;	// 调用默认的复制构造函数
// 	// 默认复制构造函数只是将两个对象的指针做赋值运算，它们指向的是同一个地址。
// 	// 当产生两次析构时，释放同一块堆内存时发生崩溃

// 	cout << "(t1.buf == t2.buf) ? " << (t1.buf == t2.buf ? "yes" : "no") << endl;
// 	return 0;
// }

/****************/
/* Interview 21 */
/****************/
// 析构函数的执行顺序
// class A
// {
// public:
// 	A(int aa) {a = aa;}
// 	~A()
// 	{
// 		cout << "Destructor A!" << a << endl;
// 	}

// private:
// 	int a;
// };

// class B : public A
// {
// public:
// 	B(int aa = 0, int bb = 0) : A(aa) {b = bb;}
// 	~B() {cout << "Destructor B!" << b << endl;}
// private:
// 	int b;
// };

// // 析构函数的执行顺序与构造函数的执行顺序相反。
// int main(int argc, char const *argv[])
// {
// 	B obj1(5), obj2(6, 7);
// 	return 0;
// }

/****************/
/* Interview 20 */
/****************/
// C++ 虚析构函数的作用
// class Base
// {
// public:
// 	Base() {};
// 	// ~Base() // 析构函数不被调用的话就会造成内存泄露。
// 	virtual ~Base()
// 	{
// 		cout << "Output from the destructor of class Base!" << endl;
// 	};
// 	virtual void DoSomething()
// 	{
// 		cout << "Do something in class Base!" << endl;
// 	}
// };
// class Derived : public Base
// {
// public:
// 	Derived() {};
// 	~Derived()
// 	{
// 		cout << "Output from the destructor of class Derived!" << endl;
// 	};
// 	void DoSomething()
// 	{
// 		cout << "Do something in class Derived!" << endl;
// 	};
// };

// int main()
// {
// 	Derived *pTest1 = new Derived(); // Derived class pointer
// 	pTest1 -> DoSomething();
// 	delete pTest1;

// 	cout << endl;

// 	Base *pTest2 = new Derived(); // Base class pointer
// 	pTest2 -> DoSomething();
// 	delete pTest2;

// 	return 0;
// }

/****************/
/* Interview 19 */
/****************/

// class Number
// {
// public:
// 	string type;
// 	Number() : type("void") {}
// 	explicit Number(short) : type("short") {} // 不能隐式调用
// 	Number(int) : type("int") {} // 42 自动转换为int类型 构造函数造出一个临时对象
// };

// void Show(const Number& n) { cout << n.type; }

// int main()
// {
// 	short s = 42;
// 	Show(s); // 打印上一步临时对象的 type 成员，即“int”
// 	return 0;5
// }

/****************/
/* Interview 18 */
/****************/
// 构造函数explicit / 普通构造函数
// class Test1
// {
// public:
// 	Test1(int n) {num = n;}
// private:
// 	int num;
// };

// class Test2
// {
// public:
// 	explicit Test2(int n) {num = n;}
// private:
// 	int num;
// };

// int main(int argc, char const *argv[])
// {
// 	Test1 t1 = 12; // 隠式调用其构造函数，成功
// 	Test2 t2 = 12; // 不能隐式调用
// 	Test2 t3(12);  // 调用成功
// 	return 0;
// }

/****************/
/* Interview 17 */
/****************/
// struct CLS
// {
// 	int m_i;
// 	CLS(int i) : m_i(i) 
// 	{
// 		cout << "CLS(): this = " << this << endl;
// 	}
// 	CLS()
// 	{
// 		CLS(0); // 在栈上生成一个临时对象
// 		cout << "CLS(int): this = " << this << endl; // 构造函数互相调用引起栈溢出
// 	}
// };

// int main(int argc, char const *argv[])
// {
// 	CLS obj;
// 	cout << "&obj = " << &obj << endl;
// 	cout << obj.m_i << endl;
// 	return 0;
// }

/****************/
/* Interview 16 */
/****************/
// 关于重载构造函数的调用
// class Test
// {
// public:
// 	Test(){}
// 	Test(char *Name, int len = 0){} 
// 	Test(char *Name){}
// };
// int main(int argc, char const *argv[])
// {
// 	Test obj("Hello"); // 二议性
// 	return 0;
// }

/****************/
/* Interview 15 */
/****************/
// 构造函数可以被重载，因为构造函数可以有多个，且可以带参数。
// 析构函数不可以被重载，因为析构函数只能有一个，且不能带参数。

/****************/
/* Interview 14 */
/****************/
// C++空类默认会产生哪些类成员函数
// class Empty
// {
// public:
// 	Empty();							// 缺省构造函数
// 	Empty( const Empty& );				// 复制构造函数
// 	~Empty();							// 析构函数
// 	Empty& operator=( const Empty& );	// 赋值运算符 = 
// 	Empty* operator&();					// 取址运算符 &
// 	const Empty* operator&() const;		// 取址运算符 const
// };

/****************/
/* Interview 13 */
/****************/
// main函数执行前还会执行什么代码？
// class Test
// {
// public:
// 	Test()	// 构造函数
// 	{
// 		cout << "construct of Test" << endl;
// 	}
// };

// Test a; // 全局变量

// int main(int argc, char const *argv[])
// {
// 	cout << "main() start" << endl;
// 	Test b; // 局部变量
// 	return 0;
// }

/****************/
/* Interview 12 */
/****************/
// 对静态数据成员的正确描述
// 下面对静态数据成员的描述中，正确的是：
// 静态数据成员可以在类体内进行初始化 		// F 静态数据成员必须在类外面初始化，以示与普通数据成员的区别。
// 静态数据成员不可以被类的对象调用   		// F
// 静态数据成员不能接受private控制符的作用	// T
// 静态数据成员可以直接用类名调用 			// T


/****************/
/* Interview 11 */
/****************/
// 静态成员的错误使用
// class test
// {
// public:
// 	static int i;
// 	int j;
// 	// test(int a) : i(1), j(a) {} // ‘int test::i’ is a static data member; it can only be initialized at its definition
// 	test(int a) : j(a) {}
// 	void func1();
// 	static void func2();
// };
// int test::i = 1;

// void test::func1() {
// 	cout << i << ", " << j << endl;
// }

// void test::func2() {
// 	cout << i << /*", " << j <<*/ endl; // invalid use of member ‘test::j’ in static member function from this location
// }

// int main(int argc, char const *argv[])
// {
// 	test t(2);
// 	t.func1();
// 	t.func2();

// 	return 0;
// }

/****************/
/* Interview 10 */
/****************/
// When USE: initialization list , NOT assignment
// 当类中含有const、reference成员变量和基类的构造函数时都需要初始化列表
// class A
// {
// private:
// 	int a;
// public:
// 	A(){}
// 	A(int x) : a(x) {}
// 	void printA()
// 	{
// 		cout << "a = " << a << endl;
// 	}
// };

// class B : public A
// {
// private:
// 	int b;
// public:
// 	B(int x, int y) : A(x) // 需要初始化b和父类的a
// 	{
// 		// a = x;	// a无法在子类中被访问，编译错误。
// 		// A(x);	// 调用方式错误。
// 		b = y;
// 	}
// 	void printB()
// 	{
// 		cout << "b = " << b << endl;
// 	}
// };

// int main()
// {
// 	B b(2, 3);
// 	b.printA();
// 	b.printB();

// 	return 0;
// }

/***************/
/* Interview 9 */
/***************/
// 静态数据成员的优势
// 主要有以下两种优势：
// 1. 静态数据成员没有进入程序的全局命名空间，因此不存在程序中其他全局命名冲突的可能性。
// 2. 使用静态数据成员可以隐藏信息。因为静态成员可以是private成员，而全局对象不能。

/***************/
/* Interview 8 */
/***************/
// class Myclass
// {
// public:
// 	Myclass(int a, int b, int c);
// 	void GetNumber();
// 	void GetSum();
// private:
// 	int A;
// 	int B;
// 	int C;
// 	int Num;
// 	static int Sum;
// };

// int Myclass::Sum = 0;

// Myclass::Myclass(int a, int b, int c)
// {
// 	A = a;
// 	B = b;
// 	C = c;
// 	Num = A + B + C;
// 	Sum = A + B + C;
// }
// void Myclass::GetNumber()
// {
// 	cout << "Number = " << Num << endl;
// }

// void Myclass::GetSum()
// {
// 	cout << "Sum = " << Sum << endl;
// }

// int main()
// {
// 	Myclass M(3, 7, 10), N(14, 9, 11);

// 	M.GetNumber();	// 20
// 	N.GetNumber();	// 34
// 	M.GetSum();		// 34
// 	N.GetSum();		// 34

// 	return 0;
// }

/***************/
/* Interview 7 */
/***************/
// class Obj
// {
// public:
// 	Obj(int k) : j(k), i(j)
// 	{
// 	}
// 	void print(void)
// 	{
// 		cout << i << endl << j << endl;
// 	}
// private:
// 	int i;
// 	int j;
// };

// int main(int argc, char const *argv[])
// {
// 	Obj obj(2); // random
// 	obj.print(); // 2

// 	return 0;
// }

/***************/
/* Interview 6 */
/***************/
// // C++类成员的访问
// #ifndef public
// #define public private // (1) 把public宏定义为private。
// #endif

// class Animal
// {
// public:
// 	void MakeNoise(); // (2) MakeNoise() is actually private.
// };

// int main(int argc, char const *argv[])
// {
// 	Animal animal;
// 	animal.MakeNoise(); // (3) Compile Error: ‘void Animal::MakeNoise()’ is private
// 	return 0;
// }

/***************/
/* Interview 5 */
/***************/
// C++类对象的声明
// struct Test
// {
// 	Test(int) {}
// 	Test() {}
// 	void fun(){}
// };

// void main(void)
// {
// 	Test a(1);
// 	a.fun();
// 	Test b;
// 	// Test b(); // "()"
// 	b.fun();
// }

/***************/
/* Interview 4 */
/***************/
// Difference between class / struct
// C: struct / C++: class

// struct 中只能定义成员变量，不能定义成员函数。
// struct Point
// {
// 	int x;
// 	int y;
// 	void print()
// 	{
// 		printf("Point print\n"); // Compile Error.
// 	}
// };

// class CPoint
// {
// private:
// 	int x;
// 	int y;
// 	void print()
// 	{
// 		cout << "CPoint: (" << x << ", " << y << ")" << endl;
// 	}
// public:
// 	CPoint(int x, int y)
// 	{
// 		this -> x = x;
// 		this -> y = y;
// 	}
// 	void print1()
// 	{
// 		cout << "CPoint: (" << x << ", " << y << ")" << endl;
// 	}
// };

// struct SPoint
// {
// 	int x;        
// 	int y;
// 	void print()
// 	{
// 		cout << "SPoint: (" << x << ", " << y << ")" << endl;
// 	}
// 	SPoint(int x, int y)
// 	{
// 		this->x = x;
// 		this->y = y;
// 	}
// private:
// 	void print1()
// 	{
// 		cout << "SPoint: (" << x << ", " << y << ")" << endl;
// 	}
// };

// class CBase
// {
// public:
// 	void print()
// 	{
// 		cout << "CBase: print()..." << endl;
// 	}
// };

// class CDerived1 : CBase // default private
// {
// };

// class CDerived2 : public CBase
// {
// };

// struct SDerived1 : CBase
// {
// };

// struct SDerived2 : private CBase // default public
// {
// };

// int main(int argc, char const *argv[])
// {
// 	CPoint cpt(1, 2);
// 	SPoint spt(3, 4);

// 	// cout << cpt.x << " " << cpt.y << endl; // private
// 	// cpt.print();	// private
// 	cpt.print1(); // public

// 	cout << spt.x << " " << spt.y << endl; // member
// 	spt.print(); // member
// 	// spt.print1(); // private

// 	CDerived1 cd1;
// 	CDerived2 cd2;
// 	SDerived1 sd1;
// 	SDerived2 sd2;

// 	// cd1.print(); // Compile Error
// 	cd2.print();
// 	sd1.print();
// 	// sd2.print(); // Compile Error

// 	return 0;
// }

// struct只是作为一种复杂数据类型的定义，不能用于面向对象编程。
// 对于成员访问权限以及继承方式，class中默认的是private的，而struct中则是public的。class还可以用于表示模板类型，struct则不行。

/***************/
/* Interview 3 */
/***************/
// 选择题——C++与C语言相比的改进
// 在求解问题的方法上进行的最大改进是什么？ // B
// A. 面向对象
// B. 面向过程
// C. 安全性
// D. 复用性

/***************/
/* Interview 2 */
/***************/
// 判断题——类的基本概念
// Which is incorrect about the class?
// A. A class is a blueprint to objects. // T
// B. We use the keyword class to create a class construct. // T
// C. Once a class is declared, the class name becomes a type name and can be use to eclare variables. // T
// D. The class is same as the struct, and there are no difference between class and struct. // F

/***************/
/* Interview 1 */
/***************/
// 类（class）：由特殊到一般的归纳法和由一般到特殊的演绎法。
// 对象（Object）：类的实例。对象的内部状态称为属性，运动规律称为方法和事件。
// 消息（message）：指对象间互相联系和相互作用的方式。由5部分组成：
// 1. 发送消息的对象，
// 2. 接收消息的对象，
// 3. 消息传递办法，
// 4. 消息内容（参数），
// 5. 反馈。
// 类的特性：抽象、继承、封装、重载、多态。