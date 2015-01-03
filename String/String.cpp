#include "String.h"
#include "string.h"

String::String()		// 默认构造函数，构造空字符串
{
	data = new char[1];	// 空字符串只包含结束符一个元素
   *data = '\0';
	size = 0;
}

String::String(int n, char c) 	// 普通构造函数
{
	data = new char[n+1];		// 含有n个相同字符的字符串
	size = n;
	char *temp = data;
	while(n--)					// 做n次赋值
	{
		*temp++ = c;
	}
	*temp = '\0';
}

String::String(const char *source)	// 普通构造函数
{									// 字符串内容与 source 相同
	if (source == NULL)				// source 为 NULL
	{
		data = new char[1];			// data 赋为空字符串
	   *data = '\0';
		size = 0;
	}
	else							// source 不为 NULL
	{
		size = strlen(source);
		data = new char[size+1];
		strcpy(data,source);		// 复制 source 字符串
	}
}

String::String(const String &s)		// 复制构造函数
{
	data = new char[s.size+1];		// 字符串内容与对象s的相同
	strcpy(data,s.data);
	size = s.size;
}

String& String::operator =(char *s)	// = 重载
{
	if (data != NULL)				// 目标为字符串
	{
		delete[] data;
	}
	size = strlen(s);
	data = new char[size+1];
	strcpy(data, s);				// 复制目标字符串
	return *this;
}

String& String::operator =(const String& s)		// = 重载
{												// 目标为String对象
	if (this == &s)
	{
		return *this;							// 如果对象s就是自己，直接返回*this
	}
	if (data != NULL)							// 释放data堆内存
	{
		delete[] data;
	}
	size = strlen(s.data);
	data = new char[size+1];					// 分配堆内存
	strcpy(data, s.data);						// 复制对象s的字符串成员
	return *this;
}

String::~String()
{
	if (data != NULL)							// data 不为 NULL，释放data堆内存
	{
		delete[] data;
		data = NULL;
		size = 0;
	}
}

char& String::operator [](int i)				// [] 重载
{
	return data[i];								// 取数组下标为i的字符元素
}

const char& String::operator[] (int i) const
{
	return data[i];
}

String& String::operator +=(const String& s)	// += 重载
{												// 连接对象s的字符串成员
	int len = size + s.size + 1;				
	char *temp = data;							// 申请足够的堆内存来存放连接后的字符串
	data = new char[len];
	size = len - 1;
	strcpy(data, temp);							// 复制原来的字符串
	strcat(data, s.data);						// 连接目标对象内的字符串成员
	delete[] temp;
	return *this;
}

String& String::operator +=(const char *s)		// += 重载
{												// 连接s字符串
	if (s == NULL )
	{
		return *this;
	}
	int len = size + strlen(s) + 1;
	char *temp = data;							// 申请足够的堆内存来存放连接后的字符串
	data = new char[len];
	size = len - 1;
	strcpy(data, temp);							// 复制原来的字符串
	strcat(data, s);							// 连接目标字符串
	delete[] temp;
	return *this;
}

int String::length()
{
	return size;								// 获取字符串长度
}

ostream& operator <<(ostream &out, String &s)	// 重载<<
{												// 打印对象s内字符串成员的所有字符元素
	for (int i = 0; i < s.length(); ++i)
	{
		out << s[i] << " ";						// 输出字符串中每一个字符元素
	}
	return out;
}

istream& operator >>(istream& in, String& s)
{
	char p[50];
	in.getline(p, 50);							// 从输入流接收最多50个字符
	s = p;										// 调用赋值函数
	return in;
}

bool operator  <(const String& left, const String& right)	// < 重载
{
	int i = 0;
	while(left[i] == right[i] && left[i] != '\0' && right[i] != '\0')
	{
		i++;
	}
	return left[i]-right[i] < 0 ? true : false;
}

bool operator  >(const String& left, const String& right)	// > 重载
{
	int i = 0;
	while(left[i] == right[i] && left[i] != '\0' && right[i] != '\0')
	{
		i++;
	}
	return left[i]-right[i] > 0 ? true : false;
}

bool operator ==(const String& left, const String& right)	// == 重载
{
	int i = 0;
	while(left[i] == right[i] && left[i] != '\0' && right[i] != '\0')
	{
		i++;
	}
	return left[i]-right[i] == 0 ? true : false;
}

bool operator !=(const String& left, const String& right)	// != 重载
{
	int i = 0;
	while(left[i] == right[i] && left[i] != '\0' && right[i] != '\0')
	{
		i++;
	}
	return left[i]-right[i] != 0 ? true : false;
}