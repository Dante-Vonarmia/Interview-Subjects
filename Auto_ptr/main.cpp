#include "iostream"
#include "vector"
#include "memory"
#include "string.h"
using namespace std;

/* Subject 20 */
// 智能指针的实现
// 智能指针是指用来实现指针指向的对象的共享的。其实现实的基本思想：
// 1、	每次创建类的新对象时，初始化指针并将引用计数置为 1；
// 2、	当对象作为另一个对象的副本而创建时，拷贝构造函数拷贝指针并增加与之相应的引用计数；
// 3、	对一个对象进行赋值时，赋值操作符减少左操作数所指对象的引用计数（如果引用计数减至 0，则删除对象），并增加右操作数所指对象的引用计数；
// 4、	调用析构函数时，减少引用计数（如果引用计数减至 0，则删除基础对象）；
// 5、	重载“->”以及“*”操作符，使得智能指针有类似于普通指针的操作。

// 类模板原型
template <class T>
class SmartPtr
{
public:
	SmartPtr(T *p = 0);								// 构造函数
	SmartPtr(const SmartPtr& src);					// 拷贝构造函数
	SmartPtr& operator =(const SmartPtr& rhs);		// 赋值函数
	T* operator ->();								// 重载->
	T& operator *();								// 重载*
	~SmartPtr();									// 析构
private:
	void decrRef()									// 被其他成员函数所调用，自身的引用计数减 1
	{
		if (--*m_pRef == 0)							// 如果计数为 0，则释放内存
		{
			delete m_ptr;							// 删除 m_ptr 所指对象
			delete m_pRef;
		}
	}
	T *m_ptr;										// 保存对象指针
	size_t *m_pRef;									// 保存引用计数
};

// 普通构造函数中，m_ptr 与 p 指向同一块内存，并初始化引用计数为 1。
template <class T>
SmartPtr<T>::SmartPtr(T *p)		// 普通构造函数
{
	m_ptr = p;					// m_ptr 与 p 指向同一内存
	m_pRef = new size_t(1);		// m_pRef 初值为 1
}

// 拷贝构造函数中与普通构造函数的不同之处为引用计数需要加 1。
template <class T>
SmartPtr<T>::SmartPtr(const SmartPtr<T>& src)
{
	m_ptr = src.m_ptr;			// m_ptr 与 src.m_ptr 指向同一内存
	++m_pRef;
	m_pRef = src.m_pRef;		// 拷贝引用
}

// 析构函数调用私有成员 decrRef 对引用计数增减，并且判断是否需要释放对象。
template <class T>
SmartPtr<T>::~SmartPtr()
{
	decrRef();
	cout << "SmartPtr: Destructor" << endl;
}

// “->” 和 “*” 的重载。分别返回 m_ptr 以及 m_ptr 所指的内容即可。若 m_ptr 为空，则应该抛出异常。
template <class T>
T* SmartPtr<T>::operator ->()		// 重载 ->
{
	if (m_ptr)
	{
		return m_ptr;
	}
	// m_ptr 为 NULL 时，抛出异常
	throw runtime_error("access through NULL pointer");
}

template <class T>
T& SmartPtr<T>::operator*()
{
	if (m_ptr)
	{
		return *m_ptr;
	}
	// m_ptr 为 NULL 时，抛出异常
	throw runtime_error("dereference of NULL pointer");
}

// 赋值函数
template <class T>
SmartPtr<T>& SmartPtr<T>::operator =(const SmartPtr<T>& rhs)
{
	++rhs.m_pRef;			// rhs 的引用加 1
	decrRef();				// 自身指向的原指针的引用减 1
	m_ptr = rhs.m_ptr;		// m_ptr 合 rhs.m_ptr 指向同一个对象
	m_pRef = rhs.m_pRef;	// 复制引用
	return *this;
}

int main(int argc, char const *argv[])
{
	SmartPtr<Test> t1;
	SmartPtr<Test> t2(new Test("Terry"));
	SmartPtr<Test> t3(new Test("John"));
	try
	{
		t1 -> ShowName();
	} 
	catch (const exception& err)
	{
		cout << err.what() << endl;
	}

	t2 -> ShowName();
	*t2 = "Dante";
	t2 -> ShowName();
	t2 = t3;

	cout << "End of main..." << endl;
	return 0;
}

/* Subject 18 */
// class Test
// {
// public:
// 	Test() {name = NULL;}
// 	Test(const char* strname)					// 构造函数
// 	{
// 		name = new char[strlen(strname) + 1];	// 分配内存
// 		strcpy(name, strname);					// 拷贝字符串
// 	}
// 	Test& operator =(const char* namestr)		// 赋值函数
// 	{
// 		if (name != NULL)
// 		{
// 			delete name;						// 释放原来当内存
// 		}
// 		name = new char[strlen(namestr) + 1];	// 分配新内存
// 		strcpy(name, namestr);					// 拷贝字符串
// 		return *this;
// 	}
// 	void ShowName() {cout << name << endl;}		// 打印 name
// 	~Test()										// 析构函数
// 	{
// 		if (name != NULL)
// 		{
// 			delete name;						// 释放 name 所指内存
// 		}
// 		name = NULL;
// 		cout << "delete name" << endl;
// 	}
// private:
// 	char *name;
// };

// int main(int argc, char const *argv[])
// {
// 	auto_ptr<Test> TestPtr(new Test("Tara"));		// TestPtr 智能指针
// 	// auto_ptr<Test> TestPtr = new Test("Tara");	// 只能使用拷贝构造函数，所以编译错误。
// 	TestPtr -> ShowName();							// 使用智能指针调用 ShowName() 方法
// 	*TestPtr = "Dante";								// 使用智能指针改变字符串内容
// 	TestPtr -> ShowName();

// 	int y = 1;
// 	int x = 0;
// 	y = y / x;										// 产生异常， TestPtr 指向对象当内存仍然能得到释放

// 	return 0;
// }