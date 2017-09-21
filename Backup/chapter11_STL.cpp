// STL 序列容器: vector, string, deque, list
// STL 关联容器: set, multiset, map, multimap
// STL 适配容器: stack, queue, priority_queue

#include "iostream"
#include "vector"
using namespace std;

/****************/
/* Interview 18 ~ 21 */
/****************/
// refer to  ./auto_ptr

/****************/
/* Interview 17 */
/****************/
// vector 中的 erase 方法与 algorithm 中的 remove 有什么区别

// #include "algorithm"
// void print(vector<int> &a)
// {
// 	for (vector<int>::iterator it = a.begin(); it != a.end(); ++it)
// 	{
// 		cout << *it << " ";
// 	}
// 	cout << endl;
// }

// int main(int argc, char const *argv[])
// {
// 	std::vector<int> array;

// 	array.push_back(1);
// 	array.push_back(2);
// 	array.push_back(3);
// 	array.push_back(3);
// 	array.push_back(4);
// 	array.push_back(5);

// 	array.erase(array.begin());
// 	print(array);
// 	vector<int>::iterator pos;
// 	pos = remove(array.begin(), array.end(), 2);
// 	print(array);
// 	if ((pos + 1) == array.end())
// 	{
// 		cout << "(pos+1) == array.end()" << endl;
// 	}
// 	remove(array.begin(), array.end(), 3);
// 	print(array);

// 	return 0;
// }

/****************/
/* Interview 16 */
/****************/
// STL 算法的使用
// find 和 for_each 两种泛型算法；
// iterator 和 reverse_iterator 的使用。

// #include "deque"
// #include "algorithm"
// using namespace std;

// void print(int elem)
// {
// 	cout << elem << " ";
// }

// int main(int argc, char const *argv[])
// {
// 	deque<int> coll;
// 	for (int i = 1; i < 9; ++i)					// 把 9 个数字放入 coll 容器中。
// 	{
// 		coll.push_back(i);
// 	}
// 	deque<int>::iterator pos1;
// 	pos1 = find(coll.begin(), coll.end(), 2);	// 获取整数 2 在 coll 中存放的位置，即 pos1
// 	deque<int>::iterator pos2;
// 	pos2 = find(coll.begin(), coll.end(), 7);	// 获取整数 7 在 coll 中存放的位置，即 pos2
// 	for_each(pos1, pos2, print);				// 对 pos1 到 pos2 到区间元素进行打印。 左闭右开

// 	cout << endl;

// 	deque<int>::reverse_iterator rpos1(pos1);	// 反向迭代器 rpos1 指向 1
// 	deque<int>::reverse_iterator rpos2(pos2);	// 反向迭代器 rpos2 指向 6
// 	for_each(rpos2, rpos1, print);				// 
	
// 	cout << endl;

// 	return 0;
// }

/****************/
/* Interview 15 */
/****************/
// 什么是 STL 算法
// reverse 算法就能够逆置一个区间中的元素
// #include "string"
// #include "algorithm"	// stl 算法头文件

// int main(int argc, char const *argv[])
// {
// 	int a[4] = {1, 2, 3, 4};
// 	std::vector<string> v;
// 	v.push_back("one");				// 插入三个字符串
// 	v.push_back("two");
// 	v.push_back("three");
// 	reverse<int [4]>(a, a+4);		// (Mac 下不支持) 把数组 a 的所有元素逆置
// 	reverse< vector<string>::iterator >(v.begin(), v.end());	// 逆置 v 中所有元素
// 	for (vector<string>::iterator it = v.begin(); it != v.end(); ++it)
// 	{
// 		cout << *it << " ";			// 输出 v 中元素
// 	}
// 	cout << endl;
// 	for (int i = 0; i < 4; ++i)
// 	{
// 		cout << a[i] << " ";		// 输出数组 a 中元素
// 	}
// 	return 0;
// }

/****************/
/* Interview 14 */
/****************/
// map 和 hashmap 有什么区别
// 1、底层数据结构不同，map 是红黑树，hashmap 是哈希表。
// 2、map 的优点在于元素可以自动按照键值排序，而 hashmap 的优点在于它的各项操作的平均时间复杂度接近常数。
// 3、map 属于标准的一部分，而 hashma 则不是。

/****************/
/* Interview 13 */
/****************/
// STL 中 map 内部是怎么实现的
// map 底层是以红黑树实现的；

// 标准的 STL 关联容器（包括 set 和 map 以及 set 的衍生体 multiset 和 map 的衍生体 multimap）的内部结构是一个平衡二叉树（balanced binary tree）。
// AVL-tree;
// RB-tree;
// AA-tree;
// STL的底层机制都是以 RB-tree（红黑树）完成的。
// RB-tree 也是一个独立的容器，但并不给外界使用。
// 树的每个结点都被着上了红色或者黑色，节点所着的颜色被用来检测树的平衡性。
// 在对节点插入和删除对过程中，可能会被旋转，来保护树对平衡性。
// 平均和最坏对情况下，插入、删除、查找时间都是 O(lgn)。

// 一个红黑树是一棵二叉查找树，除了二叉查找树带有的一般要求外，它还具有下列的属性。
// 结点为红色或者黑色。
// 所有叶子结点都是空节点，并且被着为黑色。
// 如果父结点是红色的，那么两个子节点都是黑色的。
// 结点到其子孙节点到每条简单路径上都包含相同数目都黑色节点。
// 根结点是黑色的。

/****************/
/* Interview 12 */
/****************/
// 理解关联容器 map 的使用
// map 中存放的每一个元素都是一个 键－值 对。

// #include "map"
// #include "string"

// int main(int argc, char const *argv[])
// {
// 	std::map<int, string> mapstring;				// 键为 int 类型，值为 string 类型
// 	mapstring.insert(pair<int, string>(1, "one"));	// 插入 4 个元素
// 	mapstring.insert(pair<int, string>(4, "four"));
// 	mapstring.insert(pair<int, string>(3, "three"));
// 	mapstring.insert(pair<int, string>(2, "two"));
// 	mapstring.insert(pair<int, string>(4, "four four"));	// 4 已经存在，插入失败

// 	mapstring[1] = "one one";						// 1 已经存在，修改键为 1 对应的值
// 	mapstring[5] = "five";							// 5 不存在，添加键为 5 且值为 “five” 的元素
// 	cout << mapstring[1] << endl;					// 打印键为 1 对应元素的值

// 	mapstring.erase(2);								// 删除键为 2 的元素
// 	map<int, string>::iterator f = mapstring.find(2);	// 查找键为 2 的元素
// 	if (f != mapstring.end())						// 判断查找是否成功，如果成功，则不想等
// 	{
// 		mapstring.erase(f);
// 	}
// 	map<int, string>::iterator it = mapstring.begin();
// 	while(it != mapstring.end())					// 使用迭代器遍历 map 中所有元素
// 	{
// 		cout << (*it).first << " " << (*it).second << endl;	// 打印元素的键和值
// 		++it;
// 	}

// 	return 0;
// }

/****************/
/* Interview 11 */
/****************/
// 关联容器 set 的使用
// #include "set"
// #include "string"

// int main(int argc, char const *argv[])
// {
// 	set <string> strset;
// 	set <string>::iterator si;
// 	strset.insert("cantaloupes");		// 插入 6 个元素，其中有两个 grapes
// 	strset.insert("apple");
// 	strset.insert("orange");
// 	strset.insert("banana");
// 	strset.insert("grapes");
// 	strset.insert("grapes");			// grapes 重复，所以不插入
// 	strset.erase("banana");
// 	for (si = strset.begin(); si != strset.end(); ++si)		// 使用迭代器遍历 set 集合
// 	{
// 		cout << *si << endl;				// 打印 set 中所有元素
// 	}
// 	return 0;
// }

/****************/
/* Interview 10 */
/****************/
// 理解适配器 stack 和 queue 的使用
// #include "queue"
// #include "stack"

// int main(int argc, char const *argv[])
// {
// 	stack<int, vector<int> > s;			// define stack
// 	queue<int, vector<int> > q;			// define queue

// 	for (int i = 0; i < 10; ++i)
// 	{
// 		s.push(i);
// 		q.push(i);
// 	}

// 	while(!s.empty())
// 	{
// 		cout << s.top() << endl;
// 		s.pop();
// 	}     

// 	while(!q.empty())
// 	{
// 		cout << q.front() << endl;
// 		q.pop();						// Compile Error, no member named 'pop_front'
// 	}

// 	return 0;
// }

/***************/
/* Interview 9 */
/***************/
// 做应用时如何选择 vector 和 deque
// deque 称为双向队列容器，表面上与 vector 非常相似，甚至能在许多实现中直接替换 vector。
// (1)	deque 比 vector 多了 push_front() 和 pop_front() 两个函数，而这两个函数都是对于首部进行操作的。
// (2) deque 中不存在 capacity() 和 reserve() 成员函数。在 vector 中，这两个函数分别用于获取和设置容器容量
// 	std::vector<int> v;
// 	v.push_back(1);
// 	cout << v.capacity() << endl;
// 	v.reserve(10);
// 	cout << v.capacity() << endl;
// ** deque 中的内存是分段连续的，因此在不同段中的插入效率都相同。

// vector 和 deque 的不同点：
// 内部数据管理不同。
// 需要从首尾两端进行插入或删除元素操作的时候，应该选择deque。

/***************/
/* Interview 8 */
/***************/
// deque 是由一段段定量段连续空间组成段，因此是动态数组类型。

/***************/
/* Interview 7 */
/***************/
// list 和 vector 的使用
// #include "list"

// int main(int argc, char const *argv[])
// {
// 	list<int> list1;
// 	for (int i = 0; i < 8; ++i)
// 	{
// 		list1.push_back(i);
// 	}

// 	// iterator 也需要指明是 int 类型元素的迭代器
// 	for (list<int>::iterator it = list1.begin(); it != list1.end(); ++it)
// 	{
// 		if (*it * 2 == 0)
// 		{
// 			it = list1.erase(it);			// 得到下一个元素的位置
// 			--it;							// 回到上一个元素的位置
// 		}
// 	}

// 	for (list<int>::iterator it = list1.begin(); it != list1.end(); ++it)
// 	{
// 		cout << *it << endl;
// 	}

// 	return 0;
// }


/***************/
/* Interview 6 */
/***************/
// list 和 vector 的区别
// vector 与数组类似
// 内存空间连续。
// 起始地址不变。
// 支持随机数存储。
// 搜索复杂度 O(n)。
// 内存不够时需申请足够大的新内存进行内存拷贝，影响效率。

// list 是由双向链表实现的。
// 内存空间可以不连续。
// 不支持随机数存储。
// 只能通过指针来访问数据。
// 搜索复杂度 O(n)。
// 没有提供[]操作符重载。
// 支持任意地方的删除、插入。

// #include "list"
// int main(int argc, char const *argv[])
// {
// 	vector<int> v;
// 	list<int> l;

// 	for (int i = 0; i < 8; ++i)			// add data to v & l
// 	{
// 		v.push_back(i);
// 		l.push_back(i);
// 	}

// 	cout << "v[2] = " << v[2] << endl;
// 	cout << (v.begin() < v.end()) << endl;
// 	cout << *(v.begin() + 1) << endl;

// 	// list 没有重载[]，list::iterator 没有重载 <>
// 	// cout << "l[2] = " << l[2] << endl;
// 	// cout << (l.begin() < l.end()) << endl;

// 	vector<int>::iterator itv = v.begin();
// 	list<int>::iterator itl = l.begin();
// 	itv = itv + 1;
// 	// itl = itl + 2;				// compile Error, list::iterator 没有重载 ＋
// 	itv++;
// 	itl++;

// 	cout << *itv << endl;
// 	cout << *itl << endl;
// 	return 0;
// }

/***************/
/* Interview 5 */
/***************/
// 把一个文件中的整数排序后输出到另一个文件中
#include "fstream"

// 对 data 容器中的所有元素进行冒泡排序

void Order(std::vector<int>& data)
{
	int count = data.size();
	for (int i = 0; i < count; ++i)
	{
		for (int j = 0; j < count - i - 1; ++j)
		{
			if (data[j] > data[j + 1])
			{
				data[j + 1] ^= data[j];
				data[j] ^= data[j + 1];
				data[j + 1] ^= data[j];
			}
		}
	}
}
int main(int argc, char const *argv[])
{
	std::vector<int> data;
	ifstream in("/Users/fengfan/Development/MyNote/C++_Notes/test.txt");
	if (!in)							// Open output file failed
	{
		cout << "inFile Error!" << endl;
		return 1;
	}

	int temp;
	while(!in.eof())
	{
		in >> temp;						// read the data from test.txt
		data.push_back(temp);			// put data into the vector
	}
	in.close();
	Order(data);
	ofstream out("/Users/fengfan/Development/MyNote/C++_Notes/test.txt");
	if (!out)
	{
		cout << "outFile Error!" << endl;
		return 1;
	}
	for (int i = 0; i < data.size(); ++i)
	{
		out << data[i] << " ";			// print the data back to test.txt
	}
	out.close();

	return 0;
}

/***************/
/* Interview 4 */
/***************/
// vector 容器使用
// typedef vector IntArray;
// IntArray array;
// array.push_back(1);
// array.push_back(2);
// array.push_back(3);
// array.push_back(4);
// for (IntArray<>::iterator itor = array.begin(); itor != array.end(); ++itor)
// {
// 	if (2 == *itor)
// 	{
// 		array.erase(itor);
// 	}
// }
/*Error:*/
// (1) 没有使用类型参数，这将会导致编译错误。
// typedef vector<int> IntArray;

// (2) 循环里只删除 array 数组中的第一个 2，而不能移除所有的 2。
// 	这是因为，每次调用“array.erase(itor);”后，被删除元素之后的内容会自动往前移，导致迭代漏项。
// 	应在删除一项后使 itor--，使之从已经前移的下一个元素起继续遍历。

// int main(int argc, char const *argv[])
// {
// 	typedef vector<int> IntArray;
// 	IntArray array;
// 	array.push_back(1);
// 	array.push_back(2);
// 	array.push_back(2);
// 	array.push_back(3);
// 	// 删除数组中所有的 2。
// 	for (IntArray::iterator itor = array.begin(); itor != array.end(); ++itor)
// 	{
// 		if (2 == *itor)
// 		{
// 			array.erase(itor);
// 			--itor;				// 删除一项后使 itor 自减
// 		}
// 	}

// 	for (IntArray::iterator itor = array.begin(); itor != array.end(); ++itor)
// 	{
// 		cout << *itor << endl;
// 	}

// 	return 0;
// }

/***************/
/* Interview 3 */
/***************/
// vector 容器中 iterator 的使用

// int main(int argc, char const *argv[])
// {
// 	std::vector<int> array;
// 	array.push_back(1);
// 	array.push_back(2);
// 	array.push_back(3);
// 	// for (std::vector<int>::size_type i = array.size() - 1; i >= 0; --i)	// 产生随机数
// 	for (std::vector<int>::size_type i = array.size(); i > 0; --i)
// 	{
// 		cout << "Element is: " << array[i - 1] << endl;
// 	}
// 	return 0;
// }

// 由于 vector 支持随机访问，并且重载了[]运算符，因此可以像数组那样（比如 a[i]）来访问 vector 中的第 i + 1 个元素
// vector 定义
// typedef _A::size_type size_type;

// _A 是 allocator<_Ty>，查看 allocator 的定义
// typedef _SIZT size_type;

// _SIZT 的定义
// #define _SIZT size_t

// size_t 的定义
// typedef unsigned int size_t;

// 无符号的整数是大于等于 0 的。所以代码产生大量随机数，最后导致程序崩溃。

/***************/
/* Interview 2 */
/***************/
// vector 定义如下
// template< class _Ty, class _A = allocator<_Ty> >
// class vector {
// 	// ......
// };
// _Ty 类型用于表示 vector 中存储的元素类型，_A 默认为 allocator<_Ty> 类型。

// allocator 类，它是一种“内存配置器”，负责提供内存管理（可能包含内存分配、释放、自动回收等能力）
// 不用程序员关心内存管理方面的问题。

// int main(int argc, char const *argv[])
// {
// 	std::vector<int> v;					// 初始时无元素，容量为 0
// 	cout << v.capacity() << endl;
// 	v.push_back(1);						// 容量不够，分配 1 个元素内存
// 	cout << v.capacity() << endl;
// 	v.push_back(2);						// 容量不够，分配 2 个元素内存
// 	cout << v.capacity() << endl;
// 	v.push_back(3);						// 容量不够，分配 4 个元素内存
// 	cout << v.capacity() << endl;
// 	v.push_back(4);
// 	v.push_back(5);						// 容量不够，分配 8 个元素内存
// 	cout << v.capacity() << endl;

// 	return 0;
// }

// vector 的 size() 和 capacity() 
// size：数组中元素的个数
// capacity：数组有多大容量
// 如果频繁地进行内存的重新分配，会导致效率低下。

/***************/
/* Interview 1 */
/***************/
// 语言支持（language support）
// 诊断（diagnostics）：
// 	异常exception，
// 	断言assertions，
// 	错误代码error number codes
// 通用工具（general utilities）
// 字符串（string）
// 国际化（internationalization）
// 容器（containers）
// 算法（algorithms）
// 迭代器（iterators）
// 数值（numerics）
// 输入/输出（input/output）

// STL 具有工业强度、高效性的C++程序库。它是最新的C++标准函数库中的一个子集，包括容器、算法、迭代器组件。