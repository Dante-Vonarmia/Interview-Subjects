#ifndef _COMP_H
#define _COMP_H
template<typename T>
class Comparator {
public:
  Comparator (T x, T y);
  T max (void) const;
  T min (void) const;
private:
  T m_x;
  T m_y;
};
#include "comp.cpp"
#endif // _COMP_H
