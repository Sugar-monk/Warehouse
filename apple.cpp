#include <stdio.h>
#include <iostream>
using namespace std;
//题目：
/*只奶牛坐在一排，每个奶牛拥有 ai 个苹果，现在你要在它们之间转移苹果，
使得最后所有奶牛拥有的苹果数都相同，每一次，你只能从一只奶牛身上拿走
恰好两个苹果到另一个奶牛上，问最少需要移动多少次可以平分苹果，如果方案不存在输出 - 1。
*/
//算法思想：
//将每个奶牛拥有的苹果存放在一个数组中，苹果的总数除以奶牛的个数，
//如果有余数则不能平均分配，没有方案，否则检测每个奶牛多出来的个数是否是2的整数倍，
//如果不是，没有方案，否则将多出来的倍数相加就可以得到次数
int main()
{
	int arr[100] = {0};
	int num = 0;
	int sum = 0;
	bool flag = true;
	int count = 0;
	cin >> num;
	
	for (int i = 0; i < num; ++i)
	{
		cin >> arr[i];
		sum += arr[i];
	}
	if (sum%num != 0)
		flag = false;
	else
	{
		int ave = sum / num;
		for (int i = 0; i < num; ++i)
		{
			if ((arr[i] - ave) % 2 != 0)
				flag = false;
			else if (arr[i] > ave)
				count += (arr[i] - ave) / 2;
		}
	}
	if (!flag)
		cout << "-1" << endl;
	else
		cout << count << endl;
	return 0;
}