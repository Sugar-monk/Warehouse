#include "List.h"
#include <assert.h>
#include <stdlib.h>

//初始化链表
void LInit(LNode **list)
{
	assert(list);
	*list = NULL;
}

//销毁链表
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
//栈上申请空间
static LNode* AppNewNode(DataType data)
{
	LNode *newNode = (LNode *)malloc(sizeof(LNode));
	newNode->data = data;
	newNode->next = NULL;

	return newNode;

}
//头插
void LPushFront(LNode **list, DataType data)
{
	LNode * newNode = AppNewNode(data);
	newNode->next = *list;

	*list = newNode;
}
//尾插
void LPushBack(LNode **list, DataType data)
{
	LNode *newNode = AppNewNode(data);
	//特殊情况为：链表为空链表
	if (*list == NULL)
	{
		*list = newNode;			//直接让链表的第一个节点为新节点
		return;
	}

	//正常情况：链表不为空链表
	LNode *cur = *list;
	while (cur->next != NULL)		//遍历链表，知道list为最后一个节点
	{
		cur = cur->next;
	}
	cur->next = newNode;
}
//头删

void LPopFront(LNode **list)
{
	assert(list != NULL);	// 变量地址不为 NULL
	assert(*list != NULL);	// 不能是空链表
	LNode *del = *list;		//为了方便释放，将头结点存放到一个变量中
	*list = del->next;

	free(del);			//释放空间，否则del会成为野指针，
}
//尾删
void LPopBack(LNode **list)
{
	assert(list != NULL);	// 变量地址不为 NULL
	assert(*list != NULL);	// 不能是空链表

	//只有一个节点的情况
	if ((*list)->next == NULL)
	{
		free(*list);
		*list = NULL;			//直接让链表的第一个节点为新节点
		return;
	}
	LNode *del;
	LNode *cur = *list;
	while (cur->next->next != NULL)//遍历查找倒数第二个节点
	{
		cur = cur->next;
	}
	del = cur->next;		//del指向最后一个节点
	cur->next = NULL;		//将倒数第二个节点的next置空
	free(del);
}