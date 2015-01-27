#include <iostream>
#include <cstring>
#include <fstream>
#include <algorithm>
using namespace std;
class Teacher {
public:
  Teacher (string const& name = "",
    string const& sex = "", int age = 0) : m_age (age){
    strcpy (m_name, name.c_str ());
    strcpy (m_sex, sex.c_str ());
  }
  friend ostream& operator<< (ostream& os,
    Teacher const& teacher) {
    return os<< teacher.m_name << "，" << teacher.m_sex
      << "，" << teacher.m_age;
  }
private:
  /*
  string m_name;
  string m_sex;
  */
  char m_name[256];
  char m_sex[32];
  int m_age;
};
int main (void) {
  string str = "hello, world !";
  str[0] = 'H';
  str[7] = 'W';
  cout << str << endl;
  cout << "size:     " << str.size () << endl;
  cout << "capacity: " << str.capacity () << endl;
  cout << "length:   " << str.length () << endl;
  cout << "strlen:   " << strlen (str.c_str()) << endl;
  cout << "sizeof:   " << sizeof (str) << endl;
  Teacher teacher ("杨健", "男", 40);
  ofstream ofs ("teacher.dat", ios::binary);
  ofs.write ((char*)&teacher, sizeof (teacher));
  ofs.close ();
  Teacher t;
  ifstream ifs ("teacher.dat", ios::binary);
  ifs.read ((char*)&t, sizeof (t));
  cout << t << endl;
  ifs.close ();
  string s1 = "abc";
  string s2 = "def";
  string s3 = "ghi";
//s1 += s2 += s3;
//s1.append (s2).append (s3);
//s1.append (s2, 0, 2).append (s3, 1, 2);
  s1.append (10, 'x').append (10, 'y');
  cout << s1 << endl;
  string s4 = "abc1def1ghi";
  string::size_type pos = s4.find_first_of ('1');
  cout << pos << endl;
  pos = s4.find_first_of ('1', 4);
  cout << pos << endl;
  pos = s4.find_first_of ('1', 8);
  cout << (int)pos << endl;
  if (pos == string::npos)
    cout << "没找到！" << endl;
  string s5 = "abc1def2ghi3jkl";
  pos = s5.find_first_of ("0123456789");
  cout << pos << endl;
  pos = s5.find_first_of ("0123456789", 4);
  cout << pos << endl;
  pos = s5.find_first_of ("0123456789", 8);
  cout << pos << endl;
  string s6 = "aaabcd";
  pos = s6.find_first_not_of ('a');
  cout << pos << endl;
  pos = s6.find_first_not_of ("abc");
  cout << pos << endl;
  string s7 = "abc123def123ghi";
  pos = s7.find ("123", 0);
  cout << pos << endl;
  pos = s7.find ("123", 4);
  cout << pos << endl;
  pos = s7.rfind ("123", 14);
  cout << pos << endl;
  s7.replace (6, 3, "达内科技");
  cout << s7 << endl;
  try {
    string s8 = "abc";
//  cout << s8[3] << endl;
    cout << s8.at (3) << endl;
  }
  catch (exception& ex) {
    cout << ex.what () << endl;
  }
  string s9 = "world";
  s9.insert (0, "hello, ");
  cout << s9 << endl;
  string s10 = "hello";
  s10.erase (1, 3);
  cout << s10 << endl;
  string s11 = "zhongguo";
  for (string::iterator it = s11.begin ();
    it != s11.end (); ++it)
    *it -= 'a' - 'A';
  cout << s11 << endl;
  sort (s11.begin (), s11.end ());
  cout << s11 << endl;
  return 0;
}
