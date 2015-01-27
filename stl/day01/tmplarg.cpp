#include <iostream>
using namespace std;
template<typename T>
class Element {
public:
  Element (const T& data) : m_data (data) {}
  T m_data;
};
template<typename K, typename V,
  template<typename T> class E /* 模板型模板参数 */>
class Pair {
public:
  Pair (const K& key, const V& val) :
    m_key (key), m_val (val) {}
  E<K> m_key;
  E<V> m_val;
};
int main (void) {
  Pair<string, double, Element> pair ("PAI", 3.14);
  cout << pair.m_key.m_data << '='
    << pair.m_val.m_data << endl;
  return 0;
}
