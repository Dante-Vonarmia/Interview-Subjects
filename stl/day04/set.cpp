#include <iostream>
#include <set>
using namespace std;
int main (void) {
  cout << "第一个字符串：" << flush;
  string str1;
  cin >> str1;
  set<char> set1;
  for (string::iterator it = str1.begin ();
    it != str1.end (); ++it)
    set1.insert (*it);
  cout << "第二个字符串：" << flush;
  string str2;
  cin >> str2;
  set<char> set2;
  for (string::iterator it = str2.begin ();
    it != str2.end (); ++it)
    set2.insert (*it);
  cout << "两串共有字符：" << flush;
  for (set<char>::iterator it = set1.begin ();
    it != set1.end (); ++it)
    if (! set2.insert (*it).second)
       cout << *it;
  cout << endl;
  return 0;
}
