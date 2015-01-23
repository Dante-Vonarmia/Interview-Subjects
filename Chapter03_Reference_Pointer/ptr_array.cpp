#include "iostream"
#include "string"
using namespace std;

// 指针数组&数组指针 区别
// 指针数组
// 一个数组里存放同一类型的指针
// int *p[19];
// 数组指针
// 一个指针，并且指向一个数组
// int *b = new int[10];

int main(int argc, char const *argv[])
{
	int x1[4] = {1, 2, 3 ,4};
	int x2[2] = {5, 6};
	int x3[3] = {7, 8, 9};
	int *a[2];
	int *b = x1;
	int i = 0;

	a[0] = x2;
	a[1] = x3;

	cout << "a[0]: ";
	for (int i = 0; i < sizeof(x2) / sizeof(int); ++i)
	{
		cout << a[0][i] << " "; // 5 6
	}
	cout << endl;
	
	cout << "a[1]: ";
	for (int i = 0; i < sizeof(x3) / sizeof(int); ++i)
	{
		cout << a[1][i] << " "; // 7 8 9
	}
	cout << endl;
	
	cout << "b: ";
	for (int i = 0; i < sizeof(x1) / sizeof(int); ++i)
	{
		cout << b[i] << " "; // 1 2 3 4
	}
	cout << endl;

	return 0;
}