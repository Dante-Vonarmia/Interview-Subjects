#include <vector>
#include <deque>
#include <algorithm>
#include <iterator>
#include <fstream>
#include "print.h"
template<typename IT1, typename IT2>
void mycopy (IT1 begin, IT1 end, IT2 dst) {
  while (begin != end)
    *(dst++) = *(begin++);
}
template<typename IT, typename OP>
void my_for_each (IT begin, IT end, OP op) {
  while (begin != end)
    op (*(begin++));
}
void square (int& x) {
  x *= x;
}
void output (int x) {
  cout << x << ' ';
}
int main (void) {
  int a[5] = {12, 23, 34, 55, 61};
  int b[5];
  mycopy (a, a + 5, b);
  print (b, b + 5);
  vector<int> v (5);
  mycopy (b, b + 5, v.begin ());
  print (v.begin (), v.end ());
  deque<int> d (5);
  mycopy (v.begin (), v.end (), d.begin ());
  print (d.begin (), d.end ());
  ofstream ofs ("o.dat");
  mycopy (d.begin (), d.end (),
    ostream_iterator<int> (ofs, " "));
  ofs.close ();
  int c[5];
  ifstream ifs ("o.dat");
  mycopy (istream_iterator<int> (ifs),
    istream_iterator<int> (), c);
  print (c, c + 5);
  ifs.close ();
  my_for_each (c, c + 5, square);
  my_for_each (c, c + 5, output);
  cout << endl;
  return 0;
}
