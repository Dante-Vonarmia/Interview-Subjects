#include <iostream>
#include <memory>
using namespace std;
class A {
public:
  A (void) : m_data (1234) {
    cout << "A构造" << endl;
  }
  ~A (void) {
    cout << "A析构" << endl;
  }
  void foo (void) {
    cout << "A::foo() " << m_data << endl;
  }
private:
  int m_data;
};
template<typename T>
class AutoPtr {
public:
  AutoPtr (T* p = NULL) : m_p (p) {}
  AutoPtr (AutoPtr<T>& that) : m_p (that.release ()) {}
  AutoPtr& operator= (AutoPtr<T>& that) {
    if (&that != this)
      reset (that.release ());
    return *this;
  }
  ~AutoPtr (void) {
    if (m_p) {
      delete m_p;
      m_p = NULL;
    }
  }
  T& operator* (void) const {
    return *m_p;
  }
  T* operator-> (void) const {
    return &**this;
//  return &(*(*this));
  }
private:
  T* release (void) {
    T* p = m_p;
    m_p = NULL;
    return p;
  }
  void reset (T* p) {
    if (p != m_p) {
      delete m_p;
      m_p = p;
    }
  }
  T* m_p;
};
template<typename T>
class AutoPtr<T[]> {
public:
  AutoPtr (T* p = NULL) : m_p (p) {}
  AutoPtr (AutoPtr<T>& that) : m_p (that.release ()) {}
  AutoPtr& operator= (AutoPtr<T>& that) {
    if (&that != this)
      reset (that.release ());
    return *this;
  }
  ~AutoPtr (void) {
    if (m_p) {
      delete[] m_p;
      m_p = NULL;
    }
  }
  T& operator* (void) const {
    return *m_p;
  }
  T* operator-> (void) const {
    return &**this;
  }
private:
  T* release (void) {
    T* p = m_p;
    m_p = NULL;
    return p;
  }
  void reset (T* p) {
    if (p != m_p) {
      delete[] m_p;
      m_p = p;
    }
  }
  T* m_p;
};
void bar (AutoPtr<A> p) {}
int main (void) {
  /*
  auto_ptr<A> a (new A[3]);
  */
  AutoPtr<A> a (new A);
  a->foo (); // a.operator->()->foo ();
  (*a).foo ();
  AutoPtr<A> b = a;
  b->foo ();
  (*b).foo ();
//a->foo ();
//(*a).foo ();
  bar (b);
//b->foo ();
//(*b).foo ();
  AutoPtr<A[]> c (new A[3]);
//A* p = new A[12];
//cout << *((int*)p-1) << endl;
  return 0;
}
