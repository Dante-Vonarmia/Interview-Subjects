#include "stdio.h"
#include "iostream"
#include "iomanip"
#include "string.h"
using namespace std;

// triangle sort
// #ifndef M
// #define M 10
// #endif
// #ifndef NUM
// #define NUM	(M + 1) * (M) / 2
// #endif

// int main(int argc, char const *argv[])
// {
// 	int a[NUM], *p[M], i, j, index, n;
// 	for (i = 0; i < M; ++i)
// 	{
// 		index = i * (i + 1) / 2;
// 		p[i] = &a[index];
// 	}
// 	for (i = 0; i < M; ++i)
// 	{
// 		n = 1;
// 		for (j = 0; j <= i; ++j)
// 		{
// 			p[i][j] = i * M + n;
// 			n++;
// 		}
// 	}
// 	cout << "The Output: " << endl;
// 	for (i = 0; i < M; ++i)
// 	{
// 		for (j = 0; j <= i; ++j)
// 		{
// 			cout << setw(4) << p[i][j];
// 		}
// 		cout << endl;
// 	}
// 	return 0;
// }

// palindromic string.
int main(int argc, char const *argv[])
{
	char s[81] = "abca", *p1, *p2;
	int n;
	gets(s);
	n = strlen(s);
	p1 = s;
	p2 = s + n - 1;
	while (p1 < p2)
	{
		if (*p1 != *p2)
		{
			break;
		}
		else
		{
			p1++;
			p2--;
		}
	}
	if (p1 < p2)
	{
		cout << "No" << endl;
	}
	else
	{
		cout << "Yes" << endl;
	} 
	return 0;
}

// ascent the string and delete the repeat one.
// int main(int argc, char const *argv[])
// {
// 	char string[100]="mfhfzs", *p, *q, *r;
// 	// gets(string);
// 	if (string != NULL && sizeof(string) > 2)
// 	{
// 		for (p = string; *p; ++p)
// 		{
// 			for ( q = r = p; *q; ++q)
// 			{
// 				cout << "q: " << q << endl;
// 				if (*r > *q)
// 				{
// 					r = q;
// 					cout << "r: " << r << endl;
// 				}
// 				if (r != p)
// 				{
// 					*r ^= *p;
// 					*p ^= *r;
// 					*r ^= *p;
// 				}
// 			}
// 		}
// 	// for(p = string; *p; p++)
// 	// {
// 	// 	for (q = p; *p == *q; q++);
// 	// 	strcpy(p + 1, q);
// 	// }
// 	}


// 	cout << string << endl;
// 	return 0;
// }