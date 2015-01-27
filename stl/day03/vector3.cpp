#include <iostream>
#include <vector>
using namespace std;
void print (vector<int> const& vec) {
  cout << "大小：" << vec.size () << endl;
  cout << "容量：" << vec.capacity () << endl;
  cout << "内容：";
  for (vector<int>::const_iterator it = vec.begin ();
    it != vec.end (); ++it)
    cout << *it << ' ';
  cout << endl;
}
int main (void) {
  vector<int> vi;
  print (vi);
  vi.push_back (1);
  print (vi);
  vi.push_back (2);
  print (vi);
  vi.push_back (3);
  print (vi);
  vi.push_back (4);
  print (vi);
  vi.push_back (5);
  print (vi);
  vi.resize (9);
  print (vi);
  vi[9] = 100;
  cout << vi[9] << endl;
  vi.push_back (200);
  cout << vi[9] << endl;
  vi.pop_back ();
  vi.pop_back ();
  vi.pop_back ();
  vi.erase (vi.erase (vi.erase (vi.begin ())));
  vi.clear ();
  vi.reserve (20);
  print (vi);
  string s1;
  cout << sizeof (s1) << endl;
  string s2 ("alkfj;alskfj;asklfja;sklfja;slfkja;s");
  cout << sizeof (s2) << endl;
  vector<string> vs;
  return 0;
}
