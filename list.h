#pragma once
#include <stdlib.h>
#include<string.h>
#include<assert.h>
#include<stdio.h>

typedef int DataType;

#define MAX_SIZE (100)


typedef struct SeqList
{
	DataType array[MAX_SIZE];
	int size;                      // 保存表里已经存了的数据个数 (可为下标)
}SeqList;

//初始化
void SLInit(SeqList *pSeq)
{
	assert(pSeq != NULL);
	pSeq->size = 0;              //到这里已经可以完成初始化，将个数设置为了0个
	memset(pSeq->array, NULL, MAX_SIZE * sizeof(DataType));
}

//销毁
void SeqListDestory(SeqList *pSeq)
{
	assert(pSeq != NULL);
	pSeq->size = 0;
	memset(pSeq->array, NULL, MAX_SIZE * sizeof(DataType));
}

//增加(插入|头插、中插、尾插)

//尾插
void LPushBack(SeqList *pSeq,DataType data)
{
	assert(pSeq != NULL);
	assert(data != NULL);

	if (pSeq->size == MAX_SIZE)
	{
		printf("已经满了！\n");
		return;
	}
	else
	{
		pSeq->array[pSeq->size] = data;
		pSeq->size++;
	}
}

//头插
void LPushFront(SeqList *pSeq, DataType data)
{
	assert(pSeq != NULL);
	assert(data != NULL);

	if (pSeq->size == MAX_SIZE)
	{
		printf("已经满了！\n");
		return;
	}
	else
	{
		if (pSeq->size)
		{
			for (int i = pSeq->size; i > 0; i--)
			{
				pSeq->array[i] = pSeq->array[i-1];
			}
		}
		pSeq->array[0] = data;
		pSeq->size++;
	}
}

//中间插入，在POS所在的位置

void SLInsert(SeqList *pSeq, size_t pos, DataType data)
{
	assert(pSeq != NULL);
	assert(data != NULL);
	assert(pos >= 0 && pos <= pSeq->size);

	if (pSeq->size == MAX_SIZE)
		printf("已经满了\n");
	else
	{
		for (int i = pSeq->size; i > pos; --i)
		{
			pSeq->array[i] = pSeq->array[i - 1];
		}
		pSeq->array[pos] = data;
		pSeq->size++;
	}
}
//删除
void SLErase(SeqList *pSeq, size_t pos)
{
	assert(pSeq != NULL);
	assert(pos >= 0 && pos <= pSeq->size);
	assert(pSeq->size > 0);

	for (int i = pos; i < pSeq->size; i++)
	{
		pSeq->array[i] = pSeq->array[i + 1];
	}
	pSeq->size--;

}
//删除指定数
void SLRemove(SeqList *pSeq, DataType data)
{
	int pos = SLFind(pSeq, data);
	if (pos != -1)
	{
		SLErase(pSeq, pos);
	}
	else
		return;
}
//修改POS所在的下标
void SLModify(SeqList *pSeq, size_t pos, DataType data)
{
	assert(pos >= 0 && pos <= pSeq->size);
	pSeq->array[pos] = data;
}
//查找
int SLFind(SeqList *s1, DataType data)
{
	for (int i = 0; i < s1->size; i++)
	{
		if (s1->array[i] == data)
			return i;
	}
	return -1;
}
//打印
void SLPrint(SeqList *pSeq)
{
	assert(pSeq != NULL);

	for (int i = 0; i < pSeq->size; i++)
		printf("%d ", pSeq->array[i]);
	printf("\n");
}

//冒泡排序

void SLBulleSort(SeqList *pSeq)
{
	assert(pSeq != NULL);
	for (int i = 0; i < pSeq->size; i++)
	{
		int ISort = 1;
		for (int j = 1; j < pSeq->size - i; j++)
		{
			if (pSeq->array[j - 1] > pSeq->array[j])
			{
				int t = pSeq->array[j - 1];
				pSeq->array[j - 1] = pSeq->array[j];
				pSeq->array[j] = t;
				ISort = -1;
			}
		}
		if (ISort == 1)
			return;
	}
}

int SLBinarraySearch(SeqList *pSeq, DataType data)
{
	assert(pSeq != NULL);
	SLBulleSort(pSeq);
	int left = 0;
	int right = pSeq->size - 1;
	int ret = -1;
	if (pSeq->size != 0)
	{
		while (right >= left)
		{
			int mid = left + (right - left) / 2;
			if (pSeq->array[mid] > data)
				right = mid - 1;
			else if (pSeq->array[mid] < data)
				left = mid + 1;
			else if (pSeq->array[mid] == data)
			{
				ret = mid;
				break;
			}
		}
	}
	return ret;
}
//使用场景
void Test()
{
	SeqList pL;
	SLInit(&pL);
	for (int i = 0; i < 10; i++)
	{
		LPushBack(&pL, 50 - i);
	}
	SLPrint(&pL);
	SLBulleSort(&pL);
	SLPrint(&pL);
	int ret = SLBinarraySearch(&pL, 40);
	if (ret != -1)
		printf("下标为：%d\n", ret);
	else
		printf("没有找到！！\n");
}




