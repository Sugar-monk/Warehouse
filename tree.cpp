#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>

struct TreeLinkNode {
	int val;
	struct TreeLinkNode *left;
	struct TreeLinkNode *right;
	struct TreeLinkNode *next;
	TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

	}
};

/*
����һ�������������е�һ����㣬���ҳ��������˳�����һ����㲢�ҷ��ء�
ע�⣬���еĽ�㲻�����������ӽ�㣬ͬʱ����ָ�򸸽���ָ�롣
*/


class Solution {
public:
	TreeLinkNode* GetNext(TreeLinkNode* pNode)
	{
		if (pNode == NULL)
			return NULL;
		//��ǰ�ڵ������������
		if (pNode->right)
		{
			pNode = pNode->right;
			while (pNode->left)
				pNode = pNode->left;
		}
		else
		{
			//��ǰ�ڵ�������������ڣ�
			TreeLinkNode* pParent = pNode->next;
			while (pParent && pParent->right == pNode)
			{
				pNode = pParent;
				pParent = pNode->next;
			}

			pNode = pParent;
		}

		return pNode;
	}
};