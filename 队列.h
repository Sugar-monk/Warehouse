#pragma once

#include <stdlib.h>
#include<assert.h>

struct BTreeNode;

typedef struct BTreeNode * QDataType;

typedef struct QNode
{
	QDataType data;
	struct QNode *next;
}	QNode;

typedef struct Queue
{
	QNode *front;
	QNode *rear;
}	Queue;

static QNode * CreateNode(QDataType data)
{
	QNode *Node = (QNode *)malloc(sizeof(QNode));
	assert(Node);
	Node->data = data;
	Node->next = NULL;

	return Node;
}
//初始化/销毁

void QueueInit(Queue *pQueue)
{
	pQueue->front = pQueue->rear = NULL;
}

void QueueDestroy(Queue *pQueue)
{
	QNode *cur;
	QNode *next;
	for (cur = pQueue->front; cur != NULL; cur = next)
	{
		next = cur->next;
		free(cur);
	}
	pQueue->front = pQueue->rear = NULL;
}

//插入（尾插）

void QueuePush(Queue *pQueue, QDataType data)
{
	QNode *NewNode = CreateNode(data);

	if (pQueue->front == NULL)
	{
		pQueue->rear = pQueue->front = NewNode;
		return;
	}
	/*while (pQueue->rear->next !=NULL)                 //为什么不找到最后一个呢？？？
	{                                                   //因为队列是从后面插入的，
		pQueue->rear = pQueue->rear->next;
	}*/
	pQueue->rear->next = NewNode;
	pQueue->rear = NewNode;
	return;
}

//删除

void QueuePop(Queue *pQueue)
{
	assert(pQueue != NULL);            //不能传递空地址
	assert(pQueue->front != NULL);     //队列为空，无法删除

	QNode *cur = pQueue->front;
	pQueue->front = pQueue->front->next;
	free(cur);

	if (pQueue->front == NULL)         //如果此时为空队列，rear也应该置为空
	{
		pQueue->rear = NULL;
	}
}

//查看队首元素

QDataType QueueFront(Queue *pQueue)
{
	assert(pQueue != NULL);            //不能传递空地址
	assert(pQueue->front != NULL);     //队列为空，不能查看
	return pQueue->front->data;
}

//查看是否为空

int QueueEmpty(Queue *pQueue)
{
	return pQueue->front == NULL;
}

//返回数据个数

int QueueSize(Queue *pQueue)
{
	QNode *cur;
	int size = 0;
	for (cur = pQueue->front; cur != NULL; cur = cur->next)
	{
		size++;
	}
	return size;
}