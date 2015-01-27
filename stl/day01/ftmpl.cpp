#include <iostream>
#include <cstring>
using namespace std;
// 模板函数
template<typename T /* 类型参数 */>
T max (T a, T b) {
  return a > b ? a : b;
}
// 针对const char*类型的特化
template<>
const char* max<const char*> (const char* a,
  const char* b) {
  return strcmp (a, b) > 0 ? a : b;
}
template<typename T>
void foo (void) {
  T x;
}
template<typename T>
T bar (void) {
  T x;
  return x;
}
template<typename A, typename B>
A hum (B b) {
  A a;
  return a;
}
template<typename A, typename B>
B fun (A a) {
  B b;
  return b;
}
int main (void) {
  cout << ::max (100, 200) << endl;
  cout << ::max (1.23, 4.56) << endl;
  cout << ::max<string> ("hello", "world") << endl;
  cout << ::max ("hello", "world") << endl;
  foo<int> ();
  int x = bar<int> ();
  int y = hum<int> (1.23);
//int z = fun<int> (4.56);
  return 0;
}
