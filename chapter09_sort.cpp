#include "stdio.h"
#include "stdlib.h"
#include "iostream"
using namespace std;

/***************/
/* Interview 5 */
/***************/
// 直接选择排序
// 基本思想：n 个记录的直接选择排序可经过 n－1 趟直接选择排序得到有序结果。
// void select_sort(int a[], int len)
// {
// 	int mini, locate;							// 记录最小数以及其位置
// 	for (int i = 0; i < len; ++i)				// 进行 n－1 次遍历
// 	{
// 		mini = a[i];							// 每次遍历前 mini 和 locate 的初值设置
// 		locate = i;
// 		for (int j = i; j < len; ++j)			// 从 i 位置向尾部遍历
// 		{
// 			if (a[j] < mini)
// 			{
// 				mini = a[j];					// mini 保存每次遍历搜索到的最小数
// 				locate = j;						// locate 记录最小数的位置
// 			}
// 		}
// 		a[locate] = a[i];
// 		a[i] = mini;							// 把最小元素与 a[i] 进行交换
// 	}
// }

// void print_array(int a[], int len);

// int main(int argc, char const *argv[])
// {
// 	int data[9] = {54, 38, 96, 23, 15, 72, 60, 45, 83};
// 	select_sort(data, 9);
// 	print_array(data, 9);
// 	return 0;
// }

/***************/
/* Interview 4 */
/***************/
// 快速排序
// void quick_sort(int a[], int low, int high)
// {
// 	int i, j, pivot;
// 	if (low < high)
// 	{
// 		pivot = a[low];
// 		i = low;
// 		j = high;
// 		while(i < j)
// 		{
// 			while(i < j && a[j] >= pivot)
// 			{
// 				--j;
// 			}
// 			if (i < j)
// 			{
// 				swap(a[i], a[j]);
// 			}
// 			while(i < j && a[i] <= pivot)
// 			{
// 				++i;
// 			}
// 			if (i < j)
// 			{
// 				swap(a[j], a[i]);
// 			}
// 		}
// 		swap(a[i], pivot);
// 		quick_sort(a, low, i - 1);
// 		quick_sort(a, i + 1, high);
// 	}
// }

// void print_array(int a[], int len);

// int main(int argc, char const *argv[])
// {
// 	int data[9] = {54,38,23,52,64,89,65,43,70};
// 	quick_sort(data, 0, 8);
// 	print_array(data, 9);
// 	return 0;
// }

/***************/
/* Interview 3 */
/***************/
// 冒泡排序

// void bubble_sort_upgrade(int a[], int len)
// {
// 	int exchange = 0;							// 用于记录每次交换是否发生
// 	for (int i = 0; i < len - 1; ++i)			// 进行 n－1 趟扫描
// 	{
// 		exchange = 0;							// 没趟扫描对 exchange 置 0
// 		for (int j = len - 1; j >= i; --j)		// 从后往前交换，这样最小冒泡到开头部分
// 		{
// 			if (a[j+1] < a[j])					// 如果 a[j+1] 小于 a[j]，交换两元素的值
// 			{
// 				a[j+1] ^= a[j];
// 				a[j] ^= a[j+1];
// 				a[j+1] ^= a[j];
// 				exchange = 1;					// 发生交换，exchange 置 1
// 			}
// 		}
// 		if (1 != exchange)						// 若此趟扫描没有发生交换，说明已排序，不需要进行下次扫描
// 		{
// 			continue;
// 		}
// 	}
// }

// void print_array(int a[], int len);

// int main(int argc, char const *argv[])
// {
// 	int a[] = {7, 3, 5, 8, 9, 1, 2, 4, 6};
// 	int length = sizeof(a) / sizeof(int);
// 	cout << "before bubble_sort_upgrade: ";
// 	print_array(a, length);
// 	bubble_sort_upgrade(a, length);
// 	cout << "after bubble_sort_upgrade: ";
// 	print_array(a, length);
// 	return 0;
// }

/***************/
/* Interview 2 */
/***************/
// 希尔排序
// 在效率上比直接插入排序有较大改进
// 由于分组，相等的元素可能会分在不同组，导致它们的次序可能发生变化，不稳定性。
// 设置增量：初始时取序列的一半为增量，以后每次减半，直至增量为 1。
// void shell_sort(int a[], int len)
// {
// 	int h, i, j, temp;

// 	for (h = len/2; h > 0; h /= 2)			// 控制增量
// 	{
// 		for (i = h; i < len; ++i)			// 这个 for 循环就是直接插入排序
// 		{
// 			temp = a[i];
// 			for (j = i - h; j >= 0 && temp < a[j]; j -= h)
// 			{
// 				a[j+h] = a[j];
// 			}
// 			a[j+h] = temp;
// 		}
// 	}
// }

// void print_array(int a[], int len);

// int main(int argc, char const *argv[])
// {
// 	int a[] = {7, 3, 5, 8, 9, 1, 2, 4, 6};
// 	cout << "before shell_sort: ";
// 	print_array(a, 9);
// 	shell_sort(a, 9);
// 	cout << "after shell_sort: ";
// 	print_array(a, 9);
// 	return 0;
// }

/***************/
/* Interview 1 */
/***************/
// 直接插入排序
// void insert_sort(int a[], int n)
// {
// 	int i, j, temp;

// 	for (i = 1; i < n; ++i)		// 需要选择 n－1 次
// 	{
// 		// 暂存下标为 i 的数。下标从 1 开始，因为开始时下标为 0 的数，前面没有任何数，此时认为它是排好序的
// 		temp = a[i];
// 		for (j = i - 1; j >= 0 && temp < a[j]; --j)
// 		{
// 			// 如果满足条件就往后挪，最坏的情况就是 temp 比 a[0] 小，它要放在最前面
// 			a[j + 1] = a[j];
// 		}
// 		// 找到下标为 i 的数的放置位置
// 		a[j + 1] = temp;
// 	}
// }

// void print_array(int a[], int len);

// int main(int argc, char const *argv[])
// {
// 	int a[] = {7, 3, 5, 8, 9, 1, 2, 4, 6};
// 	cout << "before insert_sort: ";
// 	print_array(a, 9);
// 	insert_sort(a, 9);
// 	cout << "after insert_sort: ";
// 	print_array(a, 9);
// 	return 0;
// }

/*Public Class*/
void print_array(int a[], int len)
{
	for (int i = 0; i < len; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}