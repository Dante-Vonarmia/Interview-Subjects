#include "iostream"
#include "stdio.h"
#include "string.h"
using namespace std;

// Adjust the lastest letter to the first address in the string.
// int main(int argc, char const *argv[])
// {
// 	char str[80]="fawuieoxc", *p, *q, max;
// 	p = str;
// 	// gets(p);
// 	max = *(p++);
// 	while (*p != '\0')
// 	{
// 		if (max < *p)
// 		{
// 			max = *p;
// 			q = p;
// 		}
// 		p++;
// 		puts(p);
// 	}
// 	p = q;
// 	puts(p);
// 	while (p > str)
// 	{
// 		*p = *(p - 1);
// 		p--;
// 		puts(p);
// 	}
// 	*p = max;
// 	puts(p);
// 	return 0;
// }

// Find the key works in the string and count how many times it shows up.
// int count(char *str, char *substr)
// {
// 	int i,j,k, num = 0;
// 	for (i = 0; str[i] != '\0'; ++i)
// 	{
// 		for (j = i, k = 0; substr[k] == str[j]; ++k, ++j)
// 		{
// 			if (substr[k+1] == '\0')
// 			{
// 				num++;
// 				break;
// 			}
// 		}
// 	}
// 	return(num);
// }
// int main(int argc, char const *argv[])
// {
// 	char str[80]={}, substr[80]={};
// 	int n;
// 	gets(str);
// 	gets(substr);
// 	cout << count(str, substr) << endl;
// 	return 0;
// }

// Turn strings into integer. 

// int chnum(const char *p)
// {
// 	int num = 0, k, len, j;
// 	len = strlen(p);
// 	for (; len != 0; ++p)
// 	{
// 		k = *p - '0';
// 		j = (--len);
// 		while (j-- > 0)
// 		{
// 			k = k * 10;
// 		}
// 		num = num + k;
// 	}
// 	return(num);
// }
// int main(int argc, char const *argv[])
// {
// 	char s[6] = {'1','2','3','4','5'};
// 	int n = 0;

// 	if (*s == '-')
// 	{
// 		n = -chnum(s+1);
// 	}
// 	else 
// 	{
// 		n = chnum(s);
// 	}
// 	cout << n+1 << endl;
// 	return 0;
// }