#ifndef DUAL_NODE
#define DUAL_NODE
/******************/
/* 双向链表相关操作 */
/*****************/

// 编写实现一个双向链表的建立
typedef struct dual_node
{
	int data;				// 节点数据
	dual_node *left;		// 前驱节点指针
	dual_node *right;		// 后继节点指针
} dual_node;

// CreateNode() 根据数据来创建一个节点，返回新创建的节点
// CreateList() 函数根据一个节点数据创建链表的表头，返回表头节点
// AppendNode() 函数总在表尾插入新节点（其内部调用 CreateNode()生成节点），返回表头节点

// 根据数据创建节点
dual_node *CreateNode(int data)
{
	dual_node *p_node = (dual_node *)malloc(sizeof(dual_node));
	p_node -> data = data;
	p_node -> left = p_node -> right = p_node;		// 创建新节点时，让其前驱和后继指针都指向自身

	return p_node;
}

// 创建链表
dual_node *CreateList(int head)
{
	dual_node *p_node = (dual_node *)malloc(sizeof(dual_node));
	p_node -> data = head;
	p_node -> left = p_node -> right = p_node;

	return p_node;
}

// 插入新节点，总是在表尾插入；返回表头节点
dual_node *AppendNode(dual_node *head, int data)	// 参数 1 是链表的表头节点
{													// 参数 2 是插入的节点，其数据为 data
	dual_node *node = CreateNode(data);				// 创建数据为 data 的新节点
	dual_node *p = head, *q;

	while(NULL != p)
	{
		q = p;
		p = p -> right;
	}
	q -> right = node;
	node -> left = q;

	return head;
}

// 我们可以使用其中的 CreateList() 和 AppendNode() 来生成一个链表
// 下面是一个数据生成从 0 到 9 含有 10 个节点到循环链表
// dual_node *head = CreateList(0);		// 生成表头，表头数据为 0

// for (int i = 1; i < 10; ++i)			// 添加 9 个节点，数据为从 1 到 9
// {
// 	head = AppendNode(head, i);
// }

// 编写实现双向链表的测长
int GetLength(dual_node *head)
{
	int count = 1;
	dual_node *p_node = NULL;

	if (head == NULL)
	{
		return 0;
	}
	p_node = head -> right;
	while(p_node != NULL)
	{
		p_node = p_node -> right;
		++count;
	}

	return count;
}

// 编写实现双向链表打印
void PrintList(dual_node *head)				// 参数为链表的表头节点
{
	dual_node *p_node = NULL;

	if (head == NULL)
	{
		return;
	}
	p_node = head;
	while (p_node != NULL)
	{
		printf("%d\n", p_node -> data);
		p_node = p_node -> right;			// 使用 right 指针遍历
	}
	printf("\n");
}

// 编写实现双向链表的查找
// 查找节点，成功则返回满足条件的节点指针，否则返回 NULL
dual_node *FindNode(dual_node *head, int data)
{
	dual_node *p_node = head;

	if (head == NULL)
	{
		return NULL;
	}

	/* 找到数据或者到达链表末尾，退出 while 循环 */
	while (p_node -> right != NULL && p_node -> data != data)
	{
		p_node = p_node -> right;			// 使用 right 指针遍历
	}

	// 没有找到数据为 data 的节点，返回 NULL
	if (p_node -> right == NULL)
	{
		return NULL;
	}

	return p_node;
}

// 编写实现双向链表的插入
// 在 node 节点之后插入新节点
void InsertNode(dual_node *node, int data)
{
	dual_node *newnode = CreateNode(data);
	dual_node *p = NULL;
	
	// node 为 NULL 时返回 NULL
	if (node == NULL)
	{
		return NULL;
	}
	// node 为最后一个节点
	if (node -> right == NULL)
	{
		node -> right = newnode;
		newnode -> left = node;
	}
	else
	{	// node 为中间节点
		newnode -> right = node -> right;
		node -> right -> left = newnode;	// newnode 向右连接
		node -> right = newnode;			// newnode 向左连接
		newnode -> left = node;
	}
}

// 编写实现双向链表点的删除
// 3 种删除的情况：删除头节点、删除中间节点以及删除末节点

// 删除满足指定条件的节点，返回表头节点，删除失败，返回 NULL（失败的原因不存在该节点）
dual_node *DeleteNode(dual_node *head, int data)	// 参数 1 是链表的表头节点
{													// 参数 2 是要插入的节点，其数据为 data
	dual_node *ptmp = NULL;

	dual_node *pnode = FindNode(head, data);		// 查找节点
	if (NULL == pnode)								// 节点不存在，返回 NULL
	{
		return NULL;
	}
	else if (pnode -> left == NULL)					// node 为第一个节点
	{
		head = pnode -> right;
		if (head != NULL)							// 链表不为空
		{
			head -> left = NULL;
		}
	}
	else if (pnode -> right == NULL)				// node 为最后一个节点
	{
		pnode -> left -> right = NULL;
	}
	else											// node 为中间的节点
	{
		pnode -> left -> right = pnode -> right;
		pnode -> right -> left = pnode -> left;
	}

	free(pnode);									// 释放已被删除的节点空间
	return head;
}




























#endif
