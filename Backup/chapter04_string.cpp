#include "stdio.h"
#include "stdlib.h"
#include "iostream"
using namespace std;

/****************/
/* Interview 31 */
/****************/
// 编写字符串的替换
// char *replace(const char *str, const char *sub1, const char *sub2, char *output)
// {
// 	char *pOutput = NULL;
// 	const char *pStr = NULL;
// 	int lenSub1 = strlen(sub1);	
// 	int lenSub2 = strlen(sub2);

// 	pOutput = output;
// 	pStr = str;									// 用于寻找子串
// 	while(*pStr != 0)
// 	{
// 		pStr = strstr(pStr, sub1);				// 在 str 中寻找 sub1 子串
// 		if (NULL != pStr)						// 找到 sub1 子串
// 		{
// 			memcpy(pOutput, str, pStr - str);	// 复制 str 的前一部分 output
// 			pOutput += pStr - str;
// 			memcpy(pOutput, sub2, lenSub2);		// 复制 sub2 子串到 output
// 			pOutput += lenSub2;
// 			pStr += lenSub1;					// 为了下次复制做准备
// 			str = pStr;
// 		}
// 		else									// 找不到 sub1 子串跳出
// 		{
// 			break;
// 		}
// 	}
// 	*pOutput = '\0';
// 	if (*str != '\0')
// 	{
// 		strcpy(pOutput, str);					// 复制 str 剩余部分到 output
// 	}
// 	return output;
// }

// int main(int argc, char const *argv[])
// {
// 	char str[50] = "fabcfdefg123";
// 	char sub1[10] = "f";		// 被替换目标字符串
// 	char sub2[10] = "0";		// 替换为字符串 sub2
// 	char output[50] ="";

// 	// cout << "str: ";
// 	// cin >> str;
// 	// cout << "sub1: ";
// 	// cin >> sub1;
// 	// cout << "sub2: ";
// 	// cin >> sub2;

// 	cout << replace(str, sub1, sub2, output) << endl;

// 	return 0;
// }

/****************/
/* Interview 30 */
/****************/
// 找出 01 字符串中 0 和 1 连续出现的最大次数
// void combo(const char *str, int *max0, int *max1)
// {
// 	int temp0 = 0;	// 保存连续是'0'的最大长度
// 	int temp1 = 0;	// 保存连续是'1'的最大长度

// 	while(*str)		// 遍历01字符串
// 	{
// 		if (*str == '0')				// 当前字符是'0'
// 		{
// 			(*max0)++;					// '0'的计算长度加1
// 			if (*(++str) == '1')		// 如果下一个字符是'1'
// 			{
// 				if (temp0 < *max0)		// 判断当前最大长度是否需要保存
// 				{
// 					temp0 = *max0;
// 				}
// 				*max0 = 0;
// 			}
// 		}
// 		else if (*str == '1')
// 		{
// 			(*max1)++;					// '1' 的计算长度加1
// 			if (*(++str) == '0')		// 如果下一个字符是'1'
// 			{
// 				if (temp1 < *max1)		// 判断当前最大长度是否需要保存
// 				{
// 					temp1 = *max1;
// 				}
// 				*max1 = 0;
// 			}
// 		}
// 	}
// 	*max0 = temp0;						// '0'的最大长度返回 max0
// 	*max1 = temp1;						// '1'的最大长度返回 max1
// }

// int main(int argc, char const *argv[])
// {
// 	char string[] = "010010011000000111001110101111011111";

// 	int max0 = 0;
// 	int max1 = 0;

// 	combo(string, &max0, &max1);
// 	cout << "max0 = " << max0 << endl;
// 	cout << "max1 = " << max1 << endl;

// 	return 0;
// }

/****************/
/* Interview 29 */
/****************/
// 编写计算中文字符串长度
// int gbkStrlen(const char* str)
// {
// 	const char*p = str;		// p 用于后面遍历
// 	while(*p)				// 若是结束符，则跳出循环
// 	{
// 		if (*p < 0 && (*(p + 1) < 0 || *(p + 1) > 63)) // 符合中文汉字的情况
// 		{
// 			++str;			// str 移动一位，p 移动两位， 因此长度加 1
// 			p += 2;
// 		}
// 		else
// 		{
// 			++p;
// 		}
// 	}
// 	return p - str;			// 返回地址之差
// }

// int main(int argc, char const *argv[])
// {
// 	char str[] = "asdf 123 目的 ";

// 	int len = gbkStrlen(str);
// 	cout << str << endl;
// 	cout << "len = " << len << endl;
// 	return 0;
// }

/****************/
/* Interview 28 */
/****************/
// 编写库函数 strcat
// char* mystrcat(char* dest, const char* src)
// {
// 	char *ret = dest; 		// 保存目的字符串首地址以便返回
// 	while(*dest++);
// 	dest--;					// 此时 dest 指向的是字符串结束符
// 	while((*dest++) = (*src++));
// 	// cout << ret << endl;
// 	return ret;
// }

// int main(int argc, char const *argv[])
// {
// 	char *dest = NULL;
// 	const char *str1 = "Hello ";
// 	const char *str2 = "World!";

// 	dest = (char*)malloc(100);
// 	*dest = '\0';
// 	mystrcat(mystrcat(dest, str1), str2);		// 链式表达式
// 	printf("dest: %s\n", dest); 
// 	free(dest);
// 	dest = NULL;

// 	return 0;
// }

/****************/
/* Interview 27 */
/****************/
// 使用 strcat 连接字符串
// strcat函数的原型：
// extern char *strcat(char *dest, const char *src);

// int main(int argc, char const *argv[])
// {
// 	const char *str1 = "hello";
// 	const char *str2 = " China";
// 	char *str3 = NULL;

// 	str3 = new char[strlen(str1) + strlen(str2) + 1];	// 分配堆内存
// 	// str3[0] = '\n';
// 	str3[0] = '\0';		// 正常使用 strcat 函数
// 	strcat(str3, str1);
// 	strcat(str3, str2);
// 	cout << str3 << endl;

// 	return 0;
// }

/****************/
/* Interview 26 */
/****************/
// 删除指定字符
// char *deleteChars(char *str, char c)
// {
// 	char *head = NULL;
// 	char *p = NULL;

// 	if (str == NULL)
// 	{
// 		return NULL;
// 	}

// 	head = p = str;			// 指向字符串头，准备遍历

// 	while(*p++)
// 	{
// 		if (*p != c)
// 		{
// 			*str++ = *p;
// 		}
// 	}
// 	*str = '\0';

// 	return head;
// }

// int main(int argc, char const *argv[])
// {
// 	char string[] = "cabfawifjwf";
// 	char c = 0;

// 	printf("input char:\n");
// 	scanf("%c", &c);
// 	printf("before delete: %s\n", string);
// 	deleteChars(string, c);
// 	printf("after delete: %s\n", string);
// 	return 0;
// }

/****************/
/* Interview 25 */
/****************/
// 字符串中的排序和交换
// 冒泡排序法
// void mysort(char *str, int num)
// {
// 	for (int i = 0; i < num; ++i)
// 	{
// 		for (int j = i + 1; j < num; ++j)
// 		{
// 			if (str[i] < str[j])
// 			{
// 				str[j] ^= str[i];
// 				str[i] ^= str[j];
// 				str[j] ^= str[i];
// 			}
// 		}
// 	}
// }

// char *foo(char *str)
// {
// 	int len = 0;
// 	char* start = NULL;		
// 	if (str == NULL)
// 	{
// 		return NULL;
// 	}

// 	/*计算字符串长度经典套路*/
// 	start = str;					// 保存头部位置
// 	while(*str++);
// 	len = (str - start - 1) / 2;	// 计算字符串长度
// 	/*计算字符串长度经典套路*/

// 	// len = len / 2;				// 计算需要排序对字符个数
// 	mysort(start, len);				// 从大到小排序

// 	return str;
// }

// int main(int argc, char const *argv[])
// {
// 	char string[] = "ADZDDJKABCDEFGHIJKLMNOPQ";

// 	printf("before transformation: %s\n", string);
// 	foo(string);
// 	printf("after transformation: %s\n", string);
// 	return 0;
// }

/****************/
/* Interview 24 */
/****************/
// 删除指定长度的字符
// #include "string.h"

// char* deleteChars(char *str, int pos, int len)
// {
// 	char *p = str + pos - 1;			// 指向 pos 位置字符
// 	int tt = strlen(str);				// 计算字符长度

// 	if ((pos < 1) || (p - str) > tt)	// 检查 pos 是否不大于1，或者超出字符串长度
// 	{
// 		return str;
// 	}
// 	if ((p + len - str) > tt)			// len 大于 pos 后剩余的字符个数
// 	{
// 		*p = '\0';						// 只需对 pos 位置赋结束符
// 		return str;
// 	}

// 	// 删除 len 个字符
// 	while(*p && *(p + len))				// len 小于或等于 pos 后剩余对字符个数， 删除中间 len 个字符
// 	{
// 		*p = *(p + len);
// 		p++;
// 	}
// 	*p = '\0';

// 	return str;
// }

// int main(int argc, char const *argv[])
// {
// 	char string[] = "abcdefg";
// 	int pos = 0;
// 	int len = 0;
// 	int steps = 0;
// 	printf("string: %s\n", string);
// 	printf("input pos:\n");
// 	scanf("%d", &pos);
// 	printf("input len:\n");
// 	scanf("%d", &len);
// 	deleteChars(string, pos, len);
// 	printf("after delete %d chars behind pos %d : %s\n", len, pos, string);
// 	return 0;
// }

/****************/
/* Interview 23 */
/****************/
// 编写实现字符串的循环右移
// void loopMove(char *str, int n)
// {
// 	char *temp = NULL;
// 	int strLen = 0;
// 	char *head = str;			// 指向字符串头

// 	while(*str++);
// 	strLen = str - head - 1;	// 计算字符串长度
// 	n = n % strLen;				// 计算字符串尾部移到头部的字符个数，防止n过大
// 	temp = (char *)malloc(n);	// 分配内存
// 	for (int i = 0; i < n; ++i)
// 	{
// 		temp[i] = head[strLen - n + i]; // 临时存放从尾部移到头部的字符
// 	}
// 	for (int i = strLen - 1; i >= n; --i)
// 	{
// 		head[i] = head[i - n];	// 从头部字符移到尾部
// 	}
// 	for (int i = 0; i < n; ++i)
// 	{
// 		head[i] = temp[i];		// 从临时内存区复制尾部字符
// 	}
// 	free(temp);
// }

// int main(int argc, char const *argv[])
// {
// 	char string[] = "123456789";
// 	int steps = 0;

// 	printf("string: %s\n", string);
// 	printf("input step:\n");
// 	scanf("%d", &steps);
// 	loopMove(string, steps);	// 向右循环移位
// 	printf("after loopMove %d: %s\n", steps, string);

// 	return 0;
// }

/****************/
/* Interview 22 */
/****************/
// 编写任意长度顶两个正整数相加
// #include "string.h"
// #include "math.h"

// char* addBigInt(char* num1, char* num2)
// {
// 	int c = 0;					// 进位，开始最低进位为0
// 	int i = strlen(num1) - 1;	// 指向第一个加数的最低位
// 	int j = strlen(num2) - 1;	// 指向第二个加数的最低位
// 	// 得到两个数中较大位数的数字
// 	int maxLength = strlen(num1) >= strlen(num2) ? (strlen(num1) + 1) : (strlen(num2) + 1);
// 	char* rst = (char*)malloc(maxLength + 1); // 保存结果
// 	// ???bug???
// 	int k;
// 	if (rst == NULL)
// 	{
// 		printf("Malloc error!\n");
// 		exit(1);
// 	}

// 	rst[maxLength] = '\0';
// 	k = strlen(rst) - 1;
// 	while((i >= 0) && (j >= 0))
// 	{
// 		rst[k] = ((num1[i] - '0') + (num2[j] - '0') + c) % 10 + '0';	// 计算本位的值
// 		c = ((num1[i] - '0') + (num2[j] - '0') + c) / 10;				// 计算高位进位值
// 		--i;
// 		--j;
// 		--k;
// 	}
// 	while(i >= 0)
// 	{
// 		rst[k] = ((num1[i] - '0') + c) % 10 + '0';
// 		c = ((num1[i] - '0') + c) / 10;
// 		--i;
// 		--k;
// 	}
// 	while(j >= 0)
// 	{
// 		rst[k] = ((num2[j] - '0') + c) % 10 + '0';
// 		c = ((num2[j] - '0') + c) / 10;
// 		--j;
// 		--k;
// 	}
// 	rst[0] = c + '0';

// 	if (rst[0] != '0')			// 若结果最高位不等于0，则输出结果
// 	{
// 		return rst;
// 	}
// 	else
// 	{
// 		return rst + 1;
// 	}
// }

// int main(int argc, char const *argv[])
// {
// 	char num1[] = "12345";
// 	char num2[] = "56789";
// 	char *result = NULL;

// 	result = addBigInt(num1, num2);
// 	printf("%s + %s = %s\n", num1, num2, result);

// 	return 0;
// }

/****************/
/* Interview 21 */
/****************/
// 编写字符串反转函数 strrev
// char* strrev1(const char* str)
// {
// 	int len = strlen(str);
// 	char* tmp = new char[len + 1];			// 函数体内申请堆内存

// 	strcpy(tmp, str);
// 	for (int i = 0; i < len/2; ++i)
// 	{
// 		tmp[i] ^= tmp[len - i - 1];
// 		tmp[len - i - 1] ^= tmp[i];
// 		tmp[i] ^= tmp[len - i - 1];
// 	}

// 	return tmp;
// }

// char* strrev2(const char* str)
// {
// 	char* tmp = new char[strlen(str) + 1];
// 	strcpy(tmp, str);
// 	char* rt_value = tmp;
// 	char* p = tmp + strlen(str) - 1;

// 	while(p > tmp)
// 	{
// 		*p ^= *tmp;
// 		*tmp ^= *p;
// 		*p ^= *tmp;

// 		// *p = *p + *tmp;
// 		// *tmp = *p - *tmp;
// 		// *p = *p - *tmp;

// 		--p;
// 		++tmp;
// 	}
// 	return rt_value;
// }

// char* strrev3(char* str, int len)
// {
// 	if (len < 1)
// 	{
// 		return str;
// 	}
// 	*(str + len - 1) ^= *str;
// 	*str ^= *(str + len - 1);
// 	*(str + len - 1) ^= *str;

// 	return (strrev3(str + 1, len - 2) - 1);
// }

// int main(int argc, char const *argv[])
// {
// 	const char* str = "123456";

// 	char* str1 = strrev1(str);
// 	char* str2 = strrev2(str);
// 	char* str3 = strrev3(str1, strlen(str));

// 	cout << str1 << endl;
// 	cout << str2 << endl;
// 	cout << str3 << endl;

// 	return 0;
// }

/****************/
/* Interview 20 */
/****************/
// 字符串反转，但其指定但字串不反转
// #include "cassert"
// #include "stack"
// #include "string.h"

// const char* reverse(const char* source, const char* keyWord)
// {
// 	stack<char> stack1;								// 声明一个栈 后进先出
// 	const char* pkeyWord = keyWord, 				// 存储关键词首地址
// 				   *head = source, 					// 存储关键词开始部分
// 				   *tail = source;					// 存储关键词结束部分
// 	assert(source && keyWord);						// 判断有效性

// 	while(*head != '\0')							// 字符串不结束的情况下，进行循环
// 	{
// 		while(*head != '\0' && *pkeyWord == *head)	// 当关键词和字符串中的字符吻合时，进行循环
// 		{
// 			pkeyWord++;								// 关键词部分自增
// 			head++;									// 关键词开始部分自增，检查配对
// 		}
// 		if (*pkeyWord == '\0')						// 判断关键词结束
// 		{
// 			const char* p;							// 暂存指针变量
// 			for(p = head - 1; p >= tail; p--)		// 逆序遍历获取的关键词部分
// 			{
// 				stack1.push(*p);					// 压入栈中
// 			}
// 			pkeyWord = keyWord;						// 关键词自增完毕，重置关键词
// 			tail = head;							// 抛除不匹配部分，继续向下检查
// 		}
// 		else
// 		{
// 			stack1.push(*tail++);					// 逐个字符排查关键词和字符串是否完全符合
// 			head = tail;							// 继续检查下一组
// 			pkeyWord = keyWord;						// 关键词自增完毕，重置关键词
// 		}
// 	}

// 	char *pReturn = new char[strlen(source) + 1];	// 分配返回值内存空间
// 	int i = 0;
// 	while(!stack1.empty())							// 将逆置的字符串输出
// 	{
// 		pReturn[i++] = stack1.top();				// 回到栈顶
// 		stack1.pop();								// 从顶部弹出元素
// 	}
// 	pReturn[i] = '\0';

// 	return pReturn;
// }

// int main(int argc, char const *argv[])
// {
// 	char welcome[] = "Welcome you, my friend! you";
// 	char keyWord[] = "you";
// 	const char *pRev = reverse(welcome, keyWord);		// Mac 下编译不通过

// 	cout << "before reverse: " << endl;
// 	cout << welcome << endl;
// 	cout << "after reverse: " << endl;
// 	cout << pRev << endl;
// 	return 0;
// }

/****************/
/* Interview 19 */
/****************/
// 字符串编码例题
// Give an implementation of encoding a string which contains less than 20 chars. There three rules:
// 1. replace the alphabetical char in the string with the fourth char behind it. For example,
// a->e, A->E, X->B, y->c, z->d
// 2. If the char is not a alphabetical char, ignore it.
// 3. reverse the string updated.

// char LowerCaseAlphabets[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
// char UpperCaseAlphabets[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'j', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

// char GetFourthChar(char chrSource, char alphabets[])	// 移动 4 位
// {
// 	for (int i = 0; i < 26; ++i)						// 遍历26个字母
// 	{
// 		if (alphabets[i] == chrSource)
// 		{
// 			int index = (i + 4) % 26;					// 移动 4 位
// 			return alphabets[index];
// 		}
// 	}
// 	return '\0';
// }

// void ReplaceChars(char chars[], int len)
// {
// 	for (int i = 0; i < len; ++i)
// 	{
// 		if ('a' <= chars[i] && chars[i] <= 'z')
// 		{
// 			chars[i] = GetFourthChar(chars[i], LowerCaseAlphabets);		// 小写字母转换
// 		}
// 		else if ('A' <= chars[i] && chars[i] <= 'Z')
// 		{
// 			chars[i] = GetFourthChar(chars[i], UpperCaseAlphabets);		// 大写字母转换
// 		}
// 	}
// }

// void ReverseString(char str[], int len)			// 反转字符串
// {
// 	int begin = 0, end = len - 1;
// 	if (str[end] == '\0')
// 	{
// 		--end;
// 	}
// 	while(begin < end)							// 首尾字母互换
// 	{
// 		str[begin] ^= str[end];
// 		str[end] ^= str[begin];
// 		str[begin] ^= str[end];

// 		++begin;
// 		--end;
// 	}
// }

// void EncodeString(char str[], int len)
// {
// 	ReplaceChars(str, len);
// 	ReverseString(str, len);
// }

// int main(int argc, char const *argv[])
// {
// 	char hello[] = "a11HIUXZYxyzabc";

// 	cout << hello << endl;
// 	EncodeString(hello, strlen(hello));
// 	cout << hello << endl;

// 	return 0;
// }

/****************/
/* Interview 18 */
/****************/
// 编程实现转换字符串、插入字符的个数
// #include "string.h"
// #ifndef MAXCOUNT
// #define MAXCOUNT 2*100
// #endif

// char *transformation(char *str)
// {
// 	int len = strlen(str);
// 	char *buf = new char[len + 1];

// 	char *p = str;
// 	char *q = p + 1;
// 	int count = 1;
// 	while(*q)
// 	{
// 		if (*p==*q)
// 		{
// 			++count;
// 			p++;
// 			q++;
// 		}
// 		else
// 		{
// 			itoa(count, buf, 10);
// 			int nbits = strlen(buf);
// 			strcat(buf, q);
// 			*q = 0;
// 			strcat(str, buf);
// 			q += nbits;
// 			p = q;
// 			q = p + 1;
// 			count = 1;
// 		}
// 	}

// 	itoa(count, buf, 10);
// 	strcat(str, buf);

// 	delete []buf;
// 	buf = NULL;
// 	return str;
// }

// int main(int argc, char const *argv[])
// {
// 	char str[MAXCOUNT];

// 	printf("Please input a string:\n");
// 	scanf("%s", &str);
// 	printf("before transformation: %s\n", str);
// 	char *pstr = transformation(str);
// 	printf("after transformation: %s\n", pstr);
// 	return 0;
// }

/****************/
/* Interview 17?? */
/****************/
// 不使用printf，将十进制数以二进制和十六进制的形式输出
// （只适合部分编译器）

// #include "string.h"

// char *get2String(long num)
// {
// 	char* buffer;
// 	char* temp;

// 	buffer = (char*)malloc(33);
// 	temp = buffer;
// 	for (int i = 0; i < 32; ++i)	// 给数组的32个元素赋'0'或'1'
// 	{
// 		temp[i] = num & (1 << (31 - i));
// 		temp[i] = temp[i] >> (31 - i);
// 		temp[i] = (temp[i] == 0) ? '0' : '1';
// 	}
// 	buffer[32] = '\0';				// 字符串结束符
// 	return buffer;
// }

// char *get16String(long num)
// {
// 	char* buffer = (char*)malloc(11);
// 	char* temp;

// 	buffer[0] = '0';
// 	buffer[1] = 'x';
// 	buffer[10] = '\0';
// 	temp = buffer + 2;

// 	for (int i = 0; i < 8; ++i)		// 给数组的8个元素赋值
// 	{
// 		temp[i] = (char)(num << 4 * i >> 28);
// 		temp[i] = temp[i] >= 0 ? (temp[i]) : (temp[i] + 16);
// 		temp[i] = temp[i] <= 10 ? (temp[i] + 48) : (temp[i] + 55);
// 	}
// 	return buffer;
// }

// int main(int argc, char const *argv[])
// {
// 	char *p = NULL;
// 	char *q = NULL;
// 	int num = 0;

// 	printf("input num:\n");
// 	scanf("%d", &num);

// 	p = get2String(num);
// 	q = get16String(num);

// 	printf("%s\n", p);
// 	printf("%s\n", q);

// 	return 0;
// }

/****************/
/* Interview 16 */
/****************/
// 编写查找两个字符串中的最大公共子串
// #include "string.h"
// char *commonstring(char *str1, char *str2)
// {
// 	char *shortstr, *longstr;
// 	char *substr;

// 	if (NULL == str1 || NULL == str2)
// 	{
// 		return NULL;
// 	}
// 	if (strlen(str1) <= strlen(str2))
// 	{
// 		shortstr = str1;
// 		longstr = str2;
// 	}
// 	else
// 	{
// 		shortstr = str2;
// 		longstr = str1;
// 	}

// 	if (strstr(longstr, shortstr) != NULL)		// 如果在长的字符串中寻找到短的字符串，
// 	{
// 		return shortstr;						// 则返回短字符串
// 	}

// 	substr = (char*)malloc(sizeof(char) * (strlen(shortstr) + 1));	// 申请堆内存存放返回结果

// 	for (int i = strlen(shortstr); i > 0; --i)
// 	{
// 		for (int j = 0; j <= strlen(shortstr) - i; ++j)
// 		{
// 			memcpy(substr, &shortstr[j], i);		// 将短字符串短一部分复制到 substr，
// 			substr[i] = '\0';						// 其长度逐渐减小
// 			if (strstr(longstr, substr) != NULL)
// 			{
// 				return substr;						// 如果在 longstr 中能找到 substr，则返回 substr
// 			}
// 		}
// 	}
// 	return NULL;
// }

// int main(int argc, char const *argv[])
// {
// 	char *str1 = (char *)malloc(256);				// 分配堆内存存放字符串 str1 和 str2
// 	char *str2 = (char *)malloc(256);

// 	char *common = NULL;							// 从终端输入 str1 和 str2
// 	gets(str1);
// 	gets(str2);

// 	common = commonstring(str2, str1);

// 	printf("The longest common string is: %s\n", common);

// 	return 0;
// }

/****************/
/* Interview 15 */
/****************/
// 编写 strcmp 库函数
// int mystrcmp(const char* src, const char* dst)
// {
// 	int ret = 0;
// 	while(!(ret = *(unsigned char*)src - *(unsigned char*)dst) && *dst)
// 	{
// 		++src;
// 		++dst;
// 	}
// 	if (ret < 0)
// 	{
// 		ret = -1;
// 	}
// 	else if (ret > 0)
// 	{
// 		ret = 1;
// 	}
// 	return (ret);
// }

// int main(int argc, char const *argv[])
// {
// 	char str[10] = "1234567";
// 	char str1[10] = "1234567";		// str1 == str
// 	char str2[10] = "12345678";		// str2 > str
// 	char str3[10] = "123456";		// str3 < str

// 	cout << "test1 = " << mystrcmp(str, str1) << endl;
// 	cout << "test2 = " << mystrcmp(str, str2) << endl;
// 	cout << "test3 = " << mystrcmp(str, str3) << endl;
// 	return 0;
// }

/****************/
/* Interview 14 */
/****************/
// 判断是否回文数

// int IsRevStr(char *str)
// {
// 	int len;
// 	int found = 1;

// 	if (str == NULL)
// 	{
// 		return -1;
// 	}
// 	len = strlen(str);
// 	for (int i = 0; i < len/2; ++i)
// 	{
// 		if (*(str+i) != *(str+len-i-1))
// 		{
// 			found = 0;
// 			break;
// 		}
// 	}
// 	return found;
// }

// int main(int argc, char const *argv[])
// {
// 	char str1[10] = "1234321";
// 	char str2[10] = "1234311";

// 	int test1 = IsRevStr(str1);
// 	int test2 = IsRevStr(str2);

// 	cout << "str1 is " << (test1 == 1 ? "": "not ") << "reverse string." << endl;
// 	cout << "str2 is " << (test2 == 1 ? "": "not ") << "reverse string." << endl;

// 	return 0;
// }

/****************/
/* Interview 13 */
/****************/

// 编写字符串中各单词的反转
// 方法一：先反转单词，再反转整个字符串
// void RevStr(char *src)
// {
// 	char *start = src, *end = src, *ptr = src;

// 	while (*ptr++ != '\0')						// 遍历字符串
// 	{
// 		if (*ptr == ' ' || *ptr == '\0')		// 找到一个单词
// 		{
// 			end = ptr - 1;						// end 指向单词末尾
// 			while(start < end)
// 			{
// 				swap(*start++, *end--);			// 把单词的字母逆置
// 			}
// 			start = end = ptr + 1;				// 指向下一个单词开头
// 		}
// 	}
// 	start = src, end = ptr - 2;					// start 指向字符串开头，end 指向字符串末尾
// 	while(start < end)
// 	{
// 		swap(*start++, *end--);					// 把整个字符串逆置
// 	}
// }

// int main(int argc, char const *argv[])
// {
// 	char src[] = "I am from Shanghai";
// 	cout << src << endl;
// 	RevStr(src);
// 	cout << src << endl;
// 	return 0;
// }

// 方法二：先反转整个字符串，再反转单词
// void RevStr(char* src)
// {
// 	char *start = src, *end = src, *ptr = src;

// 	while(*ptr++ != '\0');
// 	end = ptr - 2;
// 	while(start < end)
// 	{
// 		swap(*start++, *end--);
// 	}
// 	start = src, end = ptr - 2;
// 	ptr = start;
// 	while(*ptr++ != '\0')
// 	{
// 		if (*ptr == ' ' || *ptr == '\0')
// 		{
// 			end = ptr - 1;
// 			while(start < end)
// 			swap(*start++, *end--);

// 			start = end = ptr + 1;
// 		}
// 	}
// }

// int main(int argc, char const *argv[])
// {
// 	char src[] = "I am from Shanghai";
// 	cout << src << endl;
// 	RevStr(src);
// 	cout << src << endl;
// 	return 0;
// }


/****************/
/* Interview 12 */
/****************/

// 编写在字符串中子串的查找
// #include "assert.h"
// const char* str(const char* src, const char* sub)
// {
// 	const char *bp;
// 	const char *sp;

// 	if (src == NULL || NULL == sub)
// 	{
// 		return src;
// 	}

// 	while (*src)
// 	{
// 		bp = src;						// 用于 src 的遍历
// 		sp = sub;						// 用于 sub 的遍历
// 		do
// 		{
// 			if (!*sp)					// 遍历 sub 字符串，如果到了 sub 字符串结束符位置
// 			{
// 				return src;				// 表示找到了 sub 字符串，退出
// 			}
// 		} while (*bp++ == *sp++);
// 		src += 1;
// 	}

// 	return NULL;
// }

// int main(int argc, char const *argv[])
// {
// 	char p[] = "123456789";
// 	char q[] = "7";

// 	printf("str(p, q): %s\n", str(p, q));

// 	return 0;
// }

/****************/
/* Interview 11 */
/****************/
// 编写计算字符串的长度

// #include "assert.h"

// int strlen1(const char* src)
// {
// 	assert(NULL != src);
// 	int len = 0;
// 	while(*src++ != '\0')
// 	{
// 		++len;
// 	}
// 	return len;
// }

// int strlen2(const char* src)
// {
// 	assert(NULL != src);
// 	const char *temp = src;
// 	while(*src++ != '\0');
// 	return (src - temp - 1);
// }

// int main(int argc, char const *argv[])
// {
// 	char p[] = "Hello World!";
// 	printf("strlen1 len: %d\n", strlen1(p));
// 	printf("strlen2 len: %d\n", strlen2(p));
// 	return 0;
// }

/****************/
/* Interview 10 */
/****************/
// 打印操作——数组越界
// int main(int argc, char const *argv[])
// {
// 	int a[5] = {0, 1, 2, 3, 4}, *p;
// 	p = a;
// 	printf("%d\n", *(p + 4 * sizeof(int)));

// 	return 0;
// }

/***************/
/* Interview 9 */
/***************/
// 循环——数组越界
// #ifndef MAX
// #define MAX 255
// #endif

// int main(int argc, char const *argv[])
// {
// 	unsigned char A[MAX], i;
// 	// for (int i = 0; i <= MAX; ++i) 避免数组越界及无限循环
// 	for (int i = 0; i < MAX; ++i)
// 	{
// 		A[i] = i;
// 	}
// 	return 0;
// }

/***************/
/* Interview 8 */
/***************/
// 声明——数组越界

// #include "string.h"
// void test1()
// {
// 	// char string[10];
// 	char string[11];
// 	const char* str1 = "0123456789";
// 	strcpy(string, str1);
// }

// void test2()
// {
// 	// char string[10], str1[10];
// 	char string[11], str1[11];
// 	int i;
// 	for (i = 0; i < 10; ++i)
// 	{
// 		str1[i] = 'a';
// 	}
// 	str1[10] = '\0';
// 	strcpy(string, str1);
// }

// void test3(const char* str1)
// {
// 	char string[10];
// 	// if (strlen(str1) <= 10)
// 	if (strlen(str1) < 10)
// 	{
// 		strcpy(string, str1);
// 	}
// }

// // Test
// int main(int argc, char const *argv[])
// {
// 	test1();
// 	test2();
// 	test3("12345");
// 	return 0;
// }

/***************/
/* Interview 7 */
/***************/
// Difference between strcpy & memcpy
// (1) strcpy 只能复制字符串，而 memcpy 可以复制任意内容，例如字符数组、整型、结构体、类等。
// (2) 复制方法不同，strcpy 不需要指定长度，遇到结束符'\0'结束。memcpy 则是根据第三参数决定复制的长度。

/***************/
/* Interview 6 */
/***************/
// 编写 memcpy 函数
// 内存复制的实现

// #include "assert.h"

// void *memcpy2(void *memTo, const void *memFrom, size_t size)
// {
// 	assert((memTo != NULL) && (memFrom) != NULL);
// 	char *tempFrom = (char *)memFrom;				// 保存 memFrom 首地址
// 	char *tempTo = (char *)memTo;					// 保存 memTo 首地址

// 	while(size-- > 0)								// 循环 size 次
// 	{
// 		*tempTo++ = *tempFrom++;					// 复制 memFrom 的值到 memTo 中
// 	}
// 	return memTo;
// }

// int getStrLen(const char* strSrc)					// 获取 strSrc 的实际长度
// {
// 	int len = 0;
// 	while(*strSrc++ != '\0')
// 	{
// 		++len;
// 	}
// 	return len;
// }

// int main(int argc, char const *argv[])
// {
// 	char strSrc[] = "Hello World!";
// 	char strDest[20];

// 	memcpy2(strDest, strSrc, getStrLen(strSrc));
// 	strDest[getStrLen(strSrc)] = '\0';
// 	printf("strDest: %s\n", strDest);

// 	return 0;
// }

/***************/
/* Interview 5 */
/***************/
// string copy function
// Prototype: char* strcpy(char* strDest, const char* strSrc);
// (1) 不调用库函数，实现 strcpy 函数。
// (2) 解释为什么要返回 char*

// char* strcpy(char* strDest, const char* strSrc)		// 实现 strSrc 到 strDest 的复制
// {
// 	if ((strDest == NULL) || (strSrc == NULL))
// 	{
// 		return NULL;
// 	}
// 	char *strDestCopy = strDest;
// 	printf("strDestCopy%p\n", strDestCopy);
// 	printf("strDest%p\n", strDest);
// 	while ((*strDest++ = *strSrc++) != '\0');		// 把 strSrc 字符串的内容复制到 strDest 下
// 	return strDestCopy;
// }

// int getStrLen(const char* strSrc)					// 获取 strSrc 的实际长度
// {
// 	int len = 0;
// 	while(*strSrc++ != '\0')
// 	{
// 		++len;
// 	}
// 	return len;
// }

// int main(int argc, char const *argv[])
// {
// 	char strSrc[] = "Hello World!";					// 要被复制的源字符串
// 	char strDest[20];
// 	int len = 0;

// 	len = getStrLen(strcpy(strDest, strSrc));		// 链式表达式，先复制后计算
// 	printf("strDest: %s\n", strDest);
// 	printf("Length of strDest: %d\n", len);
// 	return 0;
// }

/***************/
/* Interview 4 */
/***************/
// 不使用库函数将字符串转换成数字
// int str2int(const char *str)
// {
// 	int temp = 0;
// 	const char *ptr = str;;			// ptr save the initial char of str
// 	if (*str == '-' || *str == '+')	// if the initial char is a symbol
// 	{
// 		str++;						// move to next char
// 	}
// 	while(*str != 0)
// 	{
// 		if ((*str < '0') || (*str > '9'))	// if the char isn't a number
// 		{
// 			break;							// quit the loop
// 		}
// 		temp = temp * 10 + (*str - '0');	// count the current number
// 		str++;								// move to next char
// 	}
// 	if (*ptr == '-')
// 	{
// 		temp = -temp;
// 	}
// 	return temp;
// }
// int main(int argc, char const *argv[])
// {
// 	int n = 0;
// 	char p[10] = "";

// 	cin.getline(p, 20);
// 	n = str2int(p);

// 	cout << n << endl;
// 	return 0;
// }

/***************/
/* Interview 3 */
/***************/
// 使用库函数将字符串转换成数字
// atof(): string to float
// atoi(): string to int
// atol(): string to long double
// strtod(): string to double and report the number of the rest strings can't be converted.
// strtol(): string to long int and report the number of the rest strings can't be converted.
// strtoul(): string to unsigned long int and report the number of the rest strings can't be converted.

// int main(int argc, char const *argv[])
// {
// 	int num_int;
// 	double num_double;
// 	char str_int[30] = "345";
// 	char str_double[30] = "432.523";

// 	num_int = atoi(str_int);
// 	num_double = atof(str_double);

// 	printf("num_int: %d\n", num_int);
// 	printf("num_double: %f\n", num_double);
// 	return 0;
// }


/***************/
/* Interview 2 */
/***************/
// 不使用库函数将数字转换成字符串
// void int2str(int n, char *str) {
// 	char buf[10] = "";
// 	int i = 0;
// 	int len = 0;
// 	int temp = n < 0 ? -n : n; // temp 绝对值

// 	if (str == NULL)
// 	{
// 		return;
// 	}
// 	while (temp)
// 	{
// 		buf[i++] = (temp % 10) + '0';
// 		temp /= 10;
// 	}
// 	len = n < 0 ? ++i : i;
// 	str[i] = 0;
// 	while (1) 
// 	{
// 		i--;
// 		if (buf[len-i-1] == 0)
// 		{
// 			break;
// 		}
// 		str[i] = buf[len-i-1];
// 		// if (i == 0)
// 		// {
// 		// 	str[i] = '-';
// 		// }
// 	}
// }

// int main(int argc, char const *argv[])
// {
// 	int nNum = 99228;
// 	char p[10] = {};
// 	int buf[10] = {};
// 	int b_i = 0;
// 	int p_i = 0;
// 	int temp;

// 	cout << "Submit an integer: ";
// 	// cin >> nNum;
// 	cout << "output: ";
// 	// int2str(nNum, p);
// 	cout << p << endl;

// 	while (nNum) {
// 		temp = nNum % 10+'0';
// 		buf[b_i] = temp;
// 		nNum /= 10;
// 		++b_i;
// 	}
// 	while (b_i) {
// 		p[p_i] = buf[b_i-1];
// 		p_i++;
// 		b_i--; 
// 	}
// 	cout << p << endl;
// 	// cout << &p[1] << endl;

// 	return 0;
// }

/***************/
/* Interview 1 */
/***************/
// #include "stdio.h"
// #include "stdlib.h"
// itoa();		int to array
// ltoa();		long to array
// ultoa();	unsigned long to array
// gcvt();		float to array. >=5
// ecvt();		double to array
// fcvt();		digit to degree

// 使用库函数将数字转换成字符串
// int main(int argc, char const *argv[])
// {
// 	int num_int = 435;
// 	double num_double = 435.10f;
// 	char str_int[30];
// 	char str_double[30];

// 	itoa(num_int, str_int, 10); // 把整数 num_int 转换成字符串 str_int
// 	gcvt(num_double, 8, str_double); // 把浮点数 num_double 转换成字符串 str_double
// 	// sprintf();

// 	printf("str_int: %s\n", str_int);
// 	printf("str_double: %s\n", str_double);

// 	return 0;
// }