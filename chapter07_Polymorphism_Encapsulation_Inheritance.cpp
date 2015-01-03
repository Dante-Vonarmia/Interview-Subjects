#include "iostream"
using namespace std;

/****************/
/* Interview 20 */
/****************/
// COM

/****************/
/* Interview 19 */
/****************/
// 参见示例 ./Shape

/****************/
/* Interview 18 */
/****************/
// 抽象类不能被实例化
// class Shape
// {
// public:
// 	Shape() {}
// 	~Shape() {}

// 	virtual void Draw() = 0;
// };

// int main(int argc, char const *argv[])
// {
// 	Shape s1;	// cannot declare variable ‘s1’ to be of abstract type ‘Shape’
// 	Shape *s1;
// 	return 0;
// }

/****************/
/* Interview 17 */
/****************/
// 虚函数与纯虚函数区别
// (1) 类里声明了虚函数，这个函数是实现的，哪怕是空实现。
	// 纯虚函数只是一个接口，是个函数的声明而已，它要留到子类里去实现。

// (2) 虚函数在子类里面也可以不重载；
	// 虚函数必须在子类去实现。
	// 函数加上 virtual，增加面向对象的多态性，很难预料到父类里面的这个函数不在子类里不去修改它的实现。

// (3) 虚函数的类用于“实作继承”，也就是说继承接口的同时也继承了父亲的实现。
	// 纯虚函数的类用于“介面继承”，即纯虚函数关注的是接口的统一性，实现由子类完成。

// (4) 带纯虚函数的类叫虚基类，这种基类不能直接生成对象， 而只有被继承，并重写其虚函数后，才能使用，也叫抽象类。

/****************/
/* Interview 16 */
/****************/
// 为什么引入抽象基类和纯虚函数？
// (1) 为了方便使用多态特性
// (2) 基类本身生成对象不是合理的，抽象基类不能够被实例化，它定义的纯虚函数相当于接口，能把派生类的共同行为提取出来
// #include "memory.h"
// #include "assert.h"
// class Animal
// {
// public:
// 	// 纯虚函数，必须在派生类被定义
// 	virtual void sleep() = 0;
// 	virtual void eat() = 0;
// };

// class Tiger : public Animal
// {
// public:
// 	void sleep() { cout << "Tiger sleep" << endl; }
// 	void eat() { cout << "Tiger eat" << endl; }
// };

// class Lion : public Animal
// {
// public:
// 	void sleep() { cout << "Lion sleep" << endl; }
// 	void eat() { cout << "Lion eat" << endl; }
// };

// int main(int argc, char const *argv[])
// {
// 	Animal *p; 			// Animal 指针，不能使用 Animal animal 定义对象
// 	Tiger tiger;
// 	Lion lion;

// 	// 使用指针调用 Animal 类中的接口（纯虚函数）完成多态
// 	p = &tiger;			// 指向 Tiger 对象
// 	p->sleep();			// 调用 Tiger::sleep()
// 	p->eat();			// 调用 Tiger::eat()
// 	p = &lion;			// 指向 Lion 对象
// 	p->sleep();			// 调用 Lion::sleep()
// 	p->eat();			// 调用 Lion::eat()

// 	return 0;
// }

/****************/
/* Interview 15 */
/****************/
// 多重继承和虚拟继承
// 多继承中的构造函数顺序如下：
// (1) 任何虚拟基类的构造函数按照它们被继承的顺序构造。
// (2) 任何非虚拟基类的构造函数按照它们被构造的顺序构造。
// (3) 任何成员对象的构造按照它们声明的顺序调用。
// (4) 类自身的构造函数。

// class Parent
// {
// public:
// 	Parent() : num(0) { cout << "Parent" << endl; }
// 	Parent(int n) : num(n) {cout << "Parent(int)" << endl; }
// private:
// 	int num;
// };

// class Child1 : public Parent
// // class Child1 : virtual public Parent
// {
// public:
// 	Child1() { cout << "Child1()" << endl; }
// 	Child1(int num) : Parent(num) { cout << "Child1(int)" << endl; }
// };

// class Child2 : public Parent
// // class Child2 : virtual public Parent
// {
// public:
// 	Child2() { cout << "Child2()" << endl; }
// 	Child2(int num) : Parent(num) { cout << "Child2(int)" << endl; }
// };

// // 多重继承类对象的构造顺序与其继承列表中基类的排列顺序一致，而不是与构造函数的初始化列表顺序一致。
// // (1) 构造 Child1。由于 Child1 继承自 Parent，因此先调用 Parent 的构造函数，再调用 Child1 的构造函数。
// // (2) 调用 Child2。过程与（1）类似。
// // (3) 调用 Derived 类的构造函数。
// class Derived : public Child1, public Child2
// {
// public:
// 	Derived() : Child1(0), Child2(1) {}
// 	Derived(int num) : Child2(num), Child1(num+1) {}
// };

// int main(int argc, char const *argv[])
// {
// 	// Derived a;
// 	Derived d(4);
// 	return 0;
// }


/*********************/
/* Interview 13 & 14 */
/*********************/
// 多重继承中的二议性与消除
// class Animal {};

// class cat : virtual public Animal
// {
// public:
// 	void show()
// 	{
// 		cout << "cat" << endl;
// 	}
// };

// class fish : virtual public Animal
// {
// public:
// 	void show()
// 	{
// 		cout << "fish" << endl;
// 	}
// };

// class cat_fish : public cat, public fish {};

// int main(int argc, char const *argv[])
// {
// 	cat_fish obj;
// 	// obj.show		// Error
// 	obj.cat::show();
// 	Animal *a = &obj;
// 	return 0;
// }

/****************/
/* Interview 12 */
/****************/
// 为什么需要多重继承？它的优缺点是什么
// (1) 一些对象有两个或两个以上的属性。需要引入多重继承。
// (2) 优点，对象可以调用多个基类中的接口
// (3) 缺点，派生类所继承的多个基类有相同的基类，派生类对 象需要调用祖先类的接口方法，就会容易出现二议性。
	// Programmer_Author 拥有类 Author 和 类 Programmer 的两份拷贝。
	// a. 通过加上全局符指定调用
	// b. 使用虚继承

// class Person
// {
// public:
// 	void sleep() { cout << "sleep" << endl; }
// 	void eat() { cout << "eat" << endl; }
// };

// class Author : virtual public Person		// Author inherit from Person
// {
// public:
// 	void writeBook() { cout << "write book" << endl; }
// };

// class Programmer : virtual public Person	// Programmer inherit from person
// {
// public:
// 	void writeCode() { cout << "write code" << endl; }
// };

// class Programmer_Author : public Programmer, public Author {};	// 拥有类 Author 和 类 Programmer 的两份拷贝。

// int main(int argc, char const *argv[])
// {
// 	Programmer_Author pa;

// 	pa.writeBook();		// 调用基类 Author 的方法
// 	pa.writeCode();		// 调用基类 Programmer 的方法
// 	pa.Author::eat();	// 加上全局符确定调用拷贝
// 	pa.eat();			// eat() 定义不明
// 	pa.sleep();			// sleep() 定义不明

// 	return 0;
// }

/****************/
/* Interview 11 */
/****************/
// 选择题：对C++类虚拟机制的理解
// #include "complex"
// class Base
// {
// public:
// 	Base() { cout << "Base-ctor" << endl; }
// 	~Base() { cout << "Base-dtor" << endl; }
// 	virtual void f(int) { cout << "Base::f(int)" << endl; }
// 	virtual void f(double) { cout << "Base::f(double)" << endl; }
// 	virtual void g(int i = 10) { cout << "Base::g()" << i << endl; }
// };

// class Derived : public Base
// {
// public:
// 	Derived() { cout << "Derived-ctor" << endl; }
// 	~Derived() { cout << "Derived-dtor" << endl; }
// 	void f(complex<double> c){ cout << "Derived::f(complex)" << endl; }
// 	virtual void g(int i = 20) { cout << "Derived::g()" << i << endl; }
// };

// int main(int argc, char const *argv[])
// {
// 	Base b;
// 	Derived d;
// 	Base* pb = new Derived;
	
// 	cout << sizeof(Base) << endl;
// 	cout << sizeof(Derived) << endl;
// 	pb->f(1.0);
// 	pb->g();	
// 	return 0;
// }

// (1) cout << sizeof(Base) << endl;
// A. 4	B. 32	C. 20	D. 与平台相关

// (2) cout << sizeof(Derived) << endl;
// A. 4	B. 8	C. 36	D. 与平台相关

// (3) pb->f(1.0);
// A. Derived::f(complex)		B. Base::f(double)
// C. Base::f(int)				D. Derived::f(double)

// (4) pb->g();
// A. Base::g()10
// B. Base:g()20
// C. Derived::g()10
// D. Derived::g()20

// (1) Base 类没有任何数据成员，并且含有虚函数，所以系统会为它分配一个指针指向虚函数表。指针的大小是4个字节。

// (2) Derived 类没有任何数据成员，它是 Base 的派生类，继承了 Base 的虚函数表。系统也会为它分配一个指针指向这张虚函数表。

// (3) 由于参数1.0默认是 double 类型，因此调用的是 Base::f(double)。

// (4) 由于参数的值是在编译期就已经决定的，而不是在运行期 ，因此参数i应该取 Base 类的默认值 10

/****************/
/* Interview 10 */
/****************/
// C++类虚拟机制的理解
// #include "string.h"

// void println(const std::string& msg)
// {
// 	cout << msg << "\n";
// }

// class Base
// {
// public:
// 	Base()
// 	{
// 		println("Base::Base()");		// (1) 先调用 Base 的构造函数
// 		virt();							// (2) 接着调用 Base 类的 virt() 函数
// 	}
// 	void f()
// 	{
// 		println("Base::f()");
// 		virt();							// (6) f()函数又调用虚函数 virt()
// 	}
// 	virtual void virt()
// 	{
// 		println("Base::virt()");
// 	}
// };

// class Derived : public Base
// {
// public:
// 	Derived()
// 	{
// 		println("Derived::Derived()");	// (3) 然后调用 Derived 的构造函数
// 		virt();							// (4) 最后执行 Derived 类的 virt() 函数
// 	}
// 	virtual void virt()					// (7) 因为多态，指针 pB 是指向 Derived 类对象的
// 	{									// (8) 因此实际执行的是 Derived 类中的 virt() 成员。
// 		println("Derived::virt()");
// 	}
// };

// int main(int argc, char const *argv[])
// {
// 	Derived d;
// 	Base *pB = &d;
// 	pB->f();							// (5) Base 类的指针 pB 访问类的公有成员函数 f()

// 	return 0;
// }

/***************/
/* Interview 9 */
/***************/
// 虚函数的作用
// class A
// {
// public:
// 	virtual void print(void)
// 	{
// 		cout << "A::print()" << endl;
// 	}
// };

// class B : public A
// {
// public:
// 	virtual void print(void)
// 	{
// 		cout << "B::print()" << endl;
// 	}
// };

// class C : public A
// {
// public:
// 	virtual void print(void)
// 	{
// 		cout << "C::print()" << endl;
// 	}
// };

// // void print(A &a)		// 传引用，多态
// void print(A a)			// 传值
// {
// 	a.print();			// 对象 a、b、c 分别传入时，在函数栈中会分别生成类 A  的临时对象，
// 						//因此执行的都是类 A 的 print() 成员函数。
// }

// int main(int argc, char const *argv[])
// {
// 	A a, *pa, *pb, *pc;
// 	B b;
// 	C c;

// 	pa = &a;
// 	pb = &b;
// 	pc = &c;

// 	a.print();
// 	b.print();
// 	c.print();

// 	pa->print();
// 	pb->print();
// 	pc->print();

// 	print(a);
// 	print(b);
// 	print(c);

// 	return 0;
// }

/***************/
/* Interview 8 */
/***************/
// 虚函数不会向下匹配到派生类，而是直接执行基类的函数。

// 在构造函数中，虚拟机制不会发生作用，
// 因为基类的构造函数在派生类构造函数之前执行，当基类构造函数运行时，派生类数据成员还没有被初始化。
// class A
// {
// public:
// 	A() { doSth(); }
// 	virtual void doSth() { cout << "I am A\n"; }
// };

// 如果基类构造期间调用的虚函数向下匹配到派生类，派生类的函数理所当然会涉及本地数据成员，
// 但是那些数据成员还没有被初始化，而调用涉及一个对象还没有被初始化，而调用涉及一个对象还没有被初始化的部分自然是危险的，
// 所以C++不建议这么做。
// class B : public A
// {
// public:
// 	virtual void doSth() { cout << "I am B\n"; }
// };

// int main(int argc, char const *argv[])
// {
// 	B b;

// 	return 0;
// }

/***************/
/* Interview 7 */
/***************/
// 虚函数是怎么实现的
// (1) 虚函数是通过虚函数表实现的
// (2) 如果一个类中含有虚函数，则系统会为这个类分配一个指针成员指向一张虚函数表（vtbl）
	// 表中每一项指向一个虚函数的地址，实现上就是一个函数指针的数组。

// Parent 类的 vbl：Parent::foo1()的地址、Parent::foo1();
// class Parent
// {
// public:
// 	virtual void foo1() {}
// 	virtual void foo2() {}
// 	void foo3();
// };

// Child1 类的 vbl：Child1::foo1()的地址、Parent::foo1();
// class Child1
// {
// public:
// 	void foo1() {}
// 	void foo3();
// };

// Child2 类的 vbl：Child1::foo1()的地址、Child2::foo1();
// class Child2
// {
// public:
// 	void foo1() {}
// 	void foo2() {}
// 	void foo3();
// };

/***************/
/* Interview 6 */
/***************/
// 多态
// 多态性的定义：同一操作作用于不同的对象，可以有不同的解释，产生不同的执行结果。
// 有两种类型的多态性：
// (1) 编译时的多态性。编译时的多态性是通过重载来实现的。 
// 	对于非虚的成员来说，系统在编译时，根据传递的参数、返回的类型等信息决定实现何种操作。

// (2) 运行时的多态性。运行时的多态性就是指直到系统运行时 ，才根据实际情况决定实现何种操作。
// 	C++中，运行时的多态性通过虚成员实现。

// class Person
// {
// public:
// 	virtual void print() { cout << "I'm a Person" << endl; cout << this << endl; }
// };
// class Chinese : public Person
// {
// public:
// 	virtual void print() { cout << "I'm a China." << endl; cout << this << endl; }
// };
// class American : public Person
// {
// public:
// 	virtual void print() { cout << "I'm a USA." << endl; cout << this << endl; }
// };

// void printPerson(Person &person)
// {
// 	person.print();
// }

// int main(int argc, char const *argv[])
// {
// 	Person p;
// 	Chinese c;
// 	American a;
// 	printPerson(p);
// 	printPerson(c);
// 	printPerson(a);

// 	return 0;
// }

/***************/
/* Interview 5 */
/***************/
// 私有继承和组合的相同点与不同点
// 1. 如果在组合中需要使用一个对象的某些方法，则完全可以利用私有继承代替。
// 2. 私有继承下派生类会获得基类的一份备份，同时得到了访问基类的公共以及保护接口的权力和重写基类虚函数的能力。
// 它是组合的一种语法上的变形（聚合或者“有一个”）。

/*“汽车有一个（Has-A）引擎”用单一组合表示，也可以用私有继承表示。*/
// class Engine
// {
// public:
// 	Engine(int num) : numCylinders(num) {}	// Engine 构造函数
// 	void start()
// 	{
// 		cout << "Engine start, " << numCylinders << " Cylinders" << endl;
// 	}
// private:
// 	int numCylinders;
// };

/** Car_pri 和类 Car_comp 有很多相似点
* (1) 它们都只有一个 Engine 被确切地包含于 Car 中。
* (2) 它们在外部都不能进行指针转换，如将 Car_pri * 转换为 Engine *。
* (3) 它们都有一个start()方法，并且都在包含的 Engine 对象中调用 start() 方法。
**/

/* 区别
* (1) 如果想让每个 Car 都包含若干 Engine，那么只能用单一组合的形式。
* (2) 私有继承形式可能引入不必要的多重继承。
* (3) 私有继承形式允许 Car 的成员将 Car* 转换成 Engine*。
* (4) 私有继承形式允许访问基类的保护（protected）成员。
* (5) 私有继承形式允许 Car 重写 Engine 的虚函数。
*/

// class Car_pri : private Engine	// 私有继承
// {
// public:
// 	Car_pri() : Engine(8) {}	// 调用基类的构造函数
// 	void start()
// 	{
// 		Engine::start();		// 调用基类的 start()
// 	}
// };

// class Car_comp
// {
// private:
// 	Engine engine;				// 组合 Engine 类对象
// public:
// 	Car_comp() : engine(8) {}	// 给 engine 成员初始化
// 	void start()
// 	{
// 		engine.start();			// 调用 engine 的 start()
// 	}
// };

// int main(int argc, char const *argv[])
// {
// 	Car_pri car_pri;
// 	Car_comp car_comp;

// 	car_pri.start();
// 	car_comp.start();

// 	return 0;
// }

// 原则：尽可能使用组合，万不得已才用私有继承。

// 组合的对象关系中不能使用一个抽象类，抽象类不能被实例化。
// struct Base						// 抽象
// {
// public:
// 	virtual void Func1() = 0;	// 纯虚函数
// 	virtual void Func2() = 0;	// 纯虚函数
// 	void print()
// 	{
// 		Func1();
// 		Func2();
// 	}
// };

// struct T : private Base
// {
// public:
// 	virtual void Func1() { cout << "Func1" << endl; }	// 覆盖基类的 Fun1
// 	virtual void Func2() { cout << "Func2" << endl; }	// 覆盖基类的 Fun2
// 	void UseFunc()
// 	{
// 		Base::print();	// 调用基类的 print()
// 	}
// };

// int main(int argc, char const *argv[])
// {
// 	T t;
// 	t.UseFunc();

// 	return 0;
// }

/***************/
/* Interview 4 */
/***************/
// 私有继承的作用
// 私有继承时派生类与基类不是“is a”关系，而是“Is-Implement-In-Terms-Of”（以...实现）。
// 如果使类D私有继承于类B，这样做是因为你想利用类B中已经存在的某些代码，而不是因为类B的对象和类D的对象之间有什么概念上的关系。
// 因此，私有继承在软件“设计”过程中毫无意义，只是在软件“实现”时才有用。

// class Person
// {
// public:
// 	void eat() { cout << "Person eat" << endl; }
// };

// class Student : private Person	// 私有继承
// {
// public:
// 	void study() { cout << "Student Study" << endl; }
// };

// int main(int argc, char const *argv[])
// {
// 	Person p;
// 	Student s;

// 	p.eat();
// 	s.study();
// 	// s.eat();		// rule 1
// 	// p = s;			// rule 2

// 	return 0;
// }

// rule 1: 和公有继承相反，如果两个类之间的关系是私有，编译器 一般不会将派生类对象转换成基类对象。
// rule 2: 从私有基类继承而来的成员都成为了派生类的私有成员—— 即使它们在基类中是保护或公有成员。

/***************/
/* Interview 3 */
/***************/
// C++ 继承关系
// Find Error
// class Base
// {
// // private:
// 	// int i;
// public:
// 	int i;
// 	Base(int x) { i = x; }
// };

// class derived: public Base
// {
// private:
// 	int i;
// public:
// 	// derived(int x, int y) { i = x; } 		// 没有指明构造方法，默认调用 Base 不带参的构造方法。
// 	derived(int x, int y) : Base(y) { i = x; }	// 因为 Base 类中已经定义了一个带参的构造函数，所以编译器报错：找不到构造方法。
// 	void printTotal()
// 	{
// 		int total = i + Base::i;				// 改为 public 继承
// 		cout << "total = " << total << endl;
// 	}
// };

// int main(int argc, char const *argv[])
// {
// 	derived d(1, 2);
// 	d.printTotal();

// 	return 0;
// }

/***************/
/* Interview 2 */
/***************/
// C++ 继承关系
// 考虑标记的语句编译时可能出现的状况
// class Parent
// {
// public:
// 	Parent(int var = -1)
// 	{
// 		m_nPub = var;
// 		m_nPtd = var;
// 		m_nPrt = var;
// 	}
// public:
// 	int m_nPub;
// protected:
// 	int m_nPtd;
// private:
// 	int m_nPrt;
// };

// class Child1 : public Parent
// {
// public:
// 	int getPub() {return m_nPub;}
// 	int getPtd() {return m_nPtd;}
// 	// int getPrt() {return m_nPrt;}	// A: F  m_nPrt 是基类 Parent 的私有变量
// };

// class Child2 : protected Parent
// {
// public:
// 	int getPub() {return m_nPub;}
// 	int getPtd() {return m_nPtd;}
// 	// int getPrt() {return m_nPrt;}	// B: F  m_nPrt 是基类 Parent 的私有变量
// };

// class Child3 : private Parent
// {
// public:
// 	int getPub() {return m_nPub;}
// 	int getPtd() {return m_nPtd;}
// 	// int getPrt() {return m_nPrt;}	// C: F  m_nPrt 是基类 Parent 的私有变量
// };

// int main(int argc, char const *argv[])
// {
// 	Child1 cd1;
// 	Child2 cd2;
// 	Child3 cd3;

// 	int nVar = 0;

// 	cd1.m_nPub = nVar;				// D
// 	// cd1.m_nPtd = nVar;				// E: protected 继承，只能在Child1类内部访问，不能使用Child1对象访问。
// 	nVar = cd1.getPtd();			// F

// 	// cd2.m_nPub = nVar;				// G: protected 继承，只能在Child2类内部访问，不能使用Child2对象访问。
// 	nVar = cd2.getPtd();			// H

// 	// cd3.m_nPub = nVar;				// I: private 继承，只能在Child3类内部访问，不能使用Child3对象访问。
// 	nVar = cd3.getPtd();			// J


// 	return 0;
// }

/***************/
/* Interview 1 */
/***************/
// C++类继承的三种关系
// public, protected, private

// (1) public 继承
// 	a. public 继承是一种接口继承。
// 	b. 子类可以代替父类完成父类接口所声明的行为。
// 	c. 子类可以自动转换成为父类的接口，完成接口转换。
// 	d. public 继承会保留父类中成员的可见性不变。
// 	e. 父类中某个函数是public的，那么在被子类继承后仍然是public。

// (2) protected 继承
// 	a. protected 继承是一种实现继承。
// 	b. 子类不能代替父类完成父类接口所声明的行为。
// 	c. 子类不可以自动转换成为父类的接口。
// 	d. protected 继承会将父类中的 public 可见性的成员修改为 protected 可见性。
// 	e. 相当于在子类中引入了 protected 成员，子类中可以调用父类的 protected 和 public 成员，
// 	f. 子类的子类也就可以调用被 protected 继承的父类的 protected 和 public 成员。

// (3) private 继承
// 	a. private 继承是一种实现继承。
// 	b. 子类不能代替父类完成父类接口所声明的行为。
// 	c. 子类不可以自动转换成为父类的接口。
// 	d. private 继承会将父类中的 public 可见性的成员修改为 private 可见性。
// 	e. 子类可以调用父类的 protected 和 public 成员。
// 	f. 子类的子类就不可以再调用被 private 继承的父类的成员了。

// class Base
// {
// protected:
// 	void printProtected() {
// 		cout << "print Protected" << endl;
// 	}
// public:
// 	void printPublic() {
// 		cout << "print Public" << endl;
// 	}
// private:
// 	void printPrivate() {
// 		cout << "print Private" << endl;
// 	}
// };

// class Derived1 : public Base {}; // public inheritance

// class Derived2 : protected Base {}; // protected inheritance

// class Derived3 : private Base {}; // private inheritance

// class A : public Derived1
// {
// public:
// 	void print()
// 	{
// 		printProtected();
// 		printPublic();
// 		// printPrivate();			// maybe error
// 	}
// };

// class B : public Derived2
// {
// public:
// 	void print()
// 	{
// 		printProtected();
// 		printPublic();
// 		// printPrivate();			// maybe error
// 	}
// };

// class C : public Derived3
// {
// public:
// 	void print()
// 	{
// 		// printProtected();		// maybe error
// 		// printPublic();			// maybe error
// 		// printPrivate();			// maybe error
// 	}
// };


// int main(int argc, char const *argv[])
// {
// 	class A a;
// 	class B b;
// 	class C c;
// 	a.print();
// 	b.print();
// 	c.print();

// 	return 0;
// }