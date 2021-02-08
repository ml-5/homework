//筛法求素数(空间换时间)
//思路:把2~n中的所有数列出来，然后从2开始，先划掉n以内2的所有倍数，
//然后从下一个剩下的数开始(必然是素数)开始,
//划掉n以内的所有倍数最后剩下的数，都是素数
#include <stdio.h>
#define MAX_NUM 100
int IsPrime[MAX_NUM + 1];//注意下标
int main()
{
    for (int i = 2; i <= MAX_NUM; i++) //开始假设所有数都是素数
        IsPrime[i] = 1;
    for (int i = 2; i <= MAX_NUM; i++) //每次将一个素数的所有倍数标记为非素数
        if (IsPrime[i])                //只标记素数的倍数
            for (int j = 2 * i; j <= MAX_NUM; j += i)
                IsPrime[j] = 0;
    for (int i = 2; i <= MAX_NUM; i++)
        if (IsPrime[i])
            printf("%d\t",i);
    return 0;
}
