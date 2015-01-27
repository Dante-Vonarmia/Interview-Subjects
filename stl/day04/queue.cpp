#include <iostream>
#include <queue>
#include <list>
using namespace std;
int main (void) {
  queue<string, list<string> > qs;
  qs.push ("今天");
  qs.push ("心情");
  qs.push ("不错");
  while (! qs.empty ()) {
    cout << qs.front ();
    qs.pop ();
  }
  cout << endl;
  return 0;
}
