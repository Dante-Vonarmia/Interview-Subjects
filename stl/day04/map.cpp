#include <iostream>
#include <map>
using namespace std;
class Candidate {
public:
  Candidate (string const& name = "") : m_name (name),
    m_votes (0) {}
  string const& name (void) const {
    return m_name;
  }
  int votes (void) const {
    return m_votes;
  }
  void vote (void) {
    ++m_votes;
  }
private:
  string m_name;
  int m_votes;
};
class CmpChar {
public:
  bool operator() (char a, char b) const {
    return a > b;
  }
};
int main (void) {
  map<char, Candidate, CmpChar> cs;
  cs.insert (pair<char, Candidate> ('A',
    Candidate ("张飞")));
  cs.insert (make_pair ('B', Candidate ("赵云")));
  cs['C'] = Candidate ("关羽");
  cs['D'] = Candidate ("刘备");
  cs['E'] = string ("曹操");
  typedef map<char, Candidate>::iterator IT;
  pair<IT, bool> res = cs.insert (make_pair ('B',
    Candidate ("黄忠")));
  if (! res.second)
    cout << "插入失败！" << endl;
  cs['B'] = Candidate ("黄忠");
  for (size_t i = 0; i < 10; ++i) {
    for (IT it = cs.begin (); it != cs.end (); ++it)
      cout << '(' << it->first << ") " <<
        it->second.name () << ' ';
    cout << endl << "请投下庄严的一票：" << flush;
    char key;
    cin >> key;
    IT it = cs.find (key);
    if (it == cs.end ()) {
      cout << "废票！" << endl;
      continue;
    }
    it->second.vote ();
  }
  IT win = cs.begin ();
  for (IT it = cs.begin (); it != cs.end (); ++it) {
    cout << it->second.name () << "获得"
      << it->second.votes () << "票。" << endl;
    if (it->second.votes () > win->second.votes ())
      win = it;
  }
  cout << "热烈祝贺" << win->second.name ()
    << "成功当选首席保洁员！" << endl;
  return 0;
}
