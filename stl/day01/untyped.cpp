#include <iostream>
using namespace std;
#define max(x, y) ((x) > (y) ? (x) : (y))
int main (void) {
  cout << max (100, 200) << endl;
  cout << max (1.23, 4.56) << endl;
  cout << max ("hello", "world") << endl;
  return 0;
}
