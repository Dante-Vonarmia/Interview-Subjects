#include <iostream>
#include <vector>
using namespace std;
template<typename T>
void foo (void) {
  T t = T ();
  return 0;
}
int main (void) {
  vector<int> vi;
  vi.push_back (10);
  vector<int>::iterator it = vi.begin ();
  cout << *it << endl; // 10
  vi.push_back (20);
  it = vi.begin ();
  cout << *it << endl; // 10
  it = vi.end () - 1;
  it = vi.insert (it, 15);
  cout << *it << endl;
  it = vi.erase (it);
  cout << *it << endl;
  string s = string ();
  int i = int ();
  cout << i << endl;
  return 0;
}
