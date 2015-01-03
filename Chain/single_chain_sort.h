typedef	struct s_node
{
	int data;
	s_node *next;
} s_node;

/****************/
/* 单链表正序排列 */
/***************/

s_node *sort_node(void)
{
	int data = 0;
	struct s_node *head = NULL, *New, *Cur, *Pre;
	printf("Please submit the data:\n");
	while(1)
	{
		scanf("%d", &data);
		if (data == 0)					// 输入 0 结束
		{
			break;
		}
		New = (struct s_node*)malloc(sizeof(struct s_node));	// 新分配一个 node 节点
		New -> data = data;
		New -> next = NULL;
		if (head == NULL)				// 第一次循环时对头节点赋值
		{
			head = (struct s_node*)malloc(sizeof(struct s_node));
			continue;
		}
		if (New -> data <= head -> data)
		{// head 之前插入节点
			New -> next = head;
			head = New;
			continue;
		}
		Cur = head;
		while(New -> data > Cur -> data && Cur -> next != NULL)	
		{// 找到需要插入到位置
			Pre = Cur;
			Cur = Cur -> next;
		}
		if (Cur -> data >= New -> data)		// 把 New 节点插入到 Pre 和 Cur 之间
		{
			Pre -> next = New;
			New -> next = Cur;
		}
		else
		{// 位置在末尾
			Cur -> next = New;				// 把 New 节点插入到 Cur 之后
		}
	}
	return head;
}

// 打印单链表排序
void print(s_node *head)
{
	s_node *p;
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