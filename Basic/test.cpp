#include "iostream"
#include "stdlib.h"
#include "cstring"
#include "string.h"
using namespace std;

int main(int argc, char const *argv[])
{

	char str1[10] = "12345";
	char str2[20] = "1234567890";
	strncat(str2, str1, 5);
	strncpy(str2, str1, 5);
	strstr(str2, str1);
	strcmp(str2, str1);

	return 0;
}