// 函数指针 & 指针函数
// 返回类型标识符 *返回名称(形式参数表) {函数体}

#include "iostream"
#include "string"
using namespace std;

int max(int x, int y) {
	return (x > y ? x : y);
};

float *find(float *p, int x) {
	return p + x;
}

int main(int argc, char const *argv[])
{
	float score[] = {10, 20, 30, 40};
	int (*p)(int, int);
	float *q = find(score + 1, 1);
	int a;

	p = max;
	a = (*p)(1, 2);

	cout << "a = " << a << endl;
	cout << "*q = " << *q << endl;

	return 0;
}