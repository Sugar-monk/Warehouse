#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"Queue.h"
#include"Stack.h"

typedef int TDataType;


//创建树的结构体


typedef struct BTreeNode
{
	TDataType	data;
	struct BTreeNode *left;
	struct BTreeNode *right;
}	BTreeNode;


//压栈
BTreeNode * QCreateNode(int data)              // 与Queue中的CreatNode重复
{
	BTreeNode *node = (BTreeNode *)malloc(sizeof(BTreeNode));
	node->data = data;
	node->left = node->right = NULL;

	return node;
}

//创建树

BTreeNode * CreateTree(int preOrder[], int size, int *pUsedSize)
{
	if (size <= 0)
	{
		*pUsedSize = 0;
		return NULL;
	}

	int leftUse;
	int rightUse;
	int rootValue = preOrder[0];
	if (rootValue == -1)
	{
		*pUsedSize = 1;
		return NULL;
	}

	BTreeNode *root = QCreateNode(rootValue);

	root->left = CreateTree(preOrder + 1, size - 1, &leftUse);
	root->right = CreateTree(preOrder + 1 + leftUse, size - 1 - leftUse, &rightUse);

	*pUsedSize = 1 + leftUse + rightUse;

	return root;
}


//前序/中序/后序   遍历：

//前序
void PreOrder(BTreeNode *root)
{
	if (root == NULL)
	{
		printf("-1 ");
		return;
	}
	printf("%d ", root->data);
	PreOrder(root->left);
	PreOrder(root->right);
}

//中序

void MiddleOrder(BTreeNode *root)
{
	if (root == NULL)
	{
		//printf("-1 ");
		return;
	}
	MiddleOrder(root->left);
	printf("%d ", root->data);
	MiddleOrder(root->right);
}
//后序

void AfterOrder(BTreeNode *root)
{
	if (root == NULL)
	{
		printf("-1 ");
		return;
	}
	AfterOrder(root->left);
	AfterOrder(root->right);
	printf("%d ", root->data);
}

//求树的结点的个数

//1.用后序遍历的方式：

int count = 0;
void BehindSize(BTreeNode *root)
{
	if (root == NULL)
	{
		return;
	}
	BehindSize(root->left);      //遍历左子树
	BehindSize(root->right);	 //遍历右子树
	count++;
}

//2.用子问题的方式求树的结点数：
int GetSize(BTreeNode *root)
{
	if (root == NULL)
	{
		return 0;
	}
	int left = GetSize(root->left);
	int right = GetSize(root->right);
	return left + right + 1;
}

//求树的叶子个数

int GetLeafSize(BTreeNode *root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->left == NULL && root->right)
	{
		return 1;
	}
	else
	{
		return GetLeafSize(root->left) + GetLeafSize(root->right);
	}
}

//求K层结点的个数

int GetFloorNodeSize(BTreeNode *root, int k)
{
	if ((NULL == root) & (NULL == root))
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}
	return GetFloorNodeSize(root->left, k - 1) + GetFloorNodeSize(root->right, k - 1);
}


//求二叉树的高度/深度

#define MAX(a,b) (a > b ? a : b)
int GetHightNode(BTreeNode *root)
{
	if (root == NULL)
	{
		return 0;
	}
	return MAX(GetHightNode(root->left),
		GetHightNode(root->right)) + 1;
}

//找树里面的数值

BTreeNode *Find(BTreeNode *root, TDataType data)
{
	if (root == NULL)
	{
		return NULL;                              //           (1)
		//这是一个空树
	}
	if (root->data == data)
	{
		return root;                             //            (2)
		//找到了，直接返回
	}
	BTreeNode *num = Find(root->left, data);     //从左子树开始找
	if (num != NULL)                             //如果从左子树找到了就直接返回值
	{
		return num;                               //           (3)
	}
	num = Find(root->right, data);                //没有从左子树找到，继续从右子树查找
//if (num == data) //错误！！地址不能与数值比较 //从右子树找到了，直接返回值
	if (num !=NULL)
	{
		return num;                               //           (4)
	}
	else                                          //左右子树都找了，都没找到，说明不存在，返回空指针
	{
		return NULL;                             //            (5)
	}
}

//层序遍历

void levelOrder(BTreeNode * root)
{
	Queue queue;
	QueueInit(&queue);
	BTreeNode *front;

	if (root == NULL)
	{
		return;
	}

	QueuePush(&queue, root);             //将root的地址插入到queue队列中
	while (!QueueEmpty(&queue))          //如果front的左右叶子都没有，那么queue将不会进行插入，既为空
	{
		front = QueueFront(&queue);      //将首元素地址赋给front结点
		QueuePop(&queue);

		//front 开始查看front的左右子树是否有data

		if (front->left != NULL)
		{
			QueuePush(&queue, front->left);
		}
		if (front->right != NULL)
		{
			QueuePush(&queue, front->right);
		}

		//层序遍历当前的front结点

		printf("%d ", front->data);
	}
	 
}


//判断一棵树是否是完全二叉树

int completelyTree(BTreeNode *root)
{
	Queue queue;
	//创建一个队列
	QueueInit(&queue);
	//初始化队列
	BTreeNode *front;
	//创建一个树结点

	//如果是一个空树，说明是完全二叉树
	if (root == NULL)
	{
		return 1;
	}

	QueuePush(&queue, root);                            //将树的地址存放到队列中
	while (!QueueEmpty(&queue))                         //如果树不为空，开始循环
	{
		front = QueueFront(&queue);
		QueuePop(&queue);
		if (front == NULL)                              //如果此时的结点为空，则开始进入判断环节
		{
			break;
		}
		QueuePush(&queue, front->left);                 //如果不是空结点，则开始压栈，将左右子树分别压进去
		QueuePush(&queue, front->right);
	}

	//开始判断是否是完全二叉树

	while (!QueueEmpty(&queue))  
	{
		front = QueueFront(&queue);                    
		QueuePop(&queue);
		if (front != NULL)                               //判断接下来的结点中有没有空结点，如果有空结点就
			                                             //说明不是完善全二叉树，返回0
		{
			return 0;
		}
	}
	return 1;                                            //如果从第一个空结点开始到队列结束都是空结点，就说明是                                                   //完全二叉树，返回1
}

//非递归遍历
//08-25-1：03：00

//前序遍历（非递归）
void PreOrderLoop(BTreeNode *root)
{
	Stack stack;
	StackInit(&stack);
	BTreeNode *cur, *top;
	cur = root;
	while (cur != NULL || !StackEmpty(&stack))           //结束条件:1、树为空 2、栈为空
	{
		while (cur != NULL)                             //遍历树的左子树
		{
			printf("%d " , cur->data);
			StackPush(&stack, cur);
			cur = cur->left;
		}
		top = StackTop(&stack);                        //所有的左子树遍历完，开始从最后一个左子树开始遍历右子树
		StackPop(&stack);
		cur = top->right;
	}
}

//中序遍历（非递归）
void MidOrderLoop(BTreeNode *root)
{
	Stack stack;
	StackInit(&stack);
	BTreeNode *cur, *top;
	cur = root;
	while (cur != NULL || !StackEmpty(&stack))
	{
		while (cur != NULL)
		{
			StackPush(&stack, cur);
			cur = cur->left;
		}
		top = StackTop(&stack);
		StackPop(&stack);
		//利用子问题的思想去打印右子树 
		printf("%d ", top->data);                   
		cur = top->right;
	}
}

//后序遍历（非递归）
void PostOrderLoop(BTreeNode *root)
{
	Stack stack;
	StackInit(&stack);
	BTreeNode *cur, *top, *last = NULL;
	cur = root;
	while (cur != NULL || !StackEmpty(&stack))
	{
		while (cur != NULL)
		{
			StackPush(&stack, cur);
			cur = cur->left;
		}
		top = StackTop(&stack);
		//如果右子树被遍历过了
		if (top->right == NULL || top->right == last)
		{
			StackPop(&stack);
			printf("%d ", top->data);
			last = top;
		}
		//如果右子树没有遍历，则继续遍历               
		else
		{
			cur = top->right;
		}
	}
}

//求镜像(递归)
void Mirror1(BTreeNode *root)
{
	if (root == NULL)
	{
		return;
	}
	Mirror1(root->left);
	Mirror1(root->right);

	//开始交换数据

	BTreeNode * t = root->left;
	root->left = root->right;
	root->right = t;
}

//求镜像（非递归）
void Mirror2(BTreeNode *root)
{
	Stack stack;
	StackInit(&stack);
	BTreeNode *cur, *top, *last = NULL;
	cur = root;

	while (cur != NULL || !StackEmpty(&stack))
	{
		while (cur != NULL)
		{
			StackPush(&stack, cur);
			cur = cur->left;
		}
		top = StackTop(&stack);
		if (top->right == NULL || top->right == last)
		{
			StackPop(&stack);
			BTreeNode * t = top->left;
			top->left = top->right;
			top->right = t;
			
			last = top;
		}
		else
		{
			cur = top->right;
		}
	}
}
void Test()
{
	//int preOrder[] = { 1, 2, 4, 8, -1, -1, 9, 11, -1, -1, -1, 5, -1, -1, 3, 6, -1, 10, -1, -1, 7 };
	int preOrder[] = { 1, 2, 4,-1,-1 ,5,-1,-1, 3 };
	int size = sizeof(preOrder) / sizeof(preOrder[0]);
	int usedsize;
	BTreeNode *root = CreateTree(preOrder, size, &usedsize);
	//printf("成功了");
#if 0
	PreOrder(root);
	printf("这是前序打印\n");
	MiddleOrder(root);
	printf("这是中序打印\n");
	AfterOrder(root);
	printf("这是后序打印\n");
	BehindSize(root);
	printf("%d\n", count);
	printf("%d\n", GetSize(root));
	printf("%d\n", GetFloorNodeSize(root, 4));
	if (Find(root, 11) != NULL)
	{
		printf("找到了\n");
	}
	else
		printf("没找到！！\n");

	levelOrder(root);
	printf("\n");
	completelyTree(root);
	if(completelyTree(root) == 1)
	{
		printf("是完全二叉树\n");
	}
	else
	{
		printf("不是完全二叉树");
	}


	
	PreOrderLoop(root);
	printf("\n");
	MidOrderLoop(root);
	printf("\n");
	PostOrderLoop(root);
#endif
	PreOrderLoop(root);
	printf("\n");
	Mirror1(root);
	//PreOrderLoop(root);
	printf("\n");
	//Mirror2(root);
	PreOrderLoop(root);
	printf("\n");

	//printf("hehe");
}

