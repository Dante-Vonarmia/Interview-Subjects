#include "iostream"
#include "stdio.h"
#include "stdlib.h"
using namespace std;

/****************/
/* Interview 25 */
/****************/
// 在以下情况不宜使用内联。
// 如果函数体内的代码比较长，使用内联将导致内存消耗代价较高。
// 如果函数体内出现循环，执行函数体开销比调用函数体大。
// 类的构造函数和析构函数有可能会执行基类或成员的构造函数或析构函数。

/****************/
/* Interview 24 */
/****************/
// class A
// {
// private:
// 	int nTest;
// public:
// 	int readTest() {
// 		return nTest;
// 	}
// 	void setTest(int i);
// };
// inline void A::setTest(int i) {
// 	nTest = i;
// }

/****************/
/* Interview 22 & 23 */
/****************/
// 引入内联函数的主要目的是，用它替代C语言中表达式形式的宏定义来解决程序中函数调用的问题。
// 没有调用开销，执行效率高。
// 调用内联函数时，首先会检查其参数类型。消除隐患和局限性。像调用普通函数一样操作。
// 可作为类的成员函数，可以用在保护成员和私有成员。

/****************/
/* Interview 20 & 21 */
/****************/
// #pragma pack(2) // 编译器的对齐方式

// union u {
// 	double a;
// 	int b;
// };

// union u2 {
// 	char a[13];
// 	int b;
// };

// union u3 {
// 	char a[13];
// 	char b;
// };

// int main() {
// 	cout << sizeof(u) << endl;
// 	cout << sizeof(u2) << endl;
// 	cout << sizeof(u3) << endl;

// 	return 0;
// }

/****************/
/* Interview 19 */
/****************/
// #include "string.h"
// void UpperCase(char str[]) {
// 	int test = sizeof(str);
// 	int test2 = sizeof(str[0]);

// 	// for (size_t i = 0; i < sizeof(str)/sizeof(str[0]); ++i)
// 	for (size_t i = 0; i < strlen(str); ++i)
// 	{
// 		if ('a' <= str[i] && str[i] <= 'z')
// 		{
// 			str[i] -= ('a' -  'A');
// 		}
// 	}
// }
// int main(int argc, char const *argv[])
// {
// 	char str[] = "aBcDe";
// 	// cout << "The length of str is " << sizeof(str)/sizeof(str[0]) << endl;
// 	cout << "The length of str is " << strlen(str) << endl;
// 	UpperCase(str);
// 	cout << str << endl;
// 	return 0;
// }

/****************/
/* Interview 18 */
/****************/
// void* malloc(size_t size);
// size_t fread(void* ptr, size_t size, size_t nmemb, FILE* stream);

// void* memset(void* s, int c, sizeof(s));

/****************/
/* Interview 17 */
/****************/
// // sizeof: operator (size_t) typedef: unsignedint arguement: any type
// // strlen: functionary arguement: char* endwith: '\0'
// int main(int argc, char const *argv[])
// {
// 	char str[20] = "0123456789";
// 	int a = strlen(str); // 10
// 	int b = sizeof(str); // 20

// 	char* ss = "0123456789";
// 	int a = sizeof(ss); // 4
// 	int b = strlen(ss); // 10
// 	return 0;
// }

/****************/
/* Interview 16 */
/****************/
// class A{}; // char 1
// class B{}; // char 1
// class C:public A, public B {}; // char 1
// class D:virtual public A {}; // pointer 4
// class E:virtual public A, virtual public B {};  // pointers 8
// class F {
// public:
// 	int a; // int 4
// 	static int b; // global
// };

// int F::b = 10;

// int main(int argc, char const *argv[])
// {
// 	cout << sizeof(A) << endl; // char 1
// 	cout << sizeof(B) << endl; // char 1
// 	cout << sizeof(C) << endl; // char 1
// 	cout << sizeof(D) << endl; // pointer 4
// 	cout << sizeof(E) << endl; // pointers 8
// 	cout << sizeof(F) << endl; // int 4
// 	return 0;

/****************/
/* Interview 15 */
/****************/
// class Base
// {
// public:
// 	Base(int x) : a(x){} // 4
// 	~Base(){}

// 	void print() {
// 		cout << "base" << endl;
// 	}
// private:
// 	int a;
// };

// class Derived : public Base
// {
// public:
// 	Derived(int x) : Base(x-1), b(x){} // 8
// 	~Derived(){}

// 	void print() {
// 		cout << "derived" << endl;
// 	}
// private:
// 	int b;
// };
// class A
// {
// public:
// 	A(int x) : a(x){} // 4
// 	~A(){}
// 	virtual void print() {  // 4
// 		cout << "A" << endl;
// 	}
// private:
// 	int a;
// };
// class B : public A
// {
// public:
// 	B(int x) : A(x-1), b(x){} // 8
// 	~B(){}

// 	virtual void print() { // 4
// 		cout << "B" << endl;
// 	}
// private:
// 	int b;
// };
// int main(int argc, char const *argv[])
// {
// 	Base obj1(1);
// 	cout << "size of Base obj is " << sizeof(obj1) << endl; // 4
// 	Derived obj2(2);
// 	cout << "size of Derived obj is " << sizeof(obj2) << endl; // 8

// 	A a(1);
// 	cout << "size of A obj is " << sizeof(a) << endl; // 8
// 	B b(2);
// 	cout << "size of B obj is " << sizeof(b) << endl; // 12
// 	return 0;
// }

/****************/
/* Interview 14 */
/****************/
// class A
// {
// public:
// 	int i;
// };

// class B
// {
// public:
// 	char ch;
// };

// class C
// {
// public:
// 	int i;
// 	short j;
// };

// class D
// {
// public:
// 	int i;
// 	short j;
// 	char ch;
// };

// class E
// {
// public:
// 	int i;
// 	int j;
// 	short k;
// 	char ch;
// 	char chr;
// };

// class F
// {
// public:
// 	int i;
// 	int j;
// 	int l;
// 	short k;
// 	char ch;
// 	char chr;
// };

// int main(int argc, char const *argv[])
// {
// 	cout << "sizeof(int) = " << sizeof(int) << endl; // 4
// 	cout << "sizeof(short) = " << sizeof(short) << endl; // 2
// 	cout << "sizeof(char) = " << sizeof(char) << endl; // 1
// 	cout << "sizeof(A) = " << sizeof(A) << endl; // 4
// 	cout << "sizeof(B) = " << sizeof(B) << endl; // 1
// 	cout << "sizeof(C) = " << sizeof(C) << endl; // 4 + 1 + 3(autocomplete) = 8
// 	cout << "sizeof(D) = " << sizeof(D) << endl; // 4 + 2 + 1 + 1(autocomplete) = 8
// 	cout << "sizeof(E) = " << sizeof(E) << endl; // 4 + 4 + 2 + 1 + 1 = 12
// 	cout << "sizeof(F) = " << sizeof(F) << endl; // 4 + 4 + 4 + 2 + 1 + 1 = 16
// 	return 0;
// }

/****************/
/* Interview 13 */
/****************/
// char str[] = "Hello";
// char *p = str;
// int n = 10;
// sizeof(str) = ____; // 6
// sizeof( p ) = ____; // 4
// sizeof( n ) = ____; // 4
// void Func(char str[100])
// {
// 	sizeof(str) = ____; // 4
// }
// void *p = malloc(100);
// sizeof(p) = ____; // 4

/****************/
/* Interview 12 */
/****************/
// class Widget
// {
// public:
// 	Widget() {
// 		count++;
// 	}
// 	~Widget() {
// 		--count;
// 	}

// 	static int num() {
// 		return count;
// 	}
// private:
// 	static int count;
// };
// int Widget::count = 0;
// int main()
// {
// 	Widget x, y;
// 	cout << "The Num is " << Widget::num() << endl;
// 	if (Widget::num() > 1)
// 	{
// 		Widget x, y, z;
// 		cout << "The Num is " << Widget::num() << endl;
// 	}
// 	Widget z;
// 	cout << "The Num is " << Widget::num() << endl;
// 	return 0;
// }

/****************/
/* Interview 11 */
/****************/
// static 全局变量与普通全局变量的区别是，static全局变量只初始化一次，防止在其他文件单元中被引用。
// static 局部变量和普通变量的区别是，static局部变量只被初始化一次，下一次依据上一次结果值。
// static 函数与普通函数的区别，static函数在内存中只有一份，普通函数在每个被调用中维持一份复制品。

/****************/
/* Interview 10 */
/****************/
// 在函数体，一个被声明为静态的变量在这一函数被调用的过程中维持其值不变。
// 在模块内(但在函数体外)，一个被声明为静态的变量可以被模块内所有函数访问，但不能被模块外其他函数访问。它是一个本地的全局变量。
// 在模块内，一个静态函数只可被该模块内的其他函数调用。该静态函数被限制在声明它的模块的本地范围内使用。

/***************/
/* Interview 9 */
/***************/
// const用于定义常量：const定义的常量编译器可以对其进行数据静态类型安全检查

// const修饰函数形式参数；当输入参数为用户自定义类型和抽象数据类型时，应该将“值传递”改为“cosnt &传递”，可以提高效率。
// void fun(A a);
// void fun(A const &a);

// const修饰函数的返回值：如给“指针传递”的函数返回值加const，则返回值不能被直接修改，且该返回值只能被赋值给加const修饰的同类型指针。
// const char *Getchar(void) {};
// char *ch = Getchar(); // error
// const char *ch = Getchar(); // correct

// const修饰类的成员函数(函数定义体)：任何不会修改数据成员的函数都应用const修饰，
// 这样，当不小心修改了数据成员或调用了非const成员函数时，编译器都会报错。
// int GetCount(void) const;

/***************/
/* Interview 8 */
/***************/
// difference between const & #define

/***************/
/* Interview 7 */ 
/***************/
// int main()
// {
// 	const int x = 1;
// 	int b = 10;
// 	int c = 20;

// 	const int* a1 = &b;
// 	int* const a2 = &b;
// 	const int* const a3 = &b;

// 	x = 2;

// 	a1 = &c;
// 	*a1 = 1;

// 	a2 = &c;
// 	*a2 = 1;

// 	a3 = &c;
// 	*a3 = 1;
// 	return 0;
// }

/***************/
/* Interview 6 */ 
/***************/
// #define ARR_SIZE(a) (sizeof((a)) / sizeof((a[0])))
// int array[10];// int size 4

/***************/
/* Interview 5 */ 
/***************/
// #define WORD_LO(xxx) ((byte) ((word)(xxx) & 255))
// #define WORD_HI(xxx) ((byte) ((word)(xxx) >> 8))

/***************/
/* Interview 4 */ 
/***************/
// #define STR(s) #s
// #define CONS(a, b) (int)(a##e##b)
// int main(int argc, char const *argv[])
// {
// 	printf(STR(vck));
// 	printf("\n");
// 	printf("%d\n", CONS(2, 3));
// 	return 0;
// }

/***************/
/* Interview 3 */ 
/***************/
// #define SQR(x) (x*x)
// int main(int argc, char const *argv[])
// {
// 	int a, b = 3;
// 	a = SQR(b + 2);
// 	printf("a = %d\n", a);
// 	return 0;
// }

/***************/
/* Interview 2 */ 
/***************/
// #define MAX(x, y) ( ((x) > (y)) ? (x) : (y) )
// #define MIN(x, y) ( ((x) < (y)) ? (x) : (y) )

/***************/
/* Interview 1 */ 
/***************/
// #define DEBUG
// int main(int argc, char const *argv[])
// {
// 	int i = 0;
// 	char c;

// 	while(1) {
// 		i++;
// 		c = getchar();
// 		if (c != '\n')
// 		{
// 			getchar();
// 		}
// 		if (c == 'q' || c == 'Q') {
// #ifdef DEBUG
// 			cout << "We got: " << c << ", about to exit." << endl;
// #endif
// 		}
// 		else {
// 			cout << "i = " << i << endl;
// 		}
// #ifdef DEBUG
// 			cout << ", we got: " << c << endl;
// #endif
// 	}
// 	return 0;
// }