#include <iostream>
#include <cstdlib>
using namespace std;
template<typename T>
class A {
public:
  class X {};
  void foo (void) {}
  int m_a;
  void exit (int status) {
    cout << "88" << endl;
  }
};
template<typename T>
class B : public A<T> {
public:
  void bar (void) {
     // 在子模板中访问基模板的成员类型、成员函数、成员
     // 变量，需要使用作用域限定符
     typename A<T>::X x;
     A<T>::foo ();
     A<T>::m_a = 10;
     // 或者显式使用this指针
     this->foo ();
     this->m_a = 10;
     this->exit (0);
  }
};
int main (void) {
  B<int> b;
  b.bar ();
  return 0;
}
