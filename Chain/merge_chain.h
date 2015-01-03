/****************/
/* 有序单链表合并 */
/***************/

node* insert_m_node(node *head, node *item)			// head != NULL
{
	node *p = head;
	node *q = NULL;									// 始终指向 p 之前的节点

	while(p -> data < item -> data && p != NULL)
	{
		q = p;
		p = p -> next;
	}
	if (p == head)									// 插入到原头节点之前 
	{
		item -> next = p;
		return item;
	}
	// 插入到 q 与 p 之间
	q -> next = item;
	item -> next = p;
	return head;
}

// 非递归方法（参考）
node* merge(node* head1, node* head2)		// 传参，链表1 和 链表2
{
	node* head;
	node* p;
	node* nextP;

	if (head1 == NULL)
	{
		return head2;
	}
	else if (head2 == NULL)
	{
		return head1;
	}

	// 两个链表都不为空
	if (length(head1) >= length(head2))
	{
		head = head1;
		p = head2;
	}
	else
	{
		head = head2;
		p = head1;
	}

	while(p != NULL)
	{
		nextP = p -> next;
		head = insert_m_node(head, p);
		p = nextP;
	}

	return head;
}

///////////////////////////////////////////////////////////

// 两个有序链表进行合并
// 递归方法
node* MergeRecursive(node *head1, node *head2)
{
	node *head = NULL;
	if (head1 == NULL)
	{
		return head2;
	}
	if (head2 == NULL)
	{
		return head1;
	}
	if (head1 -> data < head2 -> data)
	{
		head = head1;
		head -> next = MergeRecursive(head1 -> next, head2);
	}
	else
	{
		head = head2;
		head -> next = MergeRecursive(head1, head2 -> next);
	}
	return head;
}