#include <iostream>
#include <queue>
#include <vector>
#include <deque>
#include <list>
using namespace std;
class Student {
public:
  Student (string const& name = "", int score = 0) :
    m_name (name), m_score (score) {}
  friend ostream& operator<< (ostream& os,
    Student const& student) {
    return os << student.m_name << "，"
      << student.m_score;
  }
  friend istream& operator>> (istream& is,
    Student& student) {
    return is >> student.m_name >> student.m_score;
  }
  /*
  bool operator< (Student const& student) const {
    return m_score < student.m_score;
  }
  */
private:
  string m_name;
  int m_score;
  friend class CmpStu;
};
class CmpStu {
public:
  bool operator() (Student const& sa,
    Student const& sb) const {
    return sa.m_score < sb.m_score;
  }
};
int main (void) {
  priority_queue<Student, deque<Student>, CmpStu> sq;
  for (size_t i = 0; i < 5; ++i) {
   Student student;
   cin >> student;
   sq.push (student);
  }
  while (! sq.empty ()) {
    cout << sq.top () << endl;
    sq.pop ();
  }
  return 0;
}
