
//在指定前位置插入
void Insert(LNode** list, LNode *pos, DataType data)
{
	assert(list != NULL);	// 变量地址不为 NULL
	assert(*list != NULL);	// 不能是空链表
	if (*list == pos)
	{
		LPushFront(list, data);
		return;
	}
	LNode *cur = *list;
	while (cur->next != pos)
	{
		cur = cur->next;
	}
	LNode *newNode = AppNewNode(data);		//在栈上为新节点申请空间
	cur->next = newNode;
	newNode->next = pos;

}
//指定位置删除 
void ErasePos(LNode** list, LNode* pos)
{
	assert(list != NULL);	// 变量地址不为 NULL
	assert(*list != NULL);	// 不能是空链表
	if (*list == pos)
	{
		LPopFront(list);
		return;
	}

	LNode *cur = *list;
	while (cur->next != pos)
	{
		cur = cur->next;
	}
	cur->next = pos->next;		//直接将cur的地址跳过pos，链接下一个节点
	free(pos);
}
//删除第一个遇到的data节点
void Remove(LNode** list, DataType data)//找到这个值所在的位置，对这个位置进行删除
{
	assert(list != NULL);	// 变量地址不为 NULL
	assert(*list != NULL);	// 不能是空链表
	if ((*list)->data == data)
	{
		LPopFront(list);
		return;
	}
	LNode *del;
	LNode *cur = *list;
	while (cur != NULL && cur->next->data != data)
	{
		cur = cur->next;
	}
	if (cur == NULL)
	{
		return;
	}
	del = cur->next;
	cur->next = cur->next->next;

	free(del);
}
void RemoveAll(LNode** list, DataType data)
{
	assert(list != NULL);	// 变量地址不为 NULL
	assert(*list != NULL);	// 不能是空链表
	LNode *cur = (*list)->next;
	LNode *tmp = *list;
	while (cur != NULL)
	{
		if (cur->data == data)
		{
			tmp->next = cur->next;
			free(cur);
			cur = tmp->next;
		}
		else
		{
			tmp = cur;
			cur = cur->next;
		}
	}
	LNode *del = *list;
	if ((*list)->data == data)
	{
		del = (*list)->next;
	}
	return del;
}