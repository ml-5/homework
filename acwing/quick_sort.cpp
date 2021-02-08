/**

快速排序 
1.确定分界点 
2.使分界点左边的元素小于等于x右边的元素大于等于x
3.递归处理左右两部分

**/
#include <iostream>
using namespace std;
const int N = 10e6 + 10;
int n;
int q[N];
void quick_sort(int q[], int l, int r)
{
    if (l >= r)
        return;
    int x = q[l], i = l - 1, j = r + 1;
    while (i < j)
    {
        do
            i++;
        while (q[i] < x);
        do
            j++;
        while (q[j] > x);
        if (i < j)
            swap(q[i], q[j]);
    }
    quick_sort(q, l, j);
    quick_sort(q, j + 1, r);
}
int main()
{
    scanf("%d ", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &q[i]);
    quick_sort(q, 0, n - 1);
    for (int i = 0; i < n; i++)
        printf("%d ", q[i]);
}