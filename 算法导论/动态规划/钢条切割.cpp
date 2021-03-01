/*
1.刻画一个最优解的结构特征
2.递归的调用最优解的值
3.计算出最优解的值，通常采用自底向上的方法
4.利用已经计算出的信息构造一个最优解

钢条切割的朴素做法 rn=max(rn,r1+rn-1,r2+rn-2.....)
第一个参数pn对应不切割，直接出售n英寸的钢条的方案，与其它n-1个参数对应另外n-1中方案对比


*/


#include <iostream>
#include <algorithm>
using namespace std;
int pi[11] = {0, 1, 5, 8},pimax[11]={0,1,5,8,9,10,17,17,20,24,30};
int main()
{
    int i, k, j;
    for (i = 4; i <= 10; i++)
    {
        for (j = 1, k = i - 1; j <= k; j++, k--)
        {
            pimax[i] = max(pimax[i], pi[j] + pi[k]);
        }
        
    }
    for (int i = 1; i <= 10; i++)
        printf("%d  %d \n", i, pimax[i]);
}