#pragma once
#include <assert.h>

struct BTreeNode;            //必须声明一下，不然数”:“StackDataType”与“BTreeNode *”的间接级别不同
typedef struct BTreeNode  * StackDataType;

#define MAX_SIZE  (100)

typedef struct Stack
{
	StackDataType array[MAX_SIZE];
	int			  top;            //表示当前个数
}	Stack;


//初始化/销毁

//初始化
void StackInit(Stack *pStack)
{
	pStack->top = 0;
}

//销毁

void StackDestroy(Stack *pStack)
{
	pStack->top = 0;
}
//增删查改

//增

void StackPush(Stack *pStack, StackDataType data)
{
	assert(pStack->top < MAX_SIZE);
	pStack->array[pStack->top++] = data;
}

//删

void StackPop(Stack *pStack)
{
	assert(pStack->top > 0);
	pStack->top--;
}

//查

//返回栈顶元素
StackDataType StackTop(const Stack *pStack)
{
	assert(pStack->top > 0);
	return pStack->array[pStack->top - 1];
}

//元素个数

int StackSize(const Stack *pStack)
{
	assert(pStack->top > 0);
	return pStack->top;
}

//是否满了

int StackFull(const Stack *pStack)
{
	return pStack->top >= MAX_SIZE;
}

//是否为空

int StackEmpty(const Stack *pStack)
{
	return pStack->top <= 0;
}

