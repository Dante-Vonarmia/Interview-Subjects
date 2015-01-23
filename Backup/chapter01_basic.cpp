#include "iostream"
#include "stdio.h"
#include "iomanip"
using namespace std;
/* Interview 12 */ 
// #include "stdlib.h"
// int atexit(void (*)(void));
// void fn1(void);
// void fn2(void);

// int main(int argc, char const *argv[])
// {
// 	atexit(fn1);
// 	atexit(fn2);
// 	cout << "main exit..." << endl;
// 	return 0;
// }

// void fn1()
// {
// 	cout << "calling fn1()..." << endl;
// }
// void fn2()
// {
// 	cout << "calling fn2()..." << endl;
// }

/* Interview 11 */ 
// The difference between <> and "".

/*Interview 10*/
// #ifndef __INCvxWorksh
// #define __INCvxWorksh
// #ifndef __cplusplus // c++ compiler
// #ifndef __STDC__ // c compiler
// extern "C" {
// #endif
// /*...*/
// #ifndef __cplusplus
// }
// #endif
// #endif /* __INCvxWorksh */

/*Interview 9*/
// c++ object oriented programming / c procedure orientd programming

/*Interview 8*/
// The difference between c and c++.

/*Interview 7*/
// void swap1(int& a, int& b) {
// 	int temp = a;
// 	a = b;
// 	b = temp;
// }
// void swap2(int& a, int& b) {
// 	a = a + b;
// 	b = b - a;
// 	a = a - b;
// }
// void swap3(int& a, int& b) {
// 	a ^= b;
// 	b ^= a;
// 	a ^= b;
// }
// int main(int argc, char const *argv[])
// {
// 	int a1 = 1, b1 = 2;
// 	int a2 = 3, b2 = 4;
// 	int a3 = 5, b3 = 6;
// 	int a = 2147483647, b = 1;

// 	swap1(a1, b1);
// 	swap2(a2, b2);
// 	swap3(a3, b3);

// 	cout << setw(2) << a1 << " " << setw(2) << b1 << endl;
// 	cout << setw(2) << a2 << " " << setw(2) << b2 << endl;
// 	cout << setw(2) << a3 << " " << setw(2) << b3 << endl;

// 	swap2(a, b);
// 	cout << setw(2) << a << " " << setw(2) << b << endl; // ERROR: Overflow!!

// 	return 0;
// }

/*Interview 6*/
// char getChar(int x, int y) {
// 	char c;
// 	unsigned  int a = x;
// 	(a + y > 10) ? (c = 1):(c = 2);
// 	return c;
// }

// int main () {
// 	char c1 = getChar(7, 4);
// 	char c2 = getChar(7, 3);
// 	char c3 = getChar(7, -7);
// 	char c4 = getChar(7, -8);

// 	printf("c1 = %d\n", c1);
// 	printf("c2 = %d\n", c2);
// 	printf("c3 = %d\n", c3);
// 	printf("c4 = %d\n", c4);

// 	return 0;
// }

/*Interview 5*/
//////////////////
// int p* = NULL;
// if (p == 0)
// if (p != 0)
// // better
// if (p == NULL)
// if (p != NULL)
//////////////////

//////////////////
// if (x == 0.0)
// if (x != 0.0)
// // better
// if ((x >= -EPSINON) && (x <= EPSINON))
// if ((x < -EPSINON) && (x > EPSINON))
//////////////////


//////////////////
// if (value)
// if (!value)	
// // better
// if (value == 0)
// if (value != 0)
//////////////////

//////////////////
// if (flag == TRUE)
// if (flag == FALSE)
// // better
// if (flag)
// if (!flag)
//////////////////

/*Interview 4*/
// // g++ -S interview.cpp
// int main(int argc, char const *argv[])
// {
// 	int i = 0;
// 	int x = 0;

// 	i++;
// 	++i;
// 	x = i++;
// 	x = ++i;
// 	return 0;
// }

/*Interview 3*/
// int main(int argc, char const *argv[])
// {
// 	int i = 8;

// 	printf("%d\n", ++i);
// 	printf("%d\n", --i);
// 	printf("%d\n", i++);
// 	printf("%d\n", i--);
// 	printf("%d\n", -i++);
// 	printf("%d\n", -i--);
// 	return 0;
// }

/*Interview 2*/
// int value = 0;
// void printValue() {
// 	printf("value = %d\n", value);
// };
// int main(int argc, char const *argv[])
// {
// 	value = 1;//局部变量
// 	printf("value = %d\n", value); //1

// 	::value = 2; //全局变量
// 	printValue(); //2
// 	return 0;
// }


/*Interview 1*/
// int main(int argc, char const *argv[])
// {
// 	int x = 3, y, z;
// 	x *= (y = z = 4);
// 	printf("x = %d\n", x); //12
// 	z = 2;

// 	x = (y = z); printf("x = %d\n", x);//2
// 	x = (y == z); printf("x = %d\n", x);//1
// 	x = (y & z); printf("x = %d\n", x);//2
// 	x = (y && z); printf("x = %d\n", x);//1

// 	y = 4;
// 	x = (y | z); printf("x = %d\n", x);//6
// 	x = (y || z); printf("x = %d\n", x);//1

// 	x = (y == z)? 4:5;
// 	printf("x = %d\n", x);//5
// 	x = (y == z)? 1:(y < z) ? 2:3;
// 	printf("x = %d\n", x);//3
// 	return 0;
// }