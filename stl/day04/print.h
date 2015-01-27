#ifndef _PRINT_H
#define _PRINT_H
#include <iostream>
using namespace std;
template<typename iterator>
void print (iterator begin, iterator end) {
  while (begin != end)
    cout << *(begin++) << ' ';
  cout << endl;
}
#endif // _PRINT_H
