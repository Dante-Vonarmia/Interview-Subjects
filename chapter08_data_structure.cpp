#include "stdio.h"
#include "stdlib.h"
#include "iostream"
#include "string.h"
using namespace std;

/****************/
/* 单链表相关操作 */
/*     1～9     */
/****************/
#include "Chain/single_chain.h"
// #include "Chain/single_chain_sort.h"

// int main(int argc, char const *argv[])
// {
// 	/*Interview 1~6*/
// 	node *head = create();							// 创建单链表

// 	printf("Length: %d\n", length(head));		// 测量单链表长度
// 	print(head);									// 打印单链表

// 	int i_pos = 2;
// 	printf("Insert integer 5 after %d node:\n", i_pos);
// 	head = insert_node(head, i_pos , 5);			// 在第 2 个节点后插入 5
// 	print(head);									// 打印单链表

// 	printf("Delete the 2nd node:\n");
// 	head = delete_node(head, 2);					// 删除第 2 个节点
// 	print(head);

// 	node *f_head = NULL;							// 搜索单链表节点
// 	printf("Search the 1's pos:\n");
// 	f_head = search_node(head, 1);
// 	print_1(f_head);
// 	/*Interview 1~6*/

// 	/*Interview 7~9*/								// 逆置单链表
// 	printf("Reverse node:\n");
// 	head = reverse(head);
// 	print(head);

// 	node *m_head = NULL;							// 搜索中间节点
// 	printf("Search the middle node:\n");
// 	m_head = search(head);
// 	print_1(m_head);

// 	free(head);
// 	head = NULL;

// 	printf("Sort new node:\n");						// 单链表排序
// 	s_node *s_head = sort_node();
// 	print(s_head);

// 	free(s_head);
// 	s_head = NULL;
// 	/*Interview 7~9*/

// 	return 0;
// }

/****************/
/* Interview 10 */
/****************/
// 判断链表是否存在环形链表
// 设置两个指针 p1、p2
// 每次循环 p1 向前走一步
// p2 向前走两步
// 直到 p2 碰到 NULL 指针或者两个指针相等时结束循环
// 如果两个指针相等，则说明存在环

bool IsLoop(node* head, node **start)
{
	node* p1 = head, *p2 = head;					// 两个指针初始化都指向头节点

	if (head == NULL || head -> next == NULL)
	{
		return false;								// head 为 NULL 或链表为空时返回 false
	}
	do
	{
		p1 = p1 -> next;							// p1 走一步
		p2 = p2 -> next -> next;					// p2 走两步
	} while (p2 && p2 -> next && p1 != p2);			// 直到 p2 碰到 NULL 指针或者两个指针相等时结束循环

	if (p1 == p2)
	{
		*start = p1;								// p1 为回环开始节点
		return true;
	}
	else
	{
		return false;
	}
}

int main(int argc, char const *argv[])
{
	bool bLoop = false;
	node *head = create();
	node *start = head -> next -> next -> next;
	start -> next = head -> next;

	node *loopStart = NULL;
	bLoop = IsLoop(head, &loopStart);
	printf("bLoop = %d\n", bLoop);
	printf("bLoop == loopStart ? %d\n", (loopStart == start));
	return 0;
}

/****************/
/* Interview 11 */
/****************/
// 有序单链表的合并
// 已知有两个链表 head1 和 head2 各自有序，请把它们合成一个有序链表，使用递归与非递归两种方法。

#include "Chain/merge_chain.h"

int main(int argc, char const *argv[])
{
	node *head1 = create();		// 单链表 1
	node *head2 = create();		// 单链表 2
	// node *head = merge(head1, head2);
	node *head = MergeRecursive(head1, head2);	// 合并两个单链表
	print(head);
	return 0;
}

/****************/
/* Interview 12 */
/****************/
// 约瑟夫环
// 循环链表的操作

// /* 结构体和函数声明 */
// typedef struct node
// {
// 	int data;
// 	node* next;
// } node;

// node *node_create(int n);

// /*构造节点数量为 n 的单向循环链表*/
// node *node_create(int n)
// {
// 	node *pRet = NULL;

// 	if (0 != n)
// 	{
// 		int n_idx = 1;
// 		node *p_node = NULL;

// 		/* 构造 n 个 node */
// 		p_node = new node[n];
// 		if (NULL == p_node)		// 申请内存失败，返回 NULL
// 		{
// 			return NULL;
// 		}
// 		else
// 		{
// 			memset(p_node, 0, n * sizeof(node));	// 初始化内存
// 		}
// 		pRet = p_node;
// 		while(n_idx < n)
// 		{
// 			p_node -> data = n_idx;
// 			p_node -> next = p_node + 1;
// 			p_node =  p_node -> next;
// 			++n_idx;
// 		}
// 		p_node -> data = n;
// 		p_node -> next = pRet;
// 	}

// 	return pRet;
// }

// int main(int argc, char const *argv[])
// {
// 	node *pList = NULL;
// 	node *pIter = NULL;
// 	int n = 10;
// 	int m = 6;

// 	/* 构造单向循环链表 */
// 	pList = node_create(n);

// 	/* Josephus 循环取数 */
// 	pIter = pList;
// 	m %= n;
// 	while(pIter != pIter -> next)
// 	{
// 		// 取到第 m － 1 个节点
// 		for (int i = 1; i < m - 1; ++i)
// 		{
// 			pIter = pIter ->next;
// 		}

// 		// 输出第 m 个节点的值
// 		printf("%d \n", pIter -> next -> data);

// 		// 从链表中删除第 m 个节点
// 		pIter -> next = pIter -> next -> next;
// 		pIter = pIter -> next;
// 	}
// 	printf("%d\n", pIter -> data);

// 	/* 释放申请空间 */
// 	delete[] pList;
// 	return 0;
// }

/*****************/
/* 双向链表相关操作 */
/*    13 ~ 20    */
/*****************/
// #include "Chain/dual_chain.h"

// int main(int argc, char const *argv[])
// {
	
// 	return 0;
// }
 





























