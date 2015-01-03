#include "iostream"
#include "String.h"
// #include "String.cpp"

int main(int argc, char const *argv[])
{
	String str(3, 'a');							// 普通构造函数
	String str1(str);							// 复制构造函数
	String str2("asdf");						// 普通构造函数
	String str3;								// 默认构造函数

	cout << " str: " << str << endl;
	cout << "str1: " << str1 << endl;
	cout << "str2: " << str2 << endl;
	cout << "str3: " << str3 << endl;

	str3 = str2;								// 赋值函数
	cout << "str3: " << str3 << endl;
	str3 = "abc123";							// 赋值函数
	cout << "str3: " << str3 << endl;

	cout << "str3[2] = " << str3[2] << endl;	// [] 重载

	str3 += "111";								// += 重载
	cout << "str3: " << str3 << endl;
	str3 += str1;								// += 重载
	cout << "str3: " << str3 << endl;

	cin >> str1;								// >> 重载
	cout << "str1: " << str1 << endl;

	String t1 = "1234";
	String t2 = "1234";
	String t3 = "12345";
	String t4 = "12335";

	cout << "t1 == t2 ? " << (t1 == t2) << endl;	// == 重载
	cout << "t2 < t3 ? " << (t1 < t3) << endl;		// <  重载
	cout << "t1 > t4 ? " << (t1 > t4) << endl;		// >  重载
	cout << "t3 != t4 ? " << (t1 != t4) << endl;	// != 重载

	return 0;
}