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
	int size;                      // ��������Ѿ����˵����ݸ��� (��Ϊ�±�)
}SeqList;

//��ʼ��
void SLInit(SeqList *pSeq)
{
	assert(pSeq != NULL);
	pSeq->size = 0;              //�������Ѿ�������ɳ�ʼ��������������Ϊ��0��
	memset(pSeq->array, NULL, MAX_SIZE * sizeof(DataType));
}

//����
void SeqListDestory(SeqList *pSeq)
{
	assert(pSeq != NULL);
	pSeq->size = 0;
	memset(pSeq->array, NULL, MAX_SIZE * sizeof(DataType));
}

//����(����|ͷ�塢�в塢β��)

//β��
void LPushBack(SeqList *pSeq,DataType data)
{
	assert(pSeq != NULL);
	assert(data != NULL);

	if (pSeq->size == MAX_SIZE)
	{
		printf("�Ѿ����ˣ�\n");
		return;
	}
	else
	{
		pSeq->array[pSeq->size] = data;
		pSeq->size++;
	}
}

//ͷ��
void LPushFront(SeqList *pSeq, DataType data)
{
	assert(pSeq != NULL);
	assert(data != NULL);

	if (pSeq->size == MAX_SIZE)
	{
		printf("�Ѿ����ˣ�\n");
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

//�м���룬��POS���ڵ�λ��

void SLInsert(SeqList *pSeq, size_t pos, DataType data)
{
	assert(pSeq != NULL);
	assert(data != NULL);
	assert(pos >= 0 && pos <= pSeq->size);

	if (pSeq->size == MAX_SIZE)
		printf("�Ѿ�����\n");
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
//ɾ��
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
//ɾ��ָ����
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
//�޸�POS���ڵ��±�
void SLModify(SeqList *pSeq, size_t pos, DataType data)
{
	assert(pos >= 0 && pos <= pSeq->size);
	pSeq->array[pos] = data;
}
//����
int SLFind(SeqList *s1, DataType data)
{
	for (int i = 0; i < s1->size; i++)
	{
		if (s1->array[i] == data)
			return i;
	}
	return -1;
}
//��ӡ
void SLPrint(SeqList *pSeq)
{
	assert(pSeq != NULL);

	for (int i = 0; i < pSeq->size; i++)
		printf("%d ", pSeq->array[i]);
	printf("\n");
}

//ð������

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
//ʹ�ó���
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
		printf("�±�Ϊ��%d\n", ret);
	else
		printf("û���ҵ�����\n");
}




