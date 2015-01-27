#include <iostream>
#include <typeinfo>
using namespace std;
template<typename T>
class A {
public:
  virtual void foo (T const& data) {
    cout << "A::foo()：" << typeid (data).name()<<endl;
  }
  template<typename K>
  virtual void bar (void) {
    K k;
    cout << k << endl;
  }
};
template<typename T>
class B : public A<T> {
public:
  void foo (T const& data) {
    cout << "B::foo()：" << typeid (data).name()<<endl;
  }
};
int main (void) {
  B<int> b;
  A<int>& a = b;
  a.foo (1234);
  return 0;
}
