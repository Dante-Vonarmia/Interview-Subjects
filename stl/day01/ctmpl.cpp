#include <iostream>
#include <cstring>
using namespace std;
// 类模板
template<typename T>
class Comparator {
public:
  Comparator (T x, T y) : m_x (x), m_y (y) {}
  T max (void) const {
    return m_x > m_y ? m_x : m_y;
  }
  T min (void) const {
    return m_x < m_y ? m_x : m_y;
  }
private:
  T m_x;
  T m_y;
};
// 全模板特化
/*
template<>
class Comparator<const char*> {
public:
  Comparator (const char* x, const char* y) :
    m_x (x), m_y (y) {}
  const char* max (void) const {
    return strcmp (m_x, m_y) > 0 ? m_x : m_y;
  }
  const char* min (void) const {
    return strcmp (m_x, m_y) < 0 ? m_x : m_y;
  }
private:
  const char* m_x;
  const char* m_y;
};
*/
// 成员特化
template<>
const char* Comparator<const char*>::max (void) const {
  return strcmp (m_x, m_y) > 0 ? m_x : m_y;
}
template<>
const char* Comparator<const char*>::min (void) const {
  return strcmp (m_x, m_y) < 0 ? m_x : m_y;
}
int main (void) {
  Comparator<int> ci (100, 200);
  cout << ci.max () << ' ' << ci.min () << endl;
  Comparator<double> cd (1.23, 4.56);
  cout << cd.max () << ' ' << cd.min () << endl;
  Comparator<string> cs ("hello", "world");
  cout << cs.max () << ' ' << cs.min () << endl;
  Comparator<const char*> cp ("hello", "world");
  cout << cp.max () << ' ' << cp.min () << endl;
  return 0;
}
