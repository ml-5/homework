/**
归并排序 
1.确定分界点 l+r>>1
2.对左右进行排序
3.归并
4.将数据拷贝回
**/
#include <iostream>
using namespace std;
int n;
const int N = 1000010;
int q[N], tmp[N];
void merge_sort(int q[], int l, int r)
{
    if (l >= r)
        return;
    int mid = l + r >> 1;
    merge_sort(q, l, mid);
    merge_sort(q, mid + 1, r);
    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)
    {
        if (q[i] < q[j])
            tmp[k++] = q[i++];
        else
            tmp[k++] = q[j++];
        while (i <= mid)
            tmp[k++] = q[i++];
        while (j <= r)
            tmp[k++] = q[j++];
    }
    for (i = l, j = 0; i <= r; i++, j++)
        q[i] = tmp[j];
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &q[i]);
    for (int i = 0; i < n; i++)
        printf("%d", q[i]);
    return 0;
}