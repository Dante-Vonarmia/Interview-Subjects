#include <iostream>
#include <stack>
#include <vector>
using namespace std;
template<typename T, typename C>
class mystack {
public:
  void push (T const& elem) {
    m_c.push_back (elem);
  }
  void pop (void) {
    m_c.pop_back ();
  }
  T& top (void) {
    return m_c.back ();
  }
  T const& top (void) const {
    return const_cast<mystack*> (this)->top ();
  }
  bool empty (void) const {
    return m_c.empty ();
  }
  size_t size (void) const {
    return m_c.size ();
  }
private:
  C m_c;
};
int main (void) {
//mystack<string, vector<string> > si;
  stack<string> si;
  si.push ("饭");
  si.push ("吃");
  si.push ("我");
  while (! si.empty ()) {
    cout << si.top ();
    si.pop ();
  }
  cout << endl;
  return 0;
}
