#include "iostream"
#include "assert.h"
using namespace std;

/***********/
/* Example */
/***********/
// 类模板、函数模板和模板特化。
// #include <cstring>
// #include <typeinfo>

// class A
// {
// public:
// 	A(int x, int y) : m_x(x), m_y(y){}

// 	int compare(void)
// 	{
// 		cout << "Type of m_x is " << typeid(m_x).name() << endl;
// 		cout << "Type of m_y is " << typeid(m_y).name() << endl;

// 		if (m_x < m_y)
// 		{
// 			return -1;
// 		}
// 		if (m_x > m_y)
// 		{
// 			return 1;
// 		}
// 		else
// 		{
// 			return 0;
// 		}
// 	}
// private:
// 	int m_x;
// 	int m_y;
// };

// class B
// {
// public:
// 	B(double x, double y) : m_x(x), m_y(y){}

// 	double compare(void)
// 	{
// 		cout << "Type of m_x is " << typeid(m_x).name() << endl;
// 		cout << "Type of m_y is " << typeid(m_y).name() << endl;

// 		if (m_x < m_y)
// 		{
// 			return -1;
// 		}
// 		if (m_x > m_y)
// 		{
// 			return 1;
// 		}
// 		else
// 		{
// 			return 0;
// 		}
// 	}
// private:
// 	double m_x;
// 	double m_y;
// };

// class C
// {
// public:
// 	C(string x, string y) : m_x(x), m_y(y){}

// 	int compare(void)
// 	{
// 		cout << "Type of m_x is " << typeid(m_x).name() << endl;
// 		cout << "Type of m_y is " << typeid(m_y).name() << endl;

// 		if (m_x < m_y)
// 		{
// 			return -1;
// 		}
// 		if (m_x > m_y)
// 		{
// 			return 1;
// 		}
// 		else
// 		{
// 			return 0;
// 		}
// 	}
// private:
// 	string m_x;
// 	string m_y;
// };

// template<class T>
// class D
// {
// public:
// 	D(T x, T y): m_x(x), m_y(y) {}
// 	int compare(void)
// 	{
// 		cout << "Type of m_x is " << typeid(m_x).name() << endl;
// 		cout << "Type of m_y is " << typeid(m_y).name() << endl;

// 		if (m_x < m_y)
// 		{
// 			return -1;
// 		}
// 		if (m_x > m_y)
// 		{
// 			return 1;
// 		}
// 		else
// 		{
// 			return 0;
// 		}
// 	}
// private:
// 	T m_x;
// 	T m_y;
// };

// 针对 char* 的类模板成员函数特化
// template<>
// int D<char*>::compare (void)
// {
// 	cout << "Type of m_x is " << typeid(m_x).name() << endl;
// 	cout << "Type of m_y is " << typeid(m_y).name() << endl;

// 	if (strcmp (m_x, m_y) < 0)
// 	{
// 		return -1;
// 	}
// 	if (strcmp (m_x, m_y) > 0)
// 	{
// 		return 1;
// 	}
// 	return 0;
// }

// 函数模板
// template<class T>
// int compare (T x, T y)
// {
// 	cout << "Type of x is " << typeid(x).name() << endl;
// 	cout << "Type of y is " << typeid(y).name() << endl;

// 	if (x < y)
// 	{
// 		return -1;
// 	}
// 	if (x > y)
// 	{
// 		return 1;
// 	}
// 	return 0;
// }

// 针对 char* 的函数模板特化
// template<>
// int compare<char*> (char* x, char* y)
// {
// 	cout << "Type of x is " << typeid(x).name() << endl;
// 	cout << "Type of y is " << typeid(y).name() << endl;

// 	if (strcmp(x, y) < 0)
// 	{
// 		return -1;
// 	}

// 	if (strcmp(x, y) > 0)
// 	{
// 		return 1;
// 	}
// 	return 0;
// }

// int main(int argc, char const *argv[])
// {
// 	Without Templates
// 	A a(10, 20);
// 	cout << "A::compare() return " << a.compare() << endl;

// 	B b(0.1, 0.2);
// 	cout << "B::compare() return " << b.compare() << endl;

// 	C c("courage", "excellent");
// 	cout << "C::compare() return " << c.compare() << endl;

// 	cout << "----------------------" << endl;

// 	With Class Templates
// 	D<int> d1(10, 20);
// 	cout << "D<int>::compare() return " << d1.compare() << endl;

// 	D<double> d2(0.1, 0.2);
// 	cout << "D<double>::compare() return " << d2.compare() << endl;

// 	D<string> d3("c", "e");
// 	cout << "D<string>::compare() return " << d3.compare() << endl;

// 	cout << "----------------------" << endl;
	
// 	类模板及其成员函数的特化
// 	char sz1[] = "courage";
// 	char sz2[] = "excellent";
// 	D<char*> d4(sz1, sz2);
// 	cout << "D<char*>::compare() return " << d4.compare() << endl;

// 	cout << "----------------------" << endl;

// 	函数模板及其特化
// 	cout << "compare<int>() return" << compare<int>(10, 20) << endl;
// 	cout << "compare<double>() return" << compare<double>(0.1, 0.2) << endl;
// 	cout << "compare<string>() return" << compare<string>("courage", "excellent") << endl;
// 	cout << "compare<char*>() return" << compare<char*>(sz1, sz2) << endl;

// 	cout << "----------------------" << endl;
	
// 	函数模板的隐式推断
// 	cout << "compare() return " << compare(10, 20) << endl;
// 	cout << "compare() return " << compare(0.1, 0.2) << endl;
// 	cout << "compare() return " << compare("courage", "excellent") << endl;
// 	cout << "compare() return " << compare(sz1,sz2) << endl;

// 	return 0;
// }

/***************/
/* Interview 9 ?? */
/***************/
// 设计一个公共的class，通过它的接口可以对任何类型的数组排序。
// 冒泡排序
// template <typename T>
// class Test
// {
// public:
// 	static void Sort(T *array, int len, bool(*Compare)(T& a, T& b)) {
// 		T temp;
// 		assert(len >= 1);
// 		for (int i = 0; i < len - 1; ++i)
// 		{
// 			for (int j = len - 1; j > i; --j)
// 			{
// 				if (Compare(array[j], array[j - 1]))
// 				{
// 					// array[j-1] ^= array[j];
// 					// array[j] ^= array[j-1];
// 					// array[j-1] ^= array[j];
// 					temp = array[j];
// 					array[j] = array[j-1];
// 					array[j-1] = array[j];
// 				}
// 			}
// 		}
// 	}
// };

// template <typename T>
// bool ascend(T &a, T &b)
// {
// 	return a < b ? true : false; // 升序
// }

// template <typename T>
// bool descend(T &a, T &b)
// {
// 	return a > b ? true : false; // 降序
// }

// template <typename T>
// class MyRect
// {
// public:
// 	MyRect():length(0), width(0) {}
// 	MyRect(T len, T wid):length(len), width(wid) {}
// 	T Area() {
// 		return length * width; // 返回面积
// 	}
// private:
// 	T length;
// 	T width;
// };

// template <typename T>
// bool operator >(MyRect<T> &rect1, MyRect<T> &rect2)
// {
// 	return rect1.Area() > rect2.Area() ? true : false;
// }


// template <typename T>
// bool operator < (MyRect<T> &rect1, MyRect<T> &rect2)
// {
// 	return rect1.Area() < rect2.Area() ? true : false;
// }

// int main(int argc, char const *argv[])
// {
// 	int int_array[10] = {4,3,7,8,2,1,9,5,6,10};
// 	float float_array[10] = {4.0f,3.0f,7.0f,8.0f,2.0f,1.0f,9.0f,5.0f,10.0f};
// 	// MyRect<int> rect_array[4] = {MyRect<int>{3,4},MyRect<int>(5,6),MyRect<int>(4,6),MyRect<int>(3,5)};

// 	Test<int>::Sort(int_array, 10, descend<int>);
// 	Test<int>::Sort(int_array, 10, ascend<int>);

// 	// Test< MyRect<int> >::Sort(rect_array, 4, descend<int>);
// 	// Test< MyRect<int> >::Sort(rect_array, 4, ascend<int>);

// 	return 0;
// }

/***************/
/* Interview 8 */
/***************/
// 使用类模板对类进行泛型化
// Give an example of implementing a Stack in the template way(only template class declaration without detail definition and realization).
// template <class T>
// class Stack
// {
// public:
// 	Stack(int len = 10);	// 构造函数，默认数组大小为 10
// 	~Stack() {				// 析构函数，释放数组内存
// 		delete[] stackPtr;
// 	}
// 	int push(const T&);
// 	int pop(T&);
// 	int isEmpty()const {
// 		return top == -1;	// 判断栈空
// 	}
// 	int isFull() const {	// 判断栈满
// 		return top == size - 1;
// 	}

// private:
// 	int size;		// 栈中的元素个数
// 	int top;		// 栈顶元素位置
// 	T* stackPtr;	// 保存动态数组指针，类型为 T*
// };

/***************/
/* Interview 7 */
/***************/
// 使用函数模板对普通函数进行泛型化
// Q: Below is usual way we find one element in an array.
// const int *find1(const int* array, int n, int x)
// {
// 	const int* p = array;
// 	for(int i = 0; i < n; i++)
// 	{
// 		if (*p == x)
// 		{
// 			return p;
// 		}
// 		++p;
// 	}
// 	return 0;
// }

// In this case we have to bear the knowledge of value type "int", the size of array, even the existence of an array.
// template <typename T>
// const T *find1(const T*array, int n, T x)
// {
// 	const T* p = array;
// 	for(int i = 0; i < n; i++)
// 	{
// 		if (*p == x)
// 		{
// 			return p;
// 		}
// 		++p;
// 	}
// 	return 0;
// }

// int main(int argc, char const *argv[])
// {
// 	int intArr[] = {1, 2, 3, 4, 5, 6, 7};
// 	double doubleArr[] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
// 	const int *p = find1(intArr, 6, 6);
// 	cout << *p << endl;
// 	const double *q = find1(doubleArr, 6, 6.6);
// 	cout << *q << endl;
// 	return 0;
// }

/***************/
/* Interview 6 */
/***************/
// 模板有两种特例化：部分模板特例化和全部模板特例化
// 全部模板特例化就是模板中的模板参数全被指定为确定的类型，也就是定义了一个全新的类型。
// template <typename A, typename B, typename C>
// class X{};
// template <>
// class X<int, float, string> {};

// 部分模板特例化就是模板那种的模板参数没有被全部确定，需要编译器在编译时进行确定。它通常有两种基本情况：
// 1) 对部分模板参数进行特例化：
// template <class B, class C>
// class X <int, B, C>
// {
// 	//...
// };
// 只要实例化时，第一个模板实参是int，就使用特例化版本。

// 2) 使用具有某一特征的类型，对模板参数进行特例化：
// template <class T>
// class Y {				// Y<int>
// 	// ...
// };
// template <class T>
// class Y<T*> {			// Y<int*> T<float*>
// 	// ...
// };

// template <class A, class B>
// class Z {				// Z<int&, float> Z<int, char>
// 	// ...
// };
// template <typename A>
// class Z <A&, char> {	// Z<int&, char> Z<string&, char>
// 	// ...
// };

/***************/
/* Interview 5 */
/***************/
// 模板特化 (template specialization)
// 分为两类：函数模板特化和类模板特化

// 函数模板特化
// template <class T>
// bool IsEqual(T t1, T t2)
// {
// 	return t1 == t2;
// }
// template <>
// bool IsEqual(char* t1, char* t2) // 函数模板特化
// {
// 	return strcmp(t1, t2) == 0;
// }

// int main()
// {
// 	char str1[] = "Hello";
// 	char str2[] = "Hello";
// 	cout << IsEqual(1, 1) << endl;
// 	cout << IsEqual(str1, str2) << endl; // out: 0
// 	return 0;
// }
// // 类模板特化
// template <class T>
// class compare
// {
// public:
// 	bool IsEqual(T t1, T t2)
// 	{
// 		return t1 == t2;
// 	}
// };
// template <>
// class compare<char *> // 特化(char*)
// {
// public:
// 	bool IsEqual(char* t1, char *t2)
// 	{
// 		return strcmp(t1, t2) == 0;
// 	}
// };
// int main()
// {
// 	char str1[] = "Hello";
// 	char str2[] = "Hello";

// 	compare<int> c1;
// 	compare<char *> c2;

// 	cout << c1.IsEqual(1, 1) << endl;
// 	cout << c2.IsEqual(str1, str2) << endl;
// 	return 0;
// }

/***************/
/* Interview 4 */
/***************/
// 类模板实例化
// Q: How many instances of the template class Array will get instantiated inside the function foo?
// A: 3.
// P.S: 模板类的实例个数有类型参数的种类决定。

// template<class T, int size = 10>
// class Array {
// 	// ...
// };
// void foo()
// {
// 	Array <int> arr1;
// 	Array <char> arr4, arr5;
// 	Array <int> arr2, arr3;
// 	Array <double> arr6;
// 	// ...
// }

/***************/
/* Interview 3 */
/***************/
// 理解模板编程的缺陷
// template 模板
// 节省时间和避免代码重复的最佳方法。
 
// 模板的缺点：不当地使用模板会导致代码膨 胀，即二进制代码臃肿而松散，会严重影响程序的运行效率。
// 解决方法：把C++模板中与参 数无关的代码分离出来。

// 代码膨胀：
// template <typename T, int num>
// class A
// {
// public:
// 	void work()
// 	{
// 		cout << "work()" << endl;
// 		cout << num << endl;
// 	}
// };
// int main()
// {
// 	A<int, 1>v1;
// 	A<int, 2>v2;
// 	A<int, 3>v3;
// 	A<int, 4>v4;
// 	v1.work();
// 	v2.work();
// 	v3.work();
// 	v4.work();
// 	return 0;
// }

// fixed
// template <typename T>
// class Base
// {
// public:
// 	void work(int num)
// 	{
// 		cout << "work()" << endl;
// 		cout << num << endl;
// 	}
// };
// template <typename T, int num>
// class Derived : public Base<T>
// {
// public:
// 	void work()
// 	{
// 		Base<T>::work(num);
// 	}
// };
// int main()
// {
// 	Derived<int, 1>d1;
// 	Derived<int, 2>d2;
// 	Derived<int, 3>d3;

// 	d1.work();
// 	d2.work();
// 	d3.work();
// 	return 0;
// }

/***************/
/* Interview 2 ??*/
/***************/
// 函数模板 & 模板函数

// 函数模板和类模板
// 抽象的函数定义， 代表一类同构函数。
// 通过用户提供的具体参数，C++编译器在编译时能将函数模板实例化，根据同一模板创建出不同的具体函数。主要区别在于数据类型不同。
// 定义格式：
// template<TYPE_LIST,ARG_LIST>Function_Definition
// Function_Definition: 函数定义
// TYPE_LIST: 被称为类型参数表
// ARG_LIST: 变量表

// 模板函数不一定指明T的类型。类模板，实例化必须显示指明类型。
// template<<参数表>>
// class<类模板名>
// {
// 	<类模板定义体>
// }

// 函数模板是一种抽象的函数定义，它代表一类同构函数。
// 类模板是一种更高层次的抽象的类定义。

// template <class T1, class T2>
// class Point_T
// {
// public:
// 	T1 a;	// 成员 a 为 T1 类型
// 	T2 b;	// 成员 b 为 T2 类型
// 	Point_T():a(0), b(0) {}								// 默认构造函数
// 	Point_T(T1 ta, T2 tb):a(ta), b(tb) {}				// 带参数的构造函数
// 	Point_T<T1, T2>& operator=(Point_T<T1, T2> &pt);	// 赋值函数
// 	friend Point_T<T1, T2> operator+(Point_T<T1, T2> &pt1, Point_T<T1, T2> &pt2);
// };

// template <class T1, class T2>
// Point_T<T1, T2>& Point_T<T1, T2>::operator=(Point_T<T1, T2> &pt)	// 赋值函数
// {
// 	this->a = pt.a;
// 	this->b = pt.b;
// 	return *this;
// }

// template <class T1, class T2>
// Point_T<T1, T2> operator+(Point_T<T1, T2> &pt1, Point_T<T1, T2> &pt2)
// {
// 	Point_T<T1, T2> temp;
// 	temp.a = pt1.a + pt2.a;
// 	temp.b = pt1.b + pt2.b;
// 	return temp;
// }

// template <class T1, class T2>
// ostream& operator<<(ostream& out, Point_T<T1, T2>& pt)
// {
// 	out << "(" << pt.a << ", " << pt.b << ")";
// 	return out;
// }
// int main(int argc, char const *argv[])
// {
	// Point_T<int, int> intPt1(1, 2);
	// Point_T<int, int> intPt2(3, 4);
	// Point_T<float, float> floatPt1(1.1f, 2.2f);
	// Point_T<float, float> floatPt2(3.3f, 4.4f);

	// Point_T<int, int> intTotalPt;
	// Point_T<float, float> floatTotalPt;

	// intTotalPt = intPt1 + intPt2;
	// floatTotalPt = floatPt1 + floatPt2;

	// cout << intTotalPt << endl;
	// cout << floatTotalPt << endl;

	// return 0;
// }

/***************/
/* Interview 1 */
/***************/
// int max(int a, int b)
// {
// 	return a > b ? a : b;
// }
// float max(float a, float b)
// {
// 	return a > b ? a : b;
// }
// long double max(long double a, long double b)
// {
// 	return a > b ? a : b;
// }
// char max(char a, char b)
// {
// 	return a > b ? a : b;
// }

// // template <class T> // class 
// template <typename T> // typename 
// T max(T a, T b)
// {
// 	return a > b ? a : b;
// }

// int main(int argc, char const *argv[])
// {
// 	cout << max(1, 2) << endl;
// 	cout << max(1.1f, 2.2f) << endl;
// 	cout << max(1.11l, 2.22l) << endl;
// 	cout << max('D', 'F') << endl;
// 	// cout << max<int>(1, 2.0) << endl;	// Error
// 	cout << max(1, 2.0) << endl;
// 	return 0;
// }