#ifndef SEQLIST_H
#define SEQLIST_H

#include <iostream>
#include <stdlib>
#include "linearList.h"

const int defaultSize = 100;
template <typename T>
class SeqList : public LinearList<T>
{
public:
	SeqList(int sz = defaultSize);			// 构造函数
	SeqList(SeqList<T>& L);					// 拷贝构造函数
	~SeqList()
	{
		delete[] data;						// 析构函数
	}
	int Size() const
	{
		return maxSize;						// 计算表最大可容纳表项个数
	}
	int Length() const
	{
		return last + 1;					// 计算表长度
	}
	int Search(T& x) const;					// 搜索 x 在表中位置，函数返回表项序号
	int Locate(int i, T& x) const;			// 定位第 i 个表项，函数返回表项序号
	bool getData(int i, T& x) const			// 取第 i 个表项的值
	{
		if (i > 0 && i <= last + 1)
		{
			x = data[i - 1];
			return true;
		}
		else
		{
			return false;
		}
	}
	void setData(int i, T& x)				// 用 x 修改第 i 个表项的值
	{
		if (i > 0 && i <= last + 1)
		{
			data[i - 1] = x;
		}
	}
	bool Insert(int i, T& x);				// 插入 x 在第 i 个表项之后
	bool Remove(int i, T& x);				// 删除第 i 个表项，通过 x 返回表项的值
	bool IsEmpty()							// 判断表空
	{
		return (last == -1) ? true : false;
	}
	bool IsFull()							// 判断表满
	{
		return (last == maxSize - 1) ? true : false;
	}
	void input();
	void output();
	SeqList<T> operator=(SeqList<T>& L);		// 赋值重载

protected:
	T *data;						// 存放数组
	int maxSize;					// 最大可容纳表项的项数
	int last;						// 当前已存表项的最后位置（从 0 开始）
	void reSize(int newSize);		// 改变 data 数组空间大小
};

#endif