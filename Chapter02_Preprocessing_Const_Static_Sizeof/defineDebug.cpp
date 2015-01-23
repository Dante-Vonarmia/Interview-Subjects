#include "iostream"
#include "stdio.h"
#include "stdlib.h"
using namespace std;

#define DEBUG
int main(int argc, char const *argv[])
{
	int i = 0;
	char c;

	while(1) {
		i++;
		c = getchar();
		if (c != '\n')
		{
			getchar();
		}
		if (c == 'q' || c == 'Q') {
#ifdef DEBUG
			cout << "We got: " << c << ", about to exit." << endl;
#endif
			break;
		}
		else {
			cout << "i = " << i << endl;
		}
#ifdef DEBUG
			cout << ", we got: " << c << endl;
#endif
	}
	return 0;
}