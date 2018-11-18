#pragma once
#include <assert.h>

struct BTreeNode;            //��������һ�£���Ȼ����:��StackDataType���롰BTreeNode *���ļ�Ӽ���ͬ
typedef struct BTreeNode  * StackDataType;

#define MAX_SIZE  (100)

typedef struct Stack
{
	StackDataType array[MAX_SIZE];
	int			  top;            //��ʾ��ǰ����
}	Stack;


//��ʼ��/����

//��ʼ��
void StackInit(Stack *pStack)
{
	pStack->top = 0;
}

//����

void StackDestroy(Stack *pStack)
{
	pStack->top = 0;
}
//��ɾ���

//��

void StackPush(Stack *pStack, StackDataType data)
{
	assert(pStack->top < MAX_SIZE);
	pStack->array[pStack->top++] = data;
}

//ɾ

void StackPop(Stack *pStack)
{
	assert(pStack->top > 0);
	pStack->top--;
}

//��

//����ջ��Ԫ��
StackDataType StackTop(const Stack *pStack)
{
	assert(pStack->top > 0);
	return pStack->array[pStack->top - 1];
}

//Ԫ�ظ���

int StackSize(const Stack *pStack)
{
	assert(pStack->top > 0);
	return pStack->top;
}

//�Ƿ�����

int StackFull(const Stack *pStack)
{
	return pStack->top >= MAX_SIZE;
}

//�Ƿ�Ϊ��

int StackEmpty(const Stack *pStack)
{
	return pStack->top <= 0;
}

