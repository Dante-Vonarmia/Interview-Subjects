#include <iostream>
using namespace std;
template<typename K>
class Pair {
public:
  Pair (const K& key) : m_key (key) {}
  /*
  template<typename V>
  void print (const V& val) {
    cout << m_key << '=' << val << endl;
  }
  */
  template<typename V>
  void print (const V& val);
  K m_key;
};
template<typename K>
  template<typename V>
void Pair<K>::print (const V& val) {
  cout << m_key << '=' << val << endl;
}
int main (void) {
  Pair<string> pair ("PAI");
  pair.print<double> (3.14);
  return 0;
}
