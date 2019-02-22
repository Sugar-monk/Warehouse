#include "List.h"
#include <assert.h>
#include <stdlib.h>

//��ʼ������
void LInit(LNode **list)
{
	assert(list);
	*list = NULL;
}

//��������
void LDestory(LNode **list)
{
	assert(list);
	LNode *next;
	for (LNode *cur = *list; cur != NULL; cur = next)
	{
		next = cur->next;
		free(cur);
	}
	*list = NULL;
}
//ջ������ռ�
static LNode* AppNewNode(DataType data)
{
	LNode *newNode = (LNode *)malloc(sizeof(LNode));
	newNode->data = data;
	newNode->next = NULL;

	return newNode;

}
//ͷ��
void LPushFront(LNode **list, DataType data)
{
	LNode * newNode = AppNewNode(data);
	newNode->next = *list;

	*list = newNode;
}
//β��
void LPushBack(LNode **list, DataType data)
{
	LNode *newNode = AppNewNode(data);
	//�������Ϊ������Ϊ������
	if (*list == NULL)
	{
		*list = newNode;			//ֱ��������ĵ�һ���ڵ�Ϊ�½ڵ�
		return;
	}

	//�������������Ϊ������
	LNode *cur = *list;
	while (cur->next != NULL)		//��������֪��listΪ���һ���ڵ�
	{
		cur = cur->next;
	}
	cur->next = newNode;
}
//ͷɾ

void LPopFront(LNode **list)
{
	assert(list != NULL);	// ������ַ��Ϊ NULL
	assert(*list != NULL);	// �����ǿ�����
	LNode *del = *list;		//Ϊ�˷����ͷţ���ͷ����ŵ�һ��������
	*list = del->next;

	free(del);			//�ͷſռ䣬����del���ΪҰָ�룬
}
//βɾ
void LPopBack(LNode **list)
{
	assert(list != NULL);	// ������ַ��Ϊ NULL
	assert(*list != NULL);	// �����ǿ�����

	//ֻ��һ���ڵ�����
	if ((*list)->next == NULL)
	{
		free(*list);
		*list = NULL;			//ֱ��������ĵ�һ���ڵ�Ϊ�½ڵ�
		return;
	}
	LNode *del;
	LNode *cur = *list;
	while (cur->next->next != NULL)//�������ҵ����ڶ����ڵ�
	{
		cur = cur->next;
	}
	del = cur->next;		//delָ�����һ���ڵ�
	cur->next = NULL;		//�������ڶ����ڵ��next�ÿ�
	free(del);
}