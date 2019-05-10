/*************************************************************************
	> File Name: homework1.c
	> Author: linuxidc
	> Mail: linuxidc@linuxidc.com 
	> Created Time: Fri 10 May 2019 01:17:05 AM PDT
 ************************************************************************/

#include <stdio.h>


/*
 * 1.写一个函数返回参数二进制中 1 的个数
 * 比如： 15 0000 1111 4 个 1
 * 程序原型：
 * int count_one_bits(unsigned int value)
 * {
 *
 / 返回 1的位数
 }*/
#if 0
int count_one_bits(unsigned int value)
{

    int count = 1;
    while (value = value & value - 1)
    {

        ++count;
    }
    return count;
}
/*
 * 2.获取一个数二进制序列中所有的偶数位和奇数位，分别输出二进制序列。
 * */
#endif
#if 0
int main()
{
    
    int num,tmp,i=0;
    scanf("%d", &num);
    for(i = 0; i < 31; i+=2)
    {
        if(0^(num>>i))    //如果不是最后一位，执行输出函数
        {
            tmp = (num>>i)&1;
            printf("%d", tmp);
        }

        else            //否则跳出循环
            break;
    }
    printf("\n");
    for(i = 1; i < 32; i+=2)
    {
        if(0^(num>>i))
        {
            tmp = (num>>i)&1;
            printf("%d", tmp);
        }
        else
            break;
    }

    printf("\n");
    return 0;
}
#endif
#if 0
// 3. 输出一个整数的每一位。
int main()
{
    int num;
    scanf("%d", &num);
    printf("从个位开始依次为：");
    while(num)
    {
        int tmp;
        tmp = num%10;
        num /= 10;
        printf("%d ", tmp);
    }
    printf("\n");
    return 0;
}
#endif
#if 1
 /* 4.编程实现：
 * 两个int（32位）整数m和n的二进制表达中，有多少个位(bit)不同？
 * 输入例子:
 * 1999 2299
 * 输出例子:7
 */

int main()
{
    int first, end, tmp, count = 0;
    scanf("%d%d", &first,&end);
    tmp = first^end;
    while(tmp)
    {
        tmp = tmp&(tmp-1);
        ++count;
    }

    printf("%d\n", count);
    return 0;
}
#endif
