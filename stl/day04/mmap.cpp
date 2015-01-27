#include <iostream>
#include <map>
using namespace std;
int main (void) {
  multimap<char, int> mm;
  mm.insert (make_pair ('B', 300));
  mm.insert (make_pair ('C', 500));
  mm.insert (make_pair ('B', 200));
  mm.insert (make_pair ('A', 100));
  mm.insert (make_pair ('B', 400));
  typedef multimap<char, int>::iterator IT;
  for (IT it = mm.begin (); it != mm.end (); ++it)
    cout << it->first << " - " << it->second << endl;
  cout << "--------" << endl;
  IT lower = mm.lower_bound ('B');
  cout << lower->first << " - " << lower->second<<endl;
  IT upper = mm.upper_bound ('B');
  cout << upper->first << " - " << upper->second<<endl;
  cout << "--------" << endl;
  pair<IT, IT> res = mm.equal_range ('B');
  cout << res.first->first << " - "
    << res.first->second << endl;
  cout << res.second->first << " - "
    << res.second->second << endl;
  return 0;
}
