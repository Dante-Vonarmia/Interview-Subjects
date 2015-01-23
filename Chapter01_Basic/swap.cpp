#include "iostream"
#include "stdio.h"
#include "iomanip"
using namespace std;

void swap1(int& a, int& b) {
	int temp = a;			// 使用局部变量 temp 完成交换
	a = b;
	b = temp;
}
void swap2(int& a, int& b) {
	a = a + b;				// 使用加减运算完成交换
	b = b - a;
	a = a - b;
}
void swap3(int& a, int& b) {
	a ^= b;					// 使用异或运算完成交换
	b ^= a;
	a ^= b;
}
int main(int argc, char const *argv[])
{
	int a1 = 1, b1 = 2;
	int a2 = 3, b2 = 4;
	int a3 = 5, b3 = 6;
	int a0 = 2147483647, b0 = 1;

	swap1(a1, b1);
	swap2(a2, b2);
	swap3(a3, b3);

	cout << setw(2) << a1 << " " << setw(2) << b1 << endl;
	cout << setw(2) << a2 << " " << setw(2) << b2 << endl;
	cout << setw(2) << a3 << " " << setw(2) << b3 << endl;

	swap2(a, b);
	cout << setw(2) << a0 << " " << setw(2) << b0 << endl; // ERROR: Overflow!!

	return 0;
}
