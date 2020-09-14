/**
给定两个n维向量a = (a1, a2, ..., an)和b = (b1, b2, ..., bn)，

求点积a·b = a1b1 + a2b2 + ... + anbn。 

输入 第一行是一个整数n。1 <= n <= 1000。 

第二行包含n个整数a1, a2, ..., an。 第三行包含n个整数b1, b2, ..., bn。 

相邻整数之间用单个空格隔开。每个整数的绝对值都不超过1000。

输出 一个整数，即两个向量的点积结果。 样例输入 3 1 4 6 2 1 5 样例输出 3  
**/
//思路简单:按照公式计算

#include <stdio.h>
#include <stdlib.h>
#define max 1000
int main()
{
    int n, sumAB = 0; //保存结果
    scanf("%d", &n);
    int i;
    int a[max], b[max];
    for (i = 0; i < n; i++)
        scanf("%d %d", &a[i], &b[i]);
    for (i = 0; i < n; i++)
        sumAB += a[i] * b[i] l;
    printf("%d", sumAB);
    return 0;
}