#include <iostream>
using namespace std;
#define MAX(T) \
T max_##T (T a, T b) { \
  return a > b ? a : b; \
}
MAX(int)
MAX(double)
MAX(string)
#define max(T) max_##T
int main (void) {
  cout << max(int) (100, 200) << endl;
  cout << max(double) (1.23, 4.56) << endl;
  cout << max(string) ("hello", "world") << endl;
  return 0;
}

