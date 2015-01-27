#include "stdio.h"

/****************/
/* Interview 16 */
/****************/
处理器字长
unsigned int zero = 0;
unsigned int compzero = 0xFFFF;
/*1's complement of zero*/

对于一个 int 型不是 16 位的处理器来说，上面的代码是不正确的。修改如下：
unsigned int compzero = ~0;

/****************/
/* Interview 15 */
/****************/
判断处理器是大端（Big_endian）还是小端（Little_endian）
编写一个函数，若处理器是 Big_endian的，则返回 0；
若是Little_endian的，则返回 1；

int checkCPU()
{
	// union 的存放顺序是所有成员都从低地址开始存放。
	union w
	{
		int a;
		char b;
	} c;
	c.a = 1;
	return (c.b == 1);
}

/****************/
/* Interview 14 */
/****************/
关键词 volatile 作用理解
一个定义为 volatile 的变量是说这变量可能会被意想不到地改变，这样，编译器就不会去假设这个变量的值了。
精确地说，就是优化器在用到这个变量时必须每次都小心地重新读取这个变量的值，而不是使用保存在寄存器里的备份。
(1)	并行设备的硬件寄存器（如状态寄存器）；
(2)	一个中断服务子程序中会访问到的非自动变量（Non-automatic variables）；
(3)	多线程应用中被几个任务共享的变量。

/****************/
/* Interview 13 */
/****************/
关键词 static 作用理解
(1)	在函数体内，一个被声明为静态都变量在这一函数被调用都过程中维持其值不变。
(2)	在模块内（但在函数体外），一个被声明为静态的变量可以被模块内所有函数访问，但不能被模块外其他函数访问。它是一个本地全局变量。
(3)	在模块内，一个被声明为静态的函数只可被这一模块内的其他函数调用。这个函数被限制在声明它模块的本地范围使用。

/****************/
/* Interview 12 */
/****************/
整数对自动转换
void foo(void)
{
	unsigned int a = 6;
	int b = -20;
	if (a + b > 6)
	{
		puts("> 6");
	}
	else
	{
		puts("<= 6");
	}
}

当表达式中存在有符号类型和无符号类型，所有操作数都自动转换为无符号类型。
答案： "> 6"。

/****************/
/* Interview 11 */
/****************/
// 对中断服务代码对评论
// 略

/****************/
/* Interview 10 */
/****************/
如何访问特定位置到内存
在某工程中，要求设置一绝对地址位 0x67a9 的整型变量的值为 0xaa66。编译器是一个纯粹的 ANSI 编译器。

int *ptr;
ptr = (int *)0x67a9;
*ptr = 0xaa66;
/*or*/
*(int * const)(0x67a9) = 0xaa66;

/***************/
/* Interview 9 */
/***************/
如何用 C 语言编写死循环

(1) common way
while(1) {}

(2) Not recommanded
for (;;) {}

(3) compiler programmer
Loop:
//...
goto Loop;

/***************/
/* Interview 8 */
/***************/
用 #define 声明一个常数
1 年有多少秒？

#ifndef SECONDS_PER_YEAR
#define SECONDS_PER_YEAR (60 * 60 * 24 * 365)UL
#endif

考点：
(1)	#define 语法的基本知识（例如，不能以分号结束，括号的使用，等等）；
(2)	懂得预处理器将为你计算常数表达式的值，因此，直接写出你是如何计算 1 年中有多少秒而不是计算出实际的值；
(3)	意识到这个表达式将使一个 16 位机到整型数溢出，因此要用到长整型符号L，告诉编译器这个常数是长整型数；
(4)	如果值表达式中用到UL（无符号长整型），说明有良好编写习惯。

/***************/
/* Interview 7 */
/***************/
列举并解释 C++ 中的 4 种运算符转化以及它们的不同点
(1)	const_cast
	将限制为 const 成员函数的 const 定义解除。

(2)	dynamic_cast
	若启动了支持运行时间类型信息（RTTI），可以有助于判断在运行时所指向对象的确切类型。
	与 typeid 运算符有关，可以将一个基类的指针指向许多不同的子类型（派生类），然后将被转型为基础类的对象还原成原来的类。

(3)	reinterpret_cast
	将一个指针转换成其他类型的指针，新类型的指针与旧指针可以毫不相干。通常用于某些非标准的指针数据类型转换。

(4)	static_cast
	在相关的对象和指针类型之间进行类型转换。
	有关的类之间必须通过继承、构造函数或者转换函数发生联系。
	static_cast 操作符还能在数字（原始的）类型之间进行类型转换。
	用于将数域宽度大的类型转换为较小的类型，同时有效的禁止编译器发出警告。

/***************/
/* Interview 6 */
/***************/
// 略

/***************/
/* Interview 5 */
/***************/
正确使用位运算符和逻辑运算符
The function need set corresponding bit into 0
#ifndef BIT_MASK
#define BIT_MASK(bit_pos) (0x01 << (bit_pos))			// 位掩码定义，需要置 0 的位是 1
#endif

int Bit_Reset(unsigned int* val, unsigned char pos)		// 把相应的位 置 0
{
	if (pos >= sizeof(unsigned int) * 8)				// 判断 pos，如果超出字节范围。
	{
		return 0;										// 则返回 0 失败
	}
	val = (val & ~BIT_MASK(pos));						// 将 val 的 pos 位 置 0
	return 1;
}

/***************/
/* Interview 4 */
/***************/
考查：各种位操作符的使用
计算一个字节里有多少 bit 被置 1.

#ifndef BIT7
#define BIT7 (0x1 << 7)					// 最高位置成 1
#endif
int calculate(unsigned char c)
{
	int count = 0;
	int i = 0;
	unsigned char comp = BIT7;

	for (i = 0; i < sizeof(c) * 8; ++i)
	{
		if ((c & comp) != 0)			// 判断每个位是否被置为 1
		{
			count++;
		}
		comp = comp >> 1;
	}
	return count;
}

int main(int argc, char const *argv[])
{
	unsigned char c = 0;
	// unsigned int c = 0;
	int count = 0;

	printf("c = ");
	scanf("%d", &c);

	count = calculate(c);
	printf("count = %d\n", count);
	return 0;
}

/***************/
/* Interview 3 */
/***************/
设置或清除特定到位
使用位操作符 & 和 |
问题：给定一个整型变量 a，写两段代码，第一个设置 a 的 bit 3，第二个清除 a 的 bit 3。以上两个操作中，要保持其他位不变。
解析：#defines 和 bit masks 操作。有极高可移植性的方法。
#ifndef BIT3
#define BIT3 (0x1 << 3)
#endif
static int a;

void set_bit3(void)
{
	a |= BIT3;		// 用来指定位置 1
}

void clear_bit3(void)
{
	a &= ~BIT3;		// 用来指定位置 0
}

/***************/
/* Interview 2 */
/***************/
使用操作符 >> 和 <<
左移操作符 << 相当于乘法操作， << n 相当于乘以 2n。
右移操作符 >> 相当于除法操作， >> n 相当于除以 2n。

int main(int argc, char const *argv[])
{
	unsigned short int i = 0;	// 无符号类型到大小范围：0～65535。内存数据为 0x0000
	unsigned char ii = 255;		// 范围：0~255，内存中到数据为 0xff。
	int j = 8, p, q;			

	p = j << 1;
	q = i >> 1;		
	i = i - 1;		// 0xffff, result: 65535
	ii = ii + 1;	// 0x00

	printf("i = %d\n", i);
	printf("ii = %d\n", ii);
	printf("p = %d\n", p);
	printf("q = %d\n", q);

	return 0;
}

/***************/
/* Interview 1 */
/***************/
位制转换

int main(int argc, char const *argv[])
{
	int i = 5.0l;
	float f = 5;

	printf("%f\n", 5);		// warning
	printf("%lf\n", 5.01);
	printf("%f\n", f);

	printf("%d\n", 5.0l);	// warning
	printf("%d\n", i);
	return 0;
}