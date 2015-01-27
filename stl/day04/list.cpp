#include <list>
#include <algorithm>
#include "print.h"
class CmpInt {
public:
  bool operator() (int a, int b) const {
    return a > b;
  }
};
int main (void) {
  list<int> li;
  li.push_back (10);
  li.push_back (20);
  li.push_back (30);
  li.push_back (20);
  li.push_back (40);
  li.push_back (20);
  li.push_back (50);
  li.push_back (20);
  print (li.begin (), li.end ());
  li.remove (20);
  print (li.begin (), li.end ());
  list<int>::iterator it = li.begin ();
  ++++it;
  li.insert (li.insert (it, 40), 40);
  li.push_back (40);
  li.push_back (40);
  print (li.begin (), li.end ());
  li.unique ();
  print (li.begin (), li.end ());
  list<int> l2;
  l2.push_back (10000);
  l2.push_back (20000);
  l2.push_back (30000);
  l2.push_back (40000);
  l2.push_back (50000);
  cout << "调用列表：";
  print (li.begin (), li.end ());
  cout << "参数列表：";
  print (l2.begin (), l2.end ());
  it = li.begin ();
  ++++it;
  /*
  li.splice (it, l2);
  *//*
  list<int>::iterator del = l2.begin ();
  ++++del;
  li.splice (it, l2, del);
  */
  list<int>::iterator begin = l2.begin (),
    end = l2.end ();
  ++begin;
  --end;
  li.splice (it, l2, begin, end);
  cout << "调用列表：";
  print (li.begin (), li.end ());
  cout << "参数列表：";
  print (l2.begin (), l2.end ());
//sort (li.begin (), li.end ());
  li.sort (CmpInt ());
  print (li.begin (), li.end ());
  list<int> l3;
  l3.push_back (12);
  l3.push_back (33);
  l3.push_back (37);
  l3.push_back (48);
  l3.push_back (63);
  l3.sort (CmpInt ());
  list<int> l4;
  l4.push_back (11);
  l4.push_back (35);
  l4.push_back (52);
  l4.sort (CmpInt ());
  cout << "调用列表：";
  print (l3.begin (), l3.end ());
  cout << "参数列表：";
  print (l4.begin (), l4.end ());
  l3.merge (l4, CmpInt ());
  cout << "调用列表：";
  print (l3.begin (), l3.end ());
  cout << "参数列表：";
  print (l4.begin (), l4.end ());
  return 0;
}
