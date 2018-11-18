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
//��ʼ��/����

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

//���루β�壩

void QueuePush(Queue *pQueue, QDataType data)
{
	QNode *NewNode = CreateNode(data);

	if (pQueue->front == NULL)
	{
		pQueue->rear = pQueue->front = NewNode;
		return;
	}
	/*while (pQueue->rear->next !=NULL)                 //Ϊʲô���ҵ����һ���أ�����
	{                                                   //��Ϊ�����ǴӺ������ģ�
		pQueue->rear = pQueue->rear->next;
	}*/
	pQueue->rear->next = NewNode;
	pQueue->rear = NewNode;
	return;
}

//ɾ��

void QueuePop(Queue *pQueue)
{
	assert(pQueue != NULL);            //���ܴ��ݿյ�ַ
	assert(pQueue->front != NULL);     //����Ϊ�գ��޷�ɾ��

	QNode *cur = pQueue->front;
	pQueue->front = pQueue->front->next;
	free(cur);

	if (pQueue->front == NULL)         //�����ʱΪ�ն��У�rearҲӦ����Ϊ��
	{
		pQueue->rear = NULL;
	}
}

//�鿴����Ԫ��

QDataType QueueFront(Queue *pQueue)
{
	assert(pQueue != NULL);            //���ܴ��ݿյ�ַ
	assert(pQueue->front != NULL);     //����Ϊ�գ����ܲ鿴
	return pQueue->front->data;
}

//�鿴�Ƿ�Ϊ��

int QueueEmpty(Queue *pQueue)
{
	return pQueue->front == NULL;
}

//�������ݸ���

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