#include "iostream"
using namespace std;

int main()
{
	const int x = 1;
	int b = 10;
	int c = 20;

	const int* a1 = &b;
	int* const a2 = &b;
	const int* const a3 = &b;

	// 常量
	// x = 2;	

	// 常指针
	a1 = &c;
	// *a1 = 1;

	// 常量
	// a2 = &c;
	*a2 = 1;

	// 都不能修改
	// a3 = &c;
	// *a3 = 1;
	return 0;
}