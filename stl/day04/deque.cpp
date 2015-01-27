#include <deque>
#include <algorithm>
#include "print.h"
class CmpInt {
public:
  bool operator() (int a, int b) const {
    return a > b;
  }
};
int main (void) {
  deque<int> di;
  di.push_back (40);
  di.push_back (50);
  di.push_back (60);
  print (di.begin (), di.end ());
  di.push_front (30);
  di.push_front (20);
  di.push_front (10);
  print (di.begin (), di.end ());
  di.pop_back ();
  print (di.begin (), di.end ());
  di.pop_front ();
  print (di.begin (), di.end ());
  deque<int>::size_type size = di.size ();
  for (deque<int>::size_type i = 0; i < size; ++i)
    di[i] *= di[i];
  print (di.begin (), di.end ());
  deque<int>::iterator it = di.begin ();
  it += 2;
  cout << *it << endl;
  it = find (di.begin (), di.end (), 1600);
  if (it == di.end ())
    cout << "没找到！" << endl;
  else
    cout << "找到了：" << *it << endl;
  sort (di.begin (), di.end (), CmpInt ());
  print (di.begin (), di.end ());
  it = di.begin () + 1;
  di.insert (it, 2000);
  it = di.end () - 1;
  di.insert (it, 500);
  print (di.begin (), di.end ());
  di.erase (di.begin () + 2);
  print (di.begin (), di.end ());
  return 0;
}
