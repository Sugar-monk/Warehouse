
//��ָ��ǰλ�ò���
void Insert(LNode** list, LNode *pos, DataType data)
{
	assert(list != NULL);	// ������ַ��Ϊ NULL
	assert(*list != NULL);	// �����ǿ�����
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
	LNode *newNode = AppNewNode(data);		//��ջ��Ϊ�½ڵ�����ռ�
	cur->next = newNode;
	newNode->next = pos;

}
//ָ��λ��ɾ�� 
void ErasePos(LNode** list, LNode* pos)
{
	assert(list != NULL);	// ������ַ��Ϊ NULL
	assert(*list != NULL);	// �����ǿ�����
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
	cur->next = pos->next;		//ֱ�ӽ�cur�ĵ�ַ����pos��������һ���ڵ�
	free(pos);
}
//ɾ����һ��������data�ڵ�
void Remove(LNode** list, DataType data)//�ҵ����ֵ���ڵ�λ�ã������λ�ý���ɾ��
{
	assert(list != NULL);	// ������ַ��Ϊ NULL
	assert(*list != NULL);	// �����ǿ�����
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
	assert(list != NULL);	// ������ַ��Ϊ NULL
	assert(*list != NULL);	// �����ǿ�����
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