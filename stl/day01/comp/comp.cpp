#include <cstring>
template<typename T>
Comparator<T>::Comparator (T x, T y) : m_x (x), m_y (y) {}
template<typename T>
T Comparator<T>::max (void) const {
  return m_x > m_y ? m_x : m_y;
}
template<typename T>
T Comparator<T>::min (void) const {
  return m_x < m_y ? m_x : m_y;
}
template<>
const char* Comparator<const char*>::max (void) const {
  return strcmp (m_x, m_y) > 0 ? m_x : m_y;
}
template<>
const char* Comparator<const char*>::min (void) const {
  return strcmp (m_x, m_y) < 0 ? m_x : m_y;
}
