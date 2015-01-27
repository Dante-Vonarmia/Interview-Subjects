#include "iostream"
#include "string.h"
using namespace std;

void swap(char *&x, char *&y) { // 指针引用类型
	char *temp;
	temp = x;
	x = y;
	y = temp;
}
// void swap(char **x, char **y) { // 二维指针
// 	char *temp;
// 	temp = *x;
// 	*x = *y;
// 	*y = temp;
// }

int main() {
	char const *ap = "hello";
	char const *bp = "how are you?";

	cout << "ap:" << ap << endl; // hello
	cout << "bp:" << bp << endl; // how are you?

	swap(ap, bp); // 1
	// swap(&ap, &bp); // 2

	cout << "swap ap, bp" << endl;
	cout << "ap:" << ap << endl; // how are you? 
	cout << "bp:" << bp << endl; // hello 

	return 0;
}