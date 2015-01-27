#include <iostream>
using namespace std;
#include "comp.h"
int main (void) {
  Comparator<int> ci (100, 200);
  cout << ci.max () << ' ' << ci.min () << endl;
  Comparator<double> cd (1.23, 4.56);
  cout << cd.max () << ' ' << cd.min () << endl;
  Comparator<string> cs ("hello", "world");
  cout << cs.max () << ' ' << cs.min () << endl;
  Comparator<const char*> cp ("hello", "world");
  cout << cp.max () << ' ' << cp.min () << endl;
  return 0;
}
