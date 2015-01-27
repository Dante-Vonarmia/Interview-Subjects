#include "iostream"
#include "stdio.h"
#include "string.h"
using namespace std;

// convert integer into string.
// void convert(int n)
// {
// 	int i;
// 	if ((i = n / 10) != 0)
// 	{
// 		convert(i);
// 	}
// 	putchar(n % 10 + '0');
// }

// int main(int argc, char const *argv[])
// {
// 	int number = -123;
// 	// cin >> number;
// 	if (number < 0)
// 	{
// 		putchar('-');
// 		number *= -1;
// 	}
// 	convert(number);
// 	return 0;
// }

// Reverse the number.
// void cvt(char *a, int n)
// {
// 	int i;

// 	if((i = n/10) != 0)
// 	{
// 		cvt(a + 1, i);
// 	}
// 	*a = n % 10 + '0';
// }

// int main(int argc, char const *argv[])
// {
// 	int number = 123456;
// 	char str[10] = "";
// 	// cin >> number;
// 	cvt(str, number);
// 	puts(str);
// 	return 0;
// }

// Reverse the string.
// char rvs(char *a)
// {
// 	if (!*a)
// 	{
// 		return 0;
// 	}
// 	// cout << *a;
// 	rvs(a + 1);
// 	cout << *a;

// 	return 1;
// }

// int main(int argc, char const *argv[])
// {
// 	char s[10] = "hello!";
// 	rvs(s);
// 	cout << endl;
// 	return 0;
// }

// 使用C编写函数，实现字符串按单词反转，要求不使用任何系统函数，尽量不考虑额外的存储空间。
// 例如：输入Please give me much more money. 输出money more much me give please.

// int main(int argc, char const *argv[])
// {
// 	char const *str = "Please give me much more money";
// 	char strDest[50] = " ";
// 	int n = strlen(str), begin=0, end=0, base = 0;
// 	for (int i = 0; *(str+i)!='\0'; ++i)
// 	{
// 		*(strDest+i) = *(str+n-i-1);
// 	}
// 	strcat(strDest, " ");
// 	// cout << strDest << endl << endl;
// 	for (int j = 0; *(strDest+j)!='\0'; ++j)
// 	{
// 		// cout << "j: " << j << ", ele: " << *(strDest+j) << endl;
// 		if (*(strDest+j) == ' ')
// 		{
// 			// cout << "begin: " << begin << endl;
// 			end = j - begin - 1;
// 			// cout << "end(words number): " << end << endl;
// 			// cout << "j(index): " << j << endl;
// 			for (;*(strDest+begin) != ' '; ++begin)
// 			{
// 				// cout << "begin(words start): " << begin << endl;
// 				// cout << "end(words over): " << end + base << endl;
// 				cout << *(strDest + end + base);
// 				// *(strDest + begin)  ^= *(strDest + end + base);
// 				// *(strDest + end + base)  ^= *(strDest + begin);
// 				// *(strDest + begin)  ^= *(strDest + end + base);
// 				--end;
// 			}
// 			cout << " ";
// 			base = begin = j + 1;
// 			// cout << endl << "!!!SPACE!!!" << endl << endl;
// 			// cout << "Next begin: " << begin << endl;
// 		}
// 	}
// 	// cout << endl << strDest << endl;
// 	cout << endl;
// 	return 0;
// }

// 请写一个程序，对用户输入的字符串进行处理。处理要求，将用户输入的每个单词首字母都变成大写，其余字母为小写，同时单词之间只保留一个空格，并去除其他额外的字符。
// 例如：
// 用户输入：
// 	you and     me wHAt  cpp2005progr@@am
// 则程序输出：
// 	You And Me What Cpp Program

// int main(int argc, char const *argv[])
// {
	// char const *str = "#$#@$you a(*^nd^&^*(#$)    @33me wHAt  cpp2005progr@@am";
	// char strDest[31] = "";
// 	int j = 0;

// 	for (int i = 0; *(str+i) != '\0'; ++i)
// 	{
// 		if ((*(str+i) >= 'a' && *(str+i) <= 'z') || (*(str+i) >= 'A' && *(str+i) <= 'Z'))
// 		{
// 			*(strDest+j) = *(str+i);
// 			// cout << *(str + i) << i << endl;
// 			// cout << *(strDest+j) << j << endl;

// 			if (j == 0 && *(strDest+j) >= 'a' && *(strDest+j) <= 'z')
// 			{
// 				*(strDest+j) =  *(strDest+j) + 'A' - 'a';
// 			}

// 			else if (*(strDest+j) >= 'A' && *(strDest+j) <= 'Z')
// 			{
// 				*(strDest+j) = *(strDest+j) +  'a' - 'A';
// 			}

// 			else if ((*(str + i - 1) == ' '))
// 			{
// 				*(strDest + j + 1) = *(strDest + j) + 'A' - 'a';				
// 				*(strDest + j) = ' ';
// 				j++;
// 			}
// 			++j;
// 		}
// 		else if (*(str+i) >= '0' && *(str+i) <= '9')
// 		{
// 			*(strDest + j) = ' ';
// 			++j;
// 			if (*(strDest + j - 2) == ' ')
// 			{
// 				--j;
// 			}
// 		}
// 	}

// 	for (j = 0; *(strDest+j) != '\0'; ++j)
// 	{
// 		if (*(strDest+j) == ' ' && *(strDest+j+1) >= 'a' && *(strDest+j+1) <= 'z')
// 		{
// 			*(strDest + j + 1) = *(strDest + j + 1) + 'A'- 'a';
// 		}
// 		// cout << *(strDest+j);
// 	}
// 	cout << strDest << endl;
// 	return 0;
// }
