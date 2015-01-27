#include <iostream>
#include <typeinfo>
using namespace std;
// 通用模板
template<typename T1, typename T2>
class Dual {
public:
  Dual (void) {
    cout << "Dual<T1,T2>" << endl;
  }
};
// 局部特化
template<typename T1>
class Dual<T1, int> {
public:
  Dual (void) {
    cout << "Dual<T1,int>" << endl;
  }
};
// 完全特化
template<>
class Dual<int, int> {
public:
  Dual (void) {
    cout << "Dual<int,int>" << endl;
  }
};
template<typename T1, typename T2, typename T3>
class Trio {
public:
  Trio (void) {
    cout << "Trio<T1,T2,T3>" << endl;
  }
};
template<typename T1, typename T2>
class Trio<T1, T2, T2> {
public:
  Trio (void) {
    cout << "Trio<T1,T2,T2>" << endl;
  }
};
template<typename T1>
class Trio<T1, T1*, T1*> {
public:
  Trio (void) {
    cout << "Trio<T1,T1*,T1*>" << endl;
  }
};
template<typename T>
class Feeb {
public:
  Feeb (void) {
    cout << "Feeb<T>" << endl;
  }
};
template<typename T>
class Feeb<T*> {
public:
  Feeb (void) {
    cout << "Feeb<T*>" << endl;
  }
};
template<typename T>
class Feeb<T[]> {
public:
  Feeb (void) {
    cout << "Feeb<T[]>" << endl;
  }
};
template<typename T1, typename T2>
class Dummy {
public:
  static void printType (void) {
    cout << "1：" << typeid (T1).name () << ' '
      << typeid (T2).name () << endl;
  }
};
template<typename T1>
class Dummy<T1, T1> {
public:
  static void printType (void) {
    cout << "2：" << typeid (T1).name () << endl;
  }
};
template<typename T1, typename T2>
class Dummy<T1*, T2*> {
public:
  static void printType (void) {
    cout << "3：" << typeid (T1).name () << ' '
      << typeid (T2).name () << endl;
  }
};
template<typename T1>
class Dummy<T1*, T1*> {
public:
  static void printType (void) {
    cout << "4：" << typeid (T1).name () << endl;
  }
};
int main (void) {
  Dual<double, double> d1;
  Dual<double, int> d2;
  Dual<int, int> d3;
  Trio<char, short, long> t1;
  Trio<char, short, short> t2;
  Trio<char, char*, char*> t3;
  Feeb<int> f1;
  Feeb<int*> f2;
  Feeb<int[]> f3;
  Dummy<int, char>::printType ();
  Dummy<int, int>::printType ();
  Dummy<int*, char*>::printType ();
  Dummy<int*, char>::printType ();
  Dummy<int*, int*>::printType ();
  return 0;
}
