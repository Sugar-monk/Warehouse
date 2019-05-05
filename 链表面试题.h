#pragma once
#include "lish.h"
//#include <stdio.h>

//��β��ͷ��ӡ������

void PrintReverse(ListNode *first)
{
	ListNode *end = NULL;                        //�������һ����㣨��ӡ���Ļ��ߴ�ӡǰ������㼴���ַ���
	while (end != first)
	{
		ListNode *cur = first;                  //������ĵ�һ�����ĵ�ַ���浽cur��
		while (cur->next != end)                //��ʼ����δ��ӡ�ĵ�����һ�����
		{
			cur = cur->next;
		}
		printf("%d \n", cur->data);
		end = cur;                              //����ӡ���Ľ��ĵ�ַ���浽end�У�Ϊ��һ��ѭ��ʹ��
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