#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;
class Movie {
public:
  friend istream& operator>> (istream& is,
    Movie& movie) {
    return is >> movie.m_title >> movie.m_company
      >> movie.m_gross;
  }
  friend ostream& operator<< (ostream& os,
    Movie const& movie) {
    return os << movie.m_title << ' '
      << movie.m_company << ' '
      << movie.m_gross;
  }
  bool operator< (Movie const& movie) const {
    return gross () > movie.gross ();
  }
private:
  double gross (void) const {
    string g = m_gross;
    string::size_type pos = 0;
    while ((pos = g.find_first_of ("$,", pos)) !=
      string::npos)
      g.erase (pos, 1);
    return atof (g.c_str ());
  }
  string m_title;
  string m_company;
  string m_gross;
};
bool read (char const* filename,vector<Movie>& movies){
  ifstream ifs (filename);
  if (! ifs) {
    perror ("打开票房记录失败");
    return false;
  }
  Movie movie;
  while (ifs >> movie)
    movies.push_back (movie);
  if (! ifs.eof ()) {
    perror ("读取票房记录失败");
    return false;
  }
  ifs.close ();
  return true;
}
bool write (char const* filename,
  vector<Movie> const& movies) {
  ofstream ofs (filename);
  if (! ofs) {
    perror ("打开榜单文件失败");
    return false;
  }
  for (vector<Movie>::const_iterator it=movies.begin();
    it != movies.end (); ++it) 
    if (! (ofs << *it << endl)) {
       perror ("写入榜单文件失败");
       return false;
    }
  ofs.close ();
  return true;
}
int main (int argc, char* argv[]) {
  if (argc < 3) {
    cerr << "用法：" << argv[0]
      << " <票房文件> <榜单文件>" << endl;
    return -1;
  }
  vector<Movie> movies;
  if (! read (argv[1], movies))
    return -1;
  sort (movies.begin (), movies.end ());
  if (movies.size () > 10)
    movies.resize (10);
  if (! write (argv[2], movies))
    return -1;
  return 0;
}
