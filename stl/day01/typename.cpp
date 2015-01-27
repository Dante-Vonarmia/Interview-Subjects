#include <iostream>
using namespace std;
class A {
public:
  typedef unsigned int UINT;
  struct Student {
    char name[256];
    int age;
  };
  class Teacher {
  public:
    float salary;
  };
};
template<typename T>
void foo (void) {
   typename T::UINT x;
   typename T::Student y;
   typename T::Teacher z;
}
int main (void) {
  foo<A> ();
  return 0;
}
