#include <iostream>
#include <typeinfo>
using namespace std;
template<typename T1 = float, typename T2 = char,
  int T3 = 1000>
class A {
public:
  static void printType (void) {
    cout << typeid (T1).name () << ' '
      << typeid (T2).name () << ' '
      << T3 << endl;
  }
};
template<typename T1, typename T2 = T1>
class B {
public:
  static void printType (void) {
    cout << typeid (T1).name () << ' '
      << typeid (T2).name () << endl;
  }
};
/*
template<typename T1, typename T2 = int>
void foo (T1 x, T2 y) {}
*/
int main (void) {
  A<string, double, 123>::printType ();
  A<string, double>::printType ();
  A<string>::printType ();
  A<>::printType ();
  B<int, double>::printType ();
  B<short>::printType ();
//foo<int, int> (1, 2);
//foo<int> (1, 0.2);
  return 0;
}
