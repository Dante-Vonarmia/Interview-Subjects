#include <iostream>
#include <vector>
using namespace std;
template<typename T>
void print (const T& vec) {
  size_t size = vec.size ();
  cout << "大小：" << size << endl;
  cout << "内容：";
  for (size_t i = 0; i < size; ++i)
    cout << vec[i] << ' ';
  cout << endl;
}
void show (const vector<int>& vec) {
  for (vector<int>::const_iterator it = vec.begin ();
    it != vec.end (); ++it)
    cout << *it << ' ';
  cout << endl;
}
class A {
public:
  A (int i = 10) : m_i (i) {}
  operator const int& (void) const {
    return m_i;
  }
private:
  int m_i;
};
int main (void) {
  vector<int> v1;
  print (v1);
  vector<int> v2 (5);
  print (v2);
  vector<A> v3 (5);
  print (v3);
  vector<int> v4 (5, 18);
  print (v4);
  vector<A> v5 (5, 28);
  print (v5);
  int a[] = {12, 34, 55, 27, 33};
  vector<int> v6 (&a[0], &a[5]);
  print (v6);
  for (vector<int>::iterator it = v6.begin ();
    it != v6.end (); ++it)
    cout << *it << ' ';
  cout << endl;
  for (vector<int>::reverse_iterator it = v6.rbegin ();
    it != v6.rend (); ++it)
    cout << *it << ' ';
  cout << endl;
  show (v6);
  vector<int>::iterator it = v6.begin ();
  it += 2;
  cout << *it << endl;
  it = v6.end ();
  it = it - 3;
  cout << *it << endl;
  cout << v6.end () - v6.begin () << endl;
  cout << boolalpha << (v6.begin () > it) << endl;
  return 0;
}
