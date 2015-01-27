#ifndef LINEARLIST_H
#define LINEARLIST_H

enum bool { false, true };
template <typename T>
class LinearList
{
public:
	LinearList();												// 构造函数
	~LinearList();												// 析构函数

	virtual int Size() const = 0;								// 求表最大的体积
	virtual int Length() const = 0;								// 求表长度
	virtual int Search(T& x) const = 0;							// 在表中搜索给定值 x
	virtual int Locate(int i) const = 0;						// 在表中定位第 i 个元素位置
	virtual bool getData(int i, T& x) const = 0;				// 取第 i 个表项的值
	virtual void setData(int i, T& x) = 0;						// 修改第 i 个表项的值为 x
	virtual bool Insert(int i, T& x) = 0;						// 在第 i 个表项后插入 x
	virtual bool Remove(int i, T& x) = 0;						// 删除第 i 个表项，通过 x 返回
	virtual bool IsEmpty() const = 0;							// 判表空
	virtual bool IsFull() const = 0;							// 判表满
	virtual void Sort() = 0;									// 排序
	virtual void input() = 0;									// 输入
	virtual void output() = 0;									// 输出
	virtual LinearList<T> operator=(LinearList<T>& L) = 0;		// 赋值重载
};

#endif