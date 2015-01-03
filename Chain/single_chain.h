#ifndef SINGLE_CHAIN_H
#define SINGLE_CHAIN_H

/****************/
/* 单链表相关操作 */
/***************/

// 链表节点
typedef struct node
{
	int data;		// 节点内容
	node *next;		// 下一个节点
} node;	

// 建立单链表
node *create()
{
	int i = 0;								// 链表中数据的个数
	node *head, *p, *q;
	int x = 0;
	head = (node *)malloc(sizeof(node));	// 创建头节点

	while(1)
	{
		if (0 == i)
		{
			printf("Please submit the data: \n");
			printf("[Enter 0 to quit] \n");
		}
		scanf("%d", &x);
		if ( 0 == x)
		{
			break;
		}
		p = (node *)malloc(sizeof(node));
		p -> data = x;
		if (++i == 1)						// 链表只有一个元素
		{
			head -> next = p;				// 连接到 head 的后面
		}
		else
		{
			q -> next = p;					// 连接到链表末端
		}
		q = p;								// q 指向末节点
	}
	q -> next = NULL;						// 链表的最后一个指针为 NULL
	return head;
}

// 编写实现一个单链表节点的查找
// 查找单链表 pos 位置的节点，返回节点指针
// pos 从 0 开始，0 返回 head 节点
node *search_node(node *head, int pos)
{
	node *p = head -> next;
	if (pos < 0)										// pos 位置不正确
	{
		printf("Incorrect position to search node!\n");
	}
	if (0 == pos)
	{
		return head;									// 在 head 位置，返回 head
	}
	if (NULL == p)
	{
		printf("Link is empty!\n");						// 链表为空
		return NULL;
	}

	while(--pos)
	{
		if (NULL == (p = p -> next))					// 超出链表返回
		{
			printf("Incorrect position to search node!\n");
			break;
		}
	}
	return p;
}

// 编写一个单链表节点的插入
// 在单链表 pos 位置处插入节点，返回链表头指针
node *insert_node(node *head, int pos, int data)
{
	node *item = NULL;
	node *p;

	item = (node *)malloc(sizeof(node));
	item -> data = data;
	// if (pos == 0)					// 插入链表头后面
	// {
	// 	head -> next = item;		// head 后面是 item
	// 	return head;
	// }
	p = search_node(head, pos);		// 获得位置 pos 的字节指针
	if (p != NULL)
	{
		item -> next = p -> next;	// item 指向原 pos 节点的后一个节点
		p -> next = item;			// 把 item 插入到 pos 的后面
	}
	return head;
}

// 查找中间元素
// 假设：
// mid 指向当前已经扫描的子链表的中间元素
// cur 指向当前已经扫描的子链表的末节点
// cur 到 cur -> next，只需判断一下是否移动 mid 到 mid -> next	
node *search(node *head)
{
	int i = 0;
	int j = 0;
	node *current = NULL;
	node *middle = NULL;

	current = middle = head -> next;
	while(current != NULL)
	{
		if (i / 2 > j)
		{
			j++;
			middle = middle -> next;
		}
		i++;
		current = current -> next;
	}
	return middle;
}

// 编写一个单链表节点的删除
// 删除单链表的 pos 位置的节点，返回链表头指针
// pos 从 1 开始计算，1 表示删除 head 后的第一个节点
node *delete_node(node *head, int pos)
{
	node *item = NULL;
	node *p = head -> next;
	if (NULL == p)							// 链表为空
	{
		printf("Link is empty\n");
	}
	p = search_node(head, pos - 1);			// 获得位置 pos 的节点指针
	if (NULL != p && p -> next != NULL)
	{
		item = p -> next;					// 删除节点的下一项
		p -> next = item -> next;			// item 的后一节点插入到 pos 节点后
		delete item;						// 释放 item 原节点
	}
	return head;
}

// 单链表的逆置
node *reverse(node *head)
{
	node *p, *q, *r;

	if (head -> next == NULL)
	{
		return head;
	}

	p = head -> next;				// 原头节点
	q = p -> next;					// 保存原第 2 个节点
	p -> next = NULL;				// 原第 1 个节点为末节点

	while(q != NULL)				// 遍历，各个节点的 next 指针反转
	{
		r = q -> next;
		q -> next = p;
		p = q;
		q = r;
	}

	head -> next = p;				// 新的第 1 个节点为原末节点
	return head;
}

// 单链表打印
void print(node *head)
{
	node *p;
	int index = 0;
	if (head -> next == NULL)			// 链表为空
	{
		printf("Link is empty\n");
	}
	p = head -> next;
	while(p != NULL)					// 遍历链表
	{
		if (0 == index)
		{
			printf("The %dst node is: %d\n", ++index, p->data);
		}
		else if (1 == index)
		{
			printf("The %dnd node is: %d\n", ++index, p->data);
		}
		else if (2 == index)
		{
			printf("The %drd node is: %d\n", ++index, p->data);
		}
		else
		{
			printf("The %dth node is: %d\n", ++index, p->data);
		}
		p = p -> next;
	}
}

// 单链表打印——单数据
void print_1(node *head)
{
	node *p;
	if (head -> next == NULL)			// 链表为空
	{
		printf("Link is empty\n");
	}
	else
	{
		printf("The node is: %d\n", p->data);
	}
}

// 单链表测长
int length(node *head)
{
	int len = 0;
	node *p;
	p = head -> next;
	while(p != NULL)		// 遍历链表
	{
		len++;
		p = p -> next;
	}
	return len;
}

#endif