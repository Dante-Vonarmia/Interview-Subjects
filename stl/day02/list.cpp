// 链表容器
#include <iostream>
#include <stdexcept>
#include <cstring>
using namespace std;
// 链表模板
template<typename T>
class List {
public:
  // 构造函数、析构函数、拷贝构造、拷贝赋值
  List (void) : m_head (NULL), m_tail (NULL) {}
  ~List (void) {
    clear ();
  }
  List (const List& that) : m_head (NULL),
    m_tail (NULL) {
    for (Node* node = that.m_head; node;
      node = node->m_next)
      push_back (node->m_data);
  }
  List& operator= (const List& that) {
    if (&that != this) {
      List list (that);
      swap (m_head, list.m_head);
      swap (m_tail, list.m_tail);
    }
    return *this;
  }
  // 获取首元素
  T& front (void) {
    if (empty ())
      throw underflow_error ("链表下溢！");
    return m_head->m_data;
  }
  const T& front (void) const {
    return const_cast<List*> (this)->front ();
  }
  // 向首部压入
  void push_front (const T& data) {
    m_head = new Node (data, NULL, m_head);
    if (m_head->m_next)
      m_head->m_next->m_prev = m_head;
    else
      m_tail = m_head;
  }
  // 从首部弹出
  void pop_front (void) {
    if (empty ())
      throw underflow_error ("链表下溢！");
    Node* next = m_head->m_next;
    delete m_head;
    m_head = next;
    if (m_head)
      m_head->m_prev = NULL;
    else
      m_tail = NULL;
  }
  // 获取尾元素
  T& back (void) {
    if (empty ())
      throw underflow_error ("链表下溢！");
    return m_tail->m_data;
  }
  const T& back (void) const {
    return const_cast<List*> (this)->back ();
  }
  // 向尾部压入
  void push_back (const T& data) {
    m_tail = new Node (data, m_tail);
    if (m_tail->m_prev)
      m_tail->m_prev->m_next = m_tail;
    else
      m_head = m_tail;
  }
  // 从尾部弹出
  void pop_back (void) {
    if (empty ())
      throw underflow_error ("链表下溢！");
    Node* prev = m_tail->m_prev;
    delete m_tail;
    m_tail = prev;
    if (m_tail)
      m_tail->m_next = NULL;
    else
      m_head = NULL;
  }
  // 删除所有匹配元素
  void remove (const T& data) {
    for (Node* node = m_head, *next; node; node=next) {
      next = node->m_next;
      if (equal (node->m_data, data)) {
        if (node->m_prev)
          node->m_prev->m_next = node->m_next;
        else
          m_head = node->m_next;
        if (node->m_next)
          node->m_next->m_prev = node->m_prev;
        else
          m_tail = node->m_prev;
        delete node;
      }
    }
  }
  // 清空
  void clear (void) {
    for (Node* next; m_head; m_head = next) {
      next = m_head->m_next;
      delete m_head;
    }
    m_tail = NULL;
  }
  // 判空
  bool empty (void) const {
    return ! m_head && ! m_tail;
  }
  // 大小
  size_t size (void) const {
    size_t counter = 0;
    for (Node* node = m_head; node; node=node->m_next)
      ++counter;
    return counter;
  }
  // 输出
  friend ostream& operator<< (ostream& os,
    const List& list) {
    for (Node* node=list.m_head;node;node=node->m_next)
      os << *node;
    return os;
  }
private:
  // 节点模板
  class Node {
  public:
    Node (const T& data, Node* prev = NULL,
      Node* next = NULL) : m_data (data),
      m_prev (prev), m_next (next) {}
    friend ostream& operator<< (ostream& os,
      const Node& node) {
      return os << '[' << node.m_data << ']';
    }
    T     m_data; // 数据
    Node* m_prev; // 前指针
    Node* m_next; // 后指针
  };
  bool equal (const T& a, const T& b) const {
    return a == b;
  }
  Node* m_head; // 头指针
  Node* m_tail; // 尾指针
public:
  // 正向迭代器
  class Iterator {
  public:
    Iterator (Node* head = NULL, Node* tail = NULL,
      Node* node = NULL) : m_head (head),
      m_tail (tail), m_node (node) {}
    bool operator== (const Iterator& it) const {
      return m_node == it.m_node;
    }
    bool operator!= (const Iterator& it) const {
      return ! (*this == it);
    }
    Iterator& operator++ (void) {
      if (m_node)
        m_node = m_node->m_next;
      else
        m_node = m_head;
      return *this;
    }
    const Iterator operator++ (int) {
      Iterator old = *this;
      ++*this;
      return old;
    }
    Iterator& operator-- (void) {
      if (m_node)
        m_node = m_node->m_prev;
      else
        m_node = m_tail;
      return *this;
    }
    const Iterator operator-- (int) {
      Iterator old = *this;
      --*this;
      return old;
    }
    T& operator* (void) const {
      return m_node->m_data;
    }
    T* operator-> (void) const {
      return &**this;
    }
  private:
    Node* m_head;
    Node* m_tail;
    Node* m_node;
    friend class List;
  };
  // 获取起始正向迭代器
  Iterator begin (void) {
    return Iterator (m_head, m_tail, m_head);
  }
  // 获取终止正向迭代器
  Iterator end (void) {
    return Iterator (m_head, m_tail);
  }
  // 在正向迭代器之前插入
  Iterator insert (Iterator loc, const T& data) {
    if (loc == end ()) {
      push_back (data);
      return Iterator (m_head, m_tail, m_tail);
    }
    else {
      Node* node = new Node (data, loc.m_node->m_prev,
        loc.m_node);
      if (node->m_prev)
        node->m_prev->m_next = node;
      else
        m_head = node;
      node->m_next->m_prev = node;
      return Iterator (m_head, m_tail, node);
    }
  }
  // 删除正向迭代器的目标
  Iterator erase (Iterator loc) {
    if (loc == end ())
      throw invalid_argument ("无效参数！");
    if (loc.m_node->m_prev)
      loc.m_node->m_prev->m_next = loc.m_node->m_next;
    else
      m_head = loc.m_node->m_next;
    if (loc.m_node->m_next)
      loc.m_node->m_next->m_prev = loc.m_node->m_prev;
    else
      m_tail = loc.m_node->m_prev;
    Node* next = loc.m_node->m_next;
    delete loc.m_node;
    return Iterator (m_head, m_tail, next);
  }
  // 常正向迭代器
  class ConstIterator {
  public:
    ConstIterator (void) {}
    ConstIterator (const Iterator& it) : m_it (it) {}
    bool operator== (const ConstIterator& it) const {
      return m_it == it.m_it;
    }
    bool operator!= (const ConstIterator& it) const {
      return ! (*this == it);
    }
    ConstIterator& operator++ (void) {
      ++m_it;
      return *this;
    }
    const ConstIterator operator++ (int) {
      ConstIterator old = *this;
      ++*this;
      return old;
    }
    ConstIterator& operator-- (void) {
      --m_it;
      return *this;
    }
    const ConstIterator operator-- (int) {
      ConstIterator old = *this;
      --*this;
      return old;
    }
    const T& operator* (void) const {
      return *m_it;
    }
    const T* operator-> (void) const {
      return &**this;
    }
  private:
    Iterator m_it;
  };
  // 获取起始常正向迭代器
  ConstIterator begin (void) const {
    return const_cast<List*> (this)->begin ();
  }
  // 获取终止常正向迭代器
  ConstIterator end (void) const {
    return const_cast<List*> (this)->end ();
  }
  // 反向迭代器
  // class ReverseIterator { ... };
  // 常反向迭代器
  // class ConstReverseIterator { ... };
};
// 针对const char*类型的特化
template<>
bool List<const char*>::equal (const char* const& a,
  const char* const& b) const {
  return ! strcmp (a, b);
}
// 线性查找
// size_t find (int data[], size_t len, int key) {...}
// Node* find (Node* head, int key) {...}
template<typename IT, typename T>
IT find (IT begin, IT end, T key) {
  IT it;
  for (it = begin; it != end; ++it)
    if (*it == key)
      break;
  return it;
}
// 测试用例
int main (void) {
  List<int> list1;
  list1.push_front (30);
  list1.push_front (20);
  list1.push_front (10);
  cout << list1 << endl; // 10 20 30
  list1.push_back (40);
  list1.push_back (50);
  list1.push_back (60);
  cout << list1 << endl; // 10 20 30 40 50 60
  ++list1.front ();
  list1.back ()--;
  cout << list1 << endl; // 11 20 30 40 50 59
  const List<int>* cp = &list1;
//cp->front () = 100;
  cout << cp->front () << ' ' << (*cp).back () << endl;
  List<int> list2 = list1;
  list2.pop_front ();
  list2.pop_back ();
  cout << list1 << endl << list2 << endl;
  list2 = list1;
  list1.pop_front ();
  list1.pop_back ();
  cout << list1 << endl << list2 << endl;
  list1.clear ();
  try {
    cout << list1.front () << endl;
  }
  catch (exception& ex) {
    cout << ex.what () << endl;
  }
  List</*string*/const char*> list3;
  list3.push_back ("北京");
  list3.push_back ("上海");
  list3.push_back ("天津");
  cout << list3 << endl;
  char text[] = "上海";
  list3.remove (text);
  cout << list3 << endl;
  for (List<int>::Iterator it = list2.begin ();
    it != list2.end (); ++it)
    cout << *it << ' ';
  cout << endl;
  List<int>::Iterator loc = list2.begin ();
  ++++loc;
  ++*list2.insert (loc, 25);
  list2.insert (list2.end (), 60);
  cout << list2 << endl;
  /*
  const List<int>::Iterator cit = list2.begin ();
  *cit = 0;
  ++cit;
  cout << list2 << endl;
  */
  cp = &list2;
  List<int>::ConstIterator cit = cp->begin ();
  cout << *cit << endl;
//++*cit;
  cit = list2.begin ();
  cout << *++cit << endl;
  cout << list2 << endl;
  loc = list2.begin ();
  ++++++loc;
  list2.erase (list2.erase (list2.erase (loc)));
  cout << list2 << endl;
  string sa[] = {"beijing", "tianjin", "shanghai"};
  string* ps = find (sa, sa + 3, "tian_jin");
  if (ps == sa + 3)
    cout << "没找到！" << endl;
  else
    cout << "找到了：" << *ps << endl;
  loc = find (list2.begin (), list2.end (), 58);
  if (loc == list2.end ())
    cout << "没找到！" << endl;
  else
    cout << "找到了：" << *loc << endl;
  return 0;
}
