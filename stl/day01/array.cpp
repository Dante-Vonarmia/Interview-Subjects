#include <iostream>
using namespace std;

template<typename T, size_t S>
class Array {
public:
	T& operator[] (size_t i) {
		return m_array[i];
	}
	const T& operator[] (size_t i) const {
		return const_cast<Array<T, S>&> (*this) [i];
	}
	size_t capacity (void) const {
		return sizeof (m_array) / sizeof (m_array[0]);
	}
private:
	T m_array[S];
};
template<int a, int b>
void foo (void) {
	cout << a << ' ' << b << endl;
}
int main(int argc, char const *argv[])
{
	const /*volatile*/ int x = 2, y = 8;
	Array<int, x+y> ai;
	ai[0] = 10;
	ai[1] = 20;
	cout << ai[0] << ' ' << ai[1] << endl;
	cout << ai.capacity () << endl;
	foo<123, 456> ();
	Array<Array<Array<int, 3>, 3>, 3> m;
	m[0][0][0] = 111;
	m[1][1][1] = 222;
	cout << m[0][0][0] << ' ' << m[1][1][1] << endl;
	return 0;
}