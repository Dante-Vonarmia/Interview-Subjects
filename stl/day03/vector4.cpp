#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Integer {
public:
  Integer (int value = 0) : m_value (value) {}
  ostream& operator>> (ostream& os) const {
    return os << m_value;
  }
  bool operator== (const Integer& that) const {
    return m_value == that.m_value;
  }
private:
  int m_value;
};
bool cmpint (int a, int b) {
  return b < a;
}
class CmpInt {
public:
  CmpInt (bool up = true) : m_up (up) {}
  bool operator() (int a, int b) const  {
    return m_up ? (a < b) : (b < a);
  }
private:
  bool m_up;
};
class Student {
public:
  Student (string const& name, int age) :
    m_name (name), m_age (age) {}
  friend ostream& operator<< (ostream& os,
    Student const& student) {
    return os << student.m_name << "，"
      << student.m_age;
  }
  bool operator< (Student const& that) const {
    if (m_name != that.m_name)
      return m_name < that.m_name;
    return m_age > that.m_age;
  }
private:
  string m_name;
  int m_age;
  friend class CmpStu;
};
class CmpStu {
public:
  bool operator() (Student const& sa,
    Student const& sb) const {
    if (sa.m_age != sb.m_age)
      return sa.m_age > sb.m_age;
    return sa.m_name < sb.m_name;
  }
};
int main (void) {
  int ai[] = {12, 33, 24, 19, 33, 25};
  vector<int> vi (ai, ai + 6);
  vector<int>::iterator it = find (vi.begin (),
    vi.end (), 33);
  if (it == vi.end ())
    cout << "没找到！" << endl;
  else
    cout << "找到了：" << *it << " (" << *(it+1)
      << ')' << endl;
  int* p = find (ai + 2, ai + 6, /*34*/33);
  if (p == ai + 6)
    cout << "没找到！" << endl;
  else
    cout << "找到了：" << *p << " (" << *(p+1)
      << ')' << endl;
  vector<Integer> vn;
  vn.push_back (12);
  vn.push_back (33);
  vn.push_back (24);
  vector<Integer>::iterator i = find (vn.begin (),
    vn.end (), 33);
  if (i == vn.end ())
    cout << "没找到！" << endl;
  else
    *i >> (cout << "找到了：") << endl;
  sort (vi.begin (), vi.end ());
  for (vector<int>::iterator it = vi.begin ();
    it != vi.end (); ++it)
    cout << *it << ' ';
  cout << endl;
  sort (ai, ai + 6, /*cmpint*/CmpInt (false));
  for (int* p = ai; p != ai + 6; ++p)
    cout << *p << ' ';
  cout << endl;
  vector<Student> vs;
  vs.push_back (Student ("zhangfei", 20));
  vs.push_back (Student ("zhaoyun", 25));
  vs.push_back (Student ("zhangfei", 30));
  vs.push_back (Student ("guanyu", 25));
  vs.push_back (Student ("zhaoyun", 30));
//sort (vs.begin (), vs.end ());
  sort (vs.begin (), vs.end (), CmpStu ());
  for (vector<Student>::iterator it = vs.begin ();
    it != vs.end (); ++it)
    cout << *it << endl;
  return 0;
}
