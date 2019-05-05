#pragma once
#include "lish.h"
//#include <stdio.h>

//从尾到头打印单链表

void PrintReverse(ListNode *first)
{
	ListNode *end = NULL;                        //定义最后一个结点（打印过的或者打印前的最后结点即空字符）
	while (end != first)
	{
		ListNode *cur = first;                  //将链表的第一个结点的地址保存到cur中
		while (cur->next != end)                //开始查找未打印的倒数第一个结点
		{
			cur = cur->next;
		}
		printf("%d \n", cur->data);
		end = cur;                              //将打印过的结点的地址保存到end中，为下一次循环使用
	}
}

void PrintReverse1(ListNode *first)
{
	if (first->next == NULL)
	{
		printf("%d \n", first->data);
		return;
	}
	PrintReverse1(first->next);
	printf("%d \n", first->data);
}
void Test()
{
	ListNode *first;
	ListInit(&first);
	ListPushFront(&first, 5);
	ListPushFront(&first, 6);
	ListPushFront(&first, 9);
	ListPushFront(&first, 10);
	PrintReverse1(first);
}