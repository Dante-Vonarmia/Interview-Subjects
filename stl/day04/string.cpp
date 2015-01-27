#include <iostream>
using namespace std;
int main (void) {
  string s1 = "abcdefghijklmn";
  string s2 = s1.substr (3, 6);
  cout << s2 << endl;
  string s3 = s1.substr (3);
  cout << s3 << endl;
  string s4 (s1, 3, 6);
  cout << s4 << endl;
  string s5 (s1, 3);
  cout << s5 << endl;
  return 0;
}
