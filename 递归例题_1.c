/**
设计一个算法销毁一个不带头结点的单链表
f(L)  不做任何事件 当L为空
f(L)  f(L->next); free(L); 当L非空


void release(LinkList *L)
{
    if (L != NULL)
    {
        release(L->next);
        free(L);
    }
}


假设a数组含有1，2，…，n，求其全排列。
思路:设f(a，n，k)为a[0..k]（k+1个元素）的所有元素的全
排序，为大问题。
则f(a，n，k-1)为a[0..k-1] （k个元素）的所有元素的全排
序，为小问题。
假设小问题已经知道,对于a[K]位置的，可以取a[0~k],在组合
再组合f(a，n，k-1)，则得到f(a，n，k) 。
f(a，n，k)  输出a 当k=0时(一个元素的全排列) 
f(a，n，k)  a[k]位置取a[0..k]任何之值， 
其他情况并组合f(a，n，k-1)的结果;
**/
#include <stdio.h>
void swap(int *i, int *j)
{
    int t;
    t = *j;
    *j = *i;
    *i = t;
}
void perm(int a[], int n, int k)
{
    int i, j;
    if (k == 0)
    {
        for (j = 0; j < n; j++)
            printf("%d", a[j]);
        printf("\n");
    }
    else
    {
        for (i = 0; i <= k; i++)
        {
            swap(&a[k], &a[i]);
            perm(a, n, k - 1);
            swap(&a[k], &a[i]);
        }
    }
}
int main()
{
    int n = 3, k = 2;
    int a[] = {1, 2, 3};
    perm(a, n, k);
}