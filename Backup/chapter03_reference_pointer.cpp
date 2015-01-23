#include "iostream"
#include "string"
using namespace std;
/****************/
/* Interview 38 */
/****************/
// 句柄：用来标识项目的，这些项目包括：
// 模块				module
// 任务				task
// 实例				instance
// 文件				file
// 内存块			block of memory
// 菜单				menu
// 控制				control
// 字体				font
// 资源				resource
// 	图标				icon
// 	光标				cursor
// 	字符串			string
// GDI对象			GDI object
// 	位图				bitmap
// 	画刷				brush
// 	元文件			metafile
// 	调色板			palette
// 	画笔				pen
// 	区域				region
// 	设备描述表		device context

/****************/
/* Interview 37 */
/****************/
// 内存分配的方式
// 1. 从静态存储区分配。内存在程序编译时就已经分 配好了。这块内存在程序的整个运行期间都存在，如，全局变量。
// 2. 在栈上创建。在执行函数时，函数内局部变量的 存储单元都可以在栈上创建，函数执行结束时，这些单元自动释放。
//    处理器的指令集中有关于栈内存的分配运算，因此效率高，但是分配的内存容量有限。
// 3. 从堆上分配，亦称动态内存分配。程序在运行的 时候用malloc或new申请任意多少的内存，程序员自己负责在何时用free或delete 释放内存。
//    动态内存的生存期由我们决定，使用非常灵活，但问题也最多。


/****************/
/* Interview 36 */
/****************/
// 野指针 不能用于变量值的互换
// // wrong
// swap(int* p1, int* p2) {
// 	int *p; 	// not initialized. 
// 	*p = *p1;
// 	*p1 = *p2;
// 	*p2 = *p;
// }

// // OK
// swap(int* p1, int* p2) {
// 	int p;
// 	*p = *p1;
// 	*p1 = *p2;
// 	*p2 = p;
// }

/****************/
/* Interview 35 */
/****************/
// 比较分析两个代码段的输出——动态内存的传递
/* e.q. 1 */
// char *GetMemory()
// {
// 	// char p[] = "hello world";
// 	static char p[] = "hello world";
// 	return p;
// }

// void Test(void)
// {
// 	char *str = NULL;
// 	str = GetMemory();
// 	printf(str);
// }

/* e.q. 2 */
// void GetMemory(char* p)
// {
// 	p = (char*)malloc(100); // no returning value;
// }
// void Test(void)
// {
// 	char *str = NULL;
// 	GetMemory(str);
// 	strcpy(str, "hello world"); // Crash!!  str is still "NULL".
// 	printf(str);
// }
/****************/
/* Interview 34 */
/****************/
// 动态内存的传递
// void GetMemory(char *p, int num)
// {
// 	p = (char *)malloc(sizeof(char) *num); // 虽然p申请了堆内存，但返回main函数是，str还是NULL， 调用strcpy时会导致程序崩溃
// };

// void GetMemory2(char **p, int num)
// {
// 	*p = (char *)malloc(sizeof(char) *num); // 把str的地址传给函数GetMemory。
// }

// void GetMemory3(char *&p, int num)
// { 
// 	p = (char *)malloc(sizeof(char) *num); // 在C++中，多了一种选择，就是传递str指针的引用。
// }

// char *GetMemory4(int num)
// {
// 	char *p = (char *)malloc(sizeof(char) *num); // 使用函数返回值来传递动态内存。
// 	return p;
// }

// int main()
// {
// 	char *str1 = NULL;
// 	char *str2 = NULL;
// 	char *str3 = NULL;
// 	char *str4 = NULL;

// 	// GetMemory(str1, 10);
// 	GetMemory2(&str2, 20);
// 	GetMemory3(str3, 20);
// 	str4 = GetMemory4(20);

// 	// strcpy(str, "hello");
// 	strcpy(str2, "GetMemory 2");
// 	strcpy(str3, "GetMemory 3");
// 	strcpy(str4, "GetMemory 4");

// 	cout << "str1 == NULL ? " << (str1 == NULL ? "yes":"no") << endl;
// 	cout << "str2: " << str2 << endl;
// 	cout << "str3: " << str3 << endl;
// 	cout << "str4: " << str4 << endl;

// 	free(str2);
// 	free(str3);
// 	free(str4);
// 	str2 = NULL;
// 	str3 = NULL;
// 	str4 = NULL;
// 	return 0; 
// }
/****************/
/* Interview 33 */
/****************/
// 动态内存的传递
// class Base
// {
// private:
// 	char* name;
// public:
// 	Base(char *className) {
// 		// name = new char[strlen(className)];
// 		// string end with '\0'
// 		name = new char[strlen(className) + 1];
// 		strcpy(name, className);
// 	}
// 	~Base() {
// 		delete name;
// 	}
// 	char *copyName() {
// 		// char newname[10] = "";
// 		// Base 的成员函数copyName()中，返回其内数组的地址。
// 		// 由于数组处于栈中，当copyName调用结束后，栈就会被销毁。这里应返回堆内存地址。
// 		char *newname = new char[strlen(name) + 1];
// 		strcpy(newname, name);

// 		return newname;
// 	}
// 	char *getName() {
// 		return name;
// 	}
// };
// class Subclass:public Base
// {
// public:
// 	Subclass(char *className):Base(className){}
// 	~Subclass(){}
// };
// int main(int argc, char const *argv[])
// {
// 	Base *pBase = new Subclass("test");
// 	cout << "name: " << pBase -> getName() << endl;
// 	cout << "new name: " << pBase -> copyName() << endl;
// 	return 0;
// }

/****************/
/* Interview 32 */
/****************/
// C语言的标准内存分配函数：malloc、calloc 、realloc、free
// malloc 的调用形式为(类型*)malloc(size);
// 在内存的动态存储区中分配一块长度为“size”字节的连续区域，返回该区域的首地址，此时内存中的值没有初始化，是个随机数。

// calloc 的调用形式为(类型*)calloc(n, size);
// 在内存的动态存储区中分配 n 块长度为“size”字节的连续区域，返回首地址，此时内存中的值都被初始化为0。

// realloc 的调用形式为(类型*)realloc(*ptr, size);
// 将ptr内存大小增大到size，新增加的内存块 没有初始化。

// free 的调用形式为(类型*)free(void *ptr);
// 释放ptr所指向的一块内存空间。

/****************/
/* Interview 31 */
/****************/
// 指针初始化
// 野指针必须初始为NULL
// #include "malloc.h"
// struct Tag_Node
// {
// 	struct Tag_Node* left;
// 	struct Tag_Node* right;
// 	int value;
// };

// typedef struct Tag_Node TNode;

// TNode* root = NULL;

// void append(int N);
// void print();

// int main(int argc, char const *argv[])
// {
// 	append(63);
// 	append(45);
// 	append(32);
// 	append(77);
// 	append(96);
// 	append(21);
// 	append(17);
// 	printf("head: %d\n", root -> value);
// 	print();

// 	return 0;
// }

// void append(int N)
// {
// 	TNode* NewNode = (TNode *)malloc(sizeof(TNode));
// 	NewNode -> value = N; // 对堆中分配的内存只做了成员value的初始化 。没有对left和right初始化为NULL。
// 	//fixed
// 	NewNode -> left = NULL;
// 	NewNode -> right = NULL;

// 	if (root == NULL)
// 	{
// 		root = NewNode;
// 		return;
// 	} else {
// 		TNode* temp;
// 		temp = root;

// 		while((N >= temp -> value && temp -> left != NULL) || (N < temp -> value && temp -> right != NULL))
// 		{
// 			while(N >= temp -> value && temp -> left != NULL)
// 			{
// 				temp = temp -> left;
// 			}
// 			while(N >= temp -> value && temp -> right != NULL)
// 			{
// 				temp = temp -> right;
// 			}
// 			if (N >= temp -> value)
// 			{
// 				temp -> left = NewNode;
// 				NewNode -> right = temp; // 形成双向链表
// 			} else {
// 				temp -> right = NewNode;
// 				NewNode -> left = temp; // 形成双向链表
// 			}
// 			return;
// 		}
// 	}
// }

// void print()
// {
// 	TNode* leftside = NULL;

// 	if (root == NULL)
// 	{
// 		cout << "There is not any element1" << endl;
// 		return;
// 	}

// 	leftside = root -> left;

// 	while(1)
// 	{
// 		if (leftside -> left == NULL)
// 		{
// 			break;
// 		}
// 		leftside = leftside -> left;
// 	}

// 	while(leftside != NULL)
// 	{
// 		cout << leftside -> value << endl;
// 		leftside = leftside -> right;
// 	}
// }

/****************/
/* Interview 30 */
/****************/
// malloc/free & new/delete
// malloc/free 是库函数，不是运算符。不自动调用构造函数和析构函数

// class Obj
// {
// public:
// 	Obj(void) {
// 		cout << "Initialization" << endl;
// 	}
// 	~Obj(void) {
// 		cout << "Destory" << endl;
// 	}
// };

// void UseMallocFree(void) {
// 	cout << "in UseMallocFree()..." << endl;
// 	Obj *a = (Obj *)malloc(sizeof(Obj));
// 	free(a);
// }

// void UseNewDelete(void) {
// 	cout << "in UseNewDelete()..." << endl;
// 	Obj *a = new Obj;
// 	delete a;
// }

// int main(int argc, char const *argv[])
// {
// 	UseMallocFree();
// 	UseNewDelete();

// 	return 0;
// }

/* Result: */
// in UseMallocFree()...
// in UseNewDelete()...
// Initialization
// Destory

/*******************/
/* Interview 28&29 */
/*******************/
// 野指针
// “野指针”不是NULL指针，而是指向“垃圾”内存的指针。
// 其成因主要为：
// 1. 指针变量没有被初始化。
// 2. 指针被free或者delete后没有置为NULL。

/* e.q. */
// short *bufptr;			// 声明了一个short*类型的指针，并且没有对它初始化。
// short bufarray[20];		// 声明了一个20个元素的数组，每个元素都是short类型。
// short var = 0x20;		// 声明了short类型的变量var。
// *bufptr = var;			// 野指针，bufptr指针没有被初始值。
// short *bufptr = (*short)malloc(sizeof(short)); // 初始化。
// bufarray[0] = var;		// 正确

/****************/
/* Interview 27 */
/****************/
// 函数指针定义中typedef的作用
// typedef int (*pfun)(int x, int y);	// 定义了pfun数据类型，表示一个函数指针类型
// int fun(int x, int y);				// 定义了一个函数指针。
// pfun p = fun;						// 定义了一个pfun类型的函数指针p,并赋给它fun的地址。
// int ret = p(2, 3);					// 调用p(2, 3)，实现fun(2, 3)的调用功能。

/****************/
/* Interview 26 */
/****************/
// 函数指针使用
// int add1(int a1, int b1) {
// 	return a1 + b1;
// }

// int add2(int a2, int b2) {
// 	return a2 + b2;
// }

// int main(int argc, char const *argv[])
// {
// 	int numa1 = 1, numb1 = 2;
// 	int numa2 = 2, numb2 = 3;
// 	int (*op[2])(int a, int b);
// 	op[0] = add1;
// 	op[1] = add2;
// 	cout << op[0](numa1, numb1) << op[1](numa2, numb2);
// 	getchar();
// 	return 0;
// }

/****************/
/* Interview 25 */
/****************/
// int max(int x, int y) {
// 	return x > y ? x : y;	
// }
// int main(int argc, char const *argv[])
// {
// 	int *p; // (*p)(int, int)
// 	int a, b, c;
// 	int result;
// 	int max(x, y); // max(int, int)

// 	p = &max;
// 	cout << "Please input three integer" << endl;
// 	cin >> a >> b >> c;
// 	result = (*p)((*p)(a, b), c);
// 	cout << "result = " << endl;

// 	return 0;
// }

/****************/
/* Interview 24 */
/****************/
// 函数指针、函数返回指针、const指针、指向const的指针 、指向const的const指针。

// void(*f)(int, int)，f是指向void max(int x, int y)类型的函数指针。
// int *fn(), fn是返回int指针类型的函数。
// const int *p, p是一个指向const的指针，指向一个常量。
// int* const q, q是一个const指针。
// const int* const ptr, ptr是指向const的const指针。

/*******************/
/* Interview 22&23 */
/*******************/
// // 函数指针 & 指针函数
// // 返回类型标识符 *返回名称(形式参数表) {函数体}
// int max(int x, int y) {
// 	return (x > y ? x : y);
// };

// float *find(float *p, int x) {
// 	return p + x;
// }

// int main(int argc, char const *argv[])
// {
// 	float score[] = {10, 20, 30, 40};
// 	int (*p)(int, int);
// 	float *q = find(score + 1, 1);
// 	int a;

// 	p = max;
// 	a = (*p)(1, 2);

// 	cout << "a = " << a << endl;
// 	cout << "*q = " << *q << endl;

// 	return 0;
// }

// int *p[10];
// int (*p)[10];  int *p = new int[10];
// int (*func)(int);
// int (*p[10])(int);

/****************/
/* Interview 21 */
/****************/
// int main(int argc, char const *argv[])
// {
// 	const char *str[] = {"Welcome","to","the","jungle~~~"};
// 	const char **p = str + 1;
// 	str[0] = (*p++) + 2;
// 	str[1] = *(p + 1);
// 	str[2] = p[1] + 3;
// 	str[3] = p[0] + (str[2] - str[1]);

// 	cout << str[0] << endl; // 
// 	cout << str[1] << endl; // jungle~~~
// 	cout << str[2] << endl; // gle~~~
// 	cout << str[3] << endl; // ~~~

// 	return 0;
// }

/****************/
/* Interview 20 */
/****************/
// 指针数组&数组指针 区别
// 指针数组
// 一个数组里存放同一类型的指针
// int *p[19];
// 数组指针
// 一个指针，并且指向一个数组
// int *b = new int[10];

// int main(int argc, char const *argv[])
// {
// 	int x1[4] = {1, 2, 3 ,4};
// 	int x2[2] = {5, 6};
// 	int x3[3] = {7, 8, 9};
// 	int *a[2];
// 	int *b = x1;
// 	int i = 0;

// 	a[0] = x2;
// 	a[1] = x3;

// 	cout << "a[0]: ";
// 	for (int i = 0; i < sizeof(x2) / sizeof(int); ++i)
// 	{
// 		cout << a[0][i] << " "; // 5 6
// 	}
// 	cout << endl;
	
// 	cout << "a[1]: ";
// 	for (int i = 0; i < sizeof(x3) / sizeof(int); ++i)
// 	{
// 		cout << a[1][i] << " "; // 7 8 9
// 	}
// 	cout << endl;
	
// 	cout << "b: ";
// 	for (int i = 0; i < sizeof(x1) / sizeof(int); ++i)
// 	{
// 		cout << b[i] << " "; // 1 2 3 4
// 	}
// 	cout << endl;

// 	return 0;
// }

/*******************/
/* Interview 18&19 */
/*******************/
// this指针
// 类的非静态成员函数才有this指针

// class MyClass
// {
// public:
// 	int data;
// 	MyClass(int data) {
// 		this->data = data;
// 		cout << "MyClass()" << endl;
// 	}
// 	~MyClass() {
// 		cout << "~MyClass()" << endl;
// 	}

// 	void print() {
// 		// cout << data << endl;
// 		cout << "hello!" << endl;
// 	}
// };
// int main(int argc, char const *argv[])
// {
// 	MyClass *pMyClass;
// 	pMyClass = new MyClass(1);
// 	pMyClass->print(); // 1 
// 	pMyClass[0].print(); // 1
// 	pMyClass[1].print();  // -3368019
// 	pMyClass[10000000].print(); // 段错误
// 	delete pMyClass;
// 	return 0;
// }

/****************/
/* ??Interview 17 */
/****************/
// int main(int argc, char const *argv[])
// {
	// const char *node1 = "abc";
			//  node1[2] = 'k';	// compiler error
			// *node1[2] = 'k';	// compiler error
			//    *node1 = "xyz";	// compiler error
				// node1 = "xyz";	// T

	// char* const node2 = "abc";
			//  node2[2] = 'k';	// operator error
			// *node2[2] = 'k';	// compiler error
			//    *node2 = "xyz";	// operator error
				// node2 = "xyz";	// compiler error
	// return 0;
// }

/****************/
/* Interview 16 */
/****************/
// const关键字在指针声明时的作用
// char *const p1;			// 指针常量 
// char const* p2;			// 常量指针 
// const int *p3;			// 常量指针 
// const char *const p4;	

/****************/
/* Interview 15 */
/****************/
// 常量指针 
// const int *p;
// int const *p;
// 1. 常量的指针。 本质是指针。
// 2. 它是一个指向常量的指针。
// 3. 防止指针误操作出现修改常量的错误。
// 4. 所指向的地址是不可修改的。

// 指针常量 
// int *const p;
// 1. 指针的常量。 本质是常量。
// 2. 首先是常量，然后才是一个指针。
// 3. 不能修改指针所指向的地址。
// 4. 可以对它所指向的内容进行修改。

/****************/
/* Interview 14 */
/****************/
// 指针类型隐式转换
// int main(int argc, char const *argv[])
// {
// 	int ival = 1024; 
// 	int ival2 = 2048;
// 	int *pi1 = &ival;
// 	int *pi2 = *ival2;
// 	int **pi3 = 0;

// 	ival = *pi3;	// int int* compiler error
// 	*pi2 = *pi3;	// int int* compiler error
// 	ival = pi2;		// int int* compiler error
// 	 pi2 = *pi1;	// int* int compiler error
// 	 pi1 = *pi3;	// NULL 	operator error
// 	ival = *pi1;	// int int
// 	 pi1 = ival;	// int* int compiler error
// 	 pi3 = &pi2;	// int** int**
	
// 	return 0;
// }

/****************/
/* Interview 13 */
/****************/
// 内存违规
// char a;
// char *str1 = &a;
// const char* str2 = "AAA";

// strcpy(str1, "hello"); // error
// cout << str1 << endl;

// str2[0] = 'B'; // error
// cout << str2 << endl;

/****************/
/* Interview 12 */
/****************/
// int main(int argc, char const *argv[])
// {
// 	char str1[] = "abc";
// 	char str2[] = "abc";
// 	const char str3[] = "abc";
// 	const char str4[] = "abc";
// 	const char* str5 = "abc";
// 	const char* str6 = "abc";
// 	char* str7 = "abc";
// 	char* str8 = "abc";

// 	cout << (str1 == str2) << endl; // 0
// 	cout << (str3 == str4) << endl; // 0
// 	cout << (str5 == str6) << endl; // 1
// 	cout << (str7 == str6) << endl; // 1
// 	cout << (str7 == str8) << endl; // 1
// 	return 0;
// }

/****************/
/* Interview 11 */
/****************/
// int a[5] = {1,2,3,4,5};
// int *ptr = (int *)(&a + 1);

// cout << &a << endl;
// cout << &a[1] << endl;
// cout << &a[4] << endl;
// cout << &ptr << endl;
// cout << *(a + 1) << endl;
// cout << *(ptr - 1) << endl;

/****************/
/* Interview 10 */
/****************/
// 指针赋值
// int main(int argc, char const *argv[])
// {
// 	char a[] = "Hi Dante!";
// 	char *ptr = a;

// 	cout << *(ptr + 4) << endl;
// 	cout << ptr[4] << endl;
// 	cout << a[4] << endl;
// 	cout << *(a+4) << endl;

// 	*(ptr + 4) += 1;
// 	cout << a << endl;
// 	return 0;
// }

/***************/
/* Interview 9 */
/***************/
// 指针声明
// int a;					An integer
// int *a;					A pointer to an integer
// int **a;					A pointer to a pointer to an integer
// int a[10];				An array of 10 integers
// int *a[10];				An array of 10 pointers to integers
// int (*a)[10];			A pointer to an array of 10 integers
// int (*a)(int);			A pointer to a function that takes an integer as an argument and returns an integer.
// int (*a[10])(int);		An array of 10 pointers to functions that takes an integer argument and return an integer.

// e.q.
// int (*func)(int *p);
// int (*func)(int *p, int (*f)(int*));
// int (*func[5])(int *p);
// int (*(*func)[5])(int *p);
// int (*(*func)(int *p))[5];

/*****************/
/* Interview 7&8 */
/*****************/
// 引用和指针 
// 初始化要求：
// 1. 引用创建时必须初始化。
// 2. 指针不必。

// 指向
// 1. 引用被初始化为指向一个对象。不能被改变为另一个对象的引用。
// 2. 指针在任何时候可以改变指向对象。       
// 3. 给引用赋值不改变它和原始对象的绑定关系。

// NULL
// 1. 引用不存在NULL。
// 2. 指针可以NULL。

// 测试
// 1. 引用不需要测试其合法性。
// 2. 指针需要经常测试。
// 3. 引用的代码效率比指针高。

// 总结：
// 1. 引用既具有指针的效率，又有变量使用的方便性和 直观性
// 2. const指针存在空指针，并且有可能产生野指针。

/***************/
/* Interview 6 */
/***************/
// 参数引用 3 常见错误
// class Test
// {
// public:
// 	void f(const int& arg);
// private:
// 	int value;
// };

// void Test::f(const int& arg) {
// 	arg = 10; // Error
// 	cout << "arg = " << arg << endl;
// 	value = 20;
// }

// int main(int argc, char const *argv[])
// {
// 	int a = 7;
// 	const int b = 10;
// 	int &c = b; // expected 'const' before 'int'
// 	const int &d = a;

// 	a++;
// 	d++; // Error: d is 'const'

// 	Test test;
// 	test.f(a);
// 	cout << "a = " << a << endl;

// 	return 0;
// }
/***************/
/* Interview 5 */
/***************/
// 参数引用 2
// const float pi = 3.14f;
// float f;
// float f1(float r) {
// 	f = r * r * pi;
// 	return f;
// }
// float& f2(float r) {
// 	f = r * r * pi;
// 	return f;
// }
// int main(int argc, char const *argv[])
// {
// 	float f1(float=5);
// 	float& f2(float=5);
// 	float a = f1();
// 	float& b = f1(); // Error
// 	float c = f2();
// 	float& d = f2();

// 	d += 1.0f;
// 	// a: 78.5
// 	// b: null
// 	// c: 78.5
// 	// d: 79.5
// 	// f: 79.5
// 	return 0;
// }

/***************/
/* Interview 4 */
/***************/
// 参数引用 1
// void swap(char *&x, char *&y) { // 指针引用类型
// 	char *temp;
// 	temp = x;
// 	x = y;
// 	y = temp;
// }
// void swap(char **x, char **y) { // 二维指针
// 	char *temp;
// 	temp = *x;
// 	*x = *y;
// 	*y = temp;
// }

// int main() {
// 	char const *ap = "hello";
// 	char const *bp = "how are you?";

// 	cout << "ap:" << ap << endl; // hello
// 	cout << "bp:" << bp << endl; // how are you?

// 	swap(ap, bp); // 1
// 	swap(&ap, &bp); // 2

// 	cout << "swap ap, bp" << endl;
// 	cout << "ap:" << ap << endl; // how are you? 
// 	cout << "bp:" << bp << endl; // hello 

// 	return 0;
// }

/***************/
/* Interview 3 */
/***************/
// int main(int argc, char const *argv[])
// {
// 	int a = 1, b = 2;
// 	int &c; // Error: not initialized
// 	int &d = a;
// 	&d = b; // Error: no reuse
// 	int *p; // Not initialized

// 	*p = 5; // Error

// 	return 0;
// }

/***************/
/* Interview 2 */
/***************/
// 指针变量引用
// int main(int argc, char const *argv[])
// {
// 	int a = 1;
// 	int b = 10;
// 	int* p = &a;
// 	int* &pa = p;

// 	(*pa)++;
// 	cout << "a = " << a << endl; // 2
// 	cout << "b = " << b << endl; // 10
// 	cout << "p = " << *p << endl; // 2

// 	pa = &b;
// 	(*pa)++;
// 	cout << "a = " << a << endl; // 2
// 	cout << "b = " << b << endl; // 11
// 	cout << "p = " << *p << endl; // 11
// 	return 0;
// }

/***************/
/* Interview 1 */
/***************/
// 一般变量引用
// int main(int argc, char const *argv[])
// {
// 	int a = 10;
// 	int b = 20;
// 	int &rn = a;
// 	int equal;

// 	rn = b;
// 	cout << "a = " << a << endl; // 20
// 	cout << "b = " << b << endl; // 20

// 	rn = 100;
// 	cout << "a = " << a << endl; // 100
// 	cout << "b = " << b << endl; // 20

// 	equal = (&a == &rn) ? 1 : 0;

// 	cout << "equal = " << equal << endl; // 1
// 	return 0;
// }