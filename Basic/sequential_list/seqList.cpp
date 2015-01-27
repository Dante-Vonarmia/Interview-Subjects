// 构造函数，通过指定参数 sz 定义数组的长度
template <typename T>
SeqList<T>::SeqList(int sz)
{
	if (sz > 0)
	{
		maxSize = sz;				// 置表的实际长度为空
		last = -1;					// 创建顺序表存储数组
		data = new T[maxSize];		// 动态分配失败
		if (data = NULL)
		{
			cerr << "存储分配错误！" << endl;
			exit(1);
		}
	}
}

// 复制构造函数，用参数表中给出的已有顺序表初始化新建的顺序表
template <typename T>
SeqList<T>::SeqList(SeqList<T>& L)
{
	maxSize = L.Size();
	last = L.Length() - 1;
	T value;
	data = new T[maxSize];			// 创建顺序表存储数据
	if (data = NULL)
	{
		cerr << "存储分配错误！" << endl;
		exit(1);
	}
	for (int i = 0; i < last + 1; ++i)
	{
		L.getData(i, value);
		data[i - 1] = value;
	}
}

// 私有函数：扩充顺序表的存储数组空间大小，新数组的元素个数为 newSize
template <typename T>
void SeqList<T>::reSize(int newSize)
{
	if (newSize <= 0)							// 检查参数的合理性
	{
		cerr << "无效的数组大小" << endl;
		return;
	}
	if (newSize != maxSize)						// 修改
	{
		T* newarray = new T[newSize];			// 建立新数组
		if (newarray == NULL)
		{
			cerr << "存储分配错误！" << endl;
			exit(1);
		}
		int n = last + 1;
		T* srcptr = data;						// 源数组首地址
		T* destptr = newarray;					// 目的数组首地址
		while(--n)								// 赋值
		{
			++*destptr = ++*srcptr;
		}
		delete[] data;							// 释放源数组
		data = newarray;						// 赋值新数组
		maxSize = newSize;
	}
}