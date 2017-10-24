#include "iostream"
#include "iomanip"
using namespace std;

// CUBE 1

/*
	// 6 1 2 3 4 5 
	// 5 6 1 2 3 4 
	// 4 5 6 1 2 3 
	// 3 4 5 6 1 2 
	// 2 3 4 5 6 1 
	// 1 2 3 4 5 6
 */

// int main(int argc, char const *argv[])
// {
// 	int a[6]={1,2,3,4,5,6},i,j,k,m;
// 	for (i = 0; i < 6; ++i)
// 	{
// 		cin >> a[i];
// 	}
// 	for (i = 5; i >= 0; --i)
// 	{
// 		k = a[5];
// 		for (j = 4; j >= 0; j--)
// 		{
// 			a[j+1] = a[j];
// 		}
// 		a[0] = k;
// 		for (int m = 0; m < 6; ++m)
// 		{
// 			cout << setw(2) << a[m];
// 		}
// 		cout << endl;
// 	}

// 	return 0;
// }

// CUBE 2

/*
 	// 1 1 1 1 1 1 1 1 1
	// 1 2 2 2 2 2 2 2 1
	// 1 2 3 3 3 3 3 2 1
	// 1 2 3 4 4 4 3 2 1
	// 1 2 3 4 5 4 3 2 1
	// 1 2 3 4 4 4 3 2 1
	// 1 2 3 3 3 3 3 2 1
	// 1 2 2 2 2 2 2 2 1
	// 1 1 1 1 1 1 1 1 1
 */

// int main(int argc, char const *argv[])
// {
// 	int a[10][10]={}, n = 9, i = 0, j = 0, m;

// 	if (n % 2 == 0)
// 	{
// 		m = n / 2;
// 	}
// 	else
// 		m = n / 2 + 1;
// 	for (; i < m; ++i)
// 	{
// 		for (j = i; j < n-i; ++j)
// 		{
// 			a[i][j] = i + j;
// 			a[n-i-1][j] = i + j;
// 			a[j][i] = i + j;
// 			a[j][n-i-1] = i + j;

// 			a[i][j] = i + 1;
// 			a[n-i-1][j] = i + 1;
// 			a[j][i] = i + 1;
// 			a[j][n-i-1] = i + 1;
// 		}
// 	}

// 	for (i = 0; i < n; ++i)
// 	{
// 		for (j = 0; j < n; ++j)
// 		{
// 			cout << setw(2) << a[i][j];
// 		}
// 		cout << endl;
// 	}
// 	return 0;
// }

// CUBE 3
/*

	//  1  2  3  4  5  6  7  8  9
	// 32 33 34 35 36 37 38 39 10
	// 31 56 57 58 59 60 61 40 11
	// 30 55 72 73 74 75 62 41 12
	// 29 54 71 80 81 76 63 42 13
	// 28 53 70 79 78 77 64 43 14
	// 27 52 69 68 67 66 65 44 15
	// 26 51 50 49 48 47 46 45 16
	// 25 24 23 22 21 20 19 18 17

 */

// int main(int argc, char const *argv[])
// {
// 	int a[10][10] = {}, i, j, k = 0, m, n = 9;
// 	if (n%2 == 0)
// 	{
// 		m = n / 2;
// 	}
// 	else
// 	{
// 		m = n / 2 + 1;
// 	}
// 	for (i = 0; i < m; ++i)
// 	{
// 		for (j = i; j < n - i; ++j)
// 		{
// 			k++;
// 			a[i][j] = k;
// 		}
// 		for (j = i + 1; j < n - i; ++j)
// 		{
// 			k++;
// 			a[j][n-i-1] = k;
// 		}
// 		for (j = n - i - 2; j >= i; j--)
// 		{
// 			k++;
// 			a[n-i-1][j] = k;
// 		}
// 		for (j = n - i - 2; j >= i+1; j--)
// 		{
// 			k++;
// 			a[j][i] = k;
// 		}
// 	}
// 	for (i = 0; i < n; ++i)
// 	{
// 		for (j = 0; j < n; ++j)
// 			{
// 				cout << setw(3) << a[i][j];
// 			}	
// 		cout << endl;
// 	}
// 	return 0;
// }