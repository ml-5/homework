/**
也是基于分治
1.选数组中中间元素的下标作为确定分界点 mid=(l+r)>>1
(归并排序确定的是中间的位置，是下标的中间值；而快速排序是选择数组中的一个元素)
2.递归排序左右两边
3.归并—合二为一(双指针) 合并两个有序数组
快速排序是先分完之后，然后再递归两边
归并排序是先递归两边，然后再操作

时间复杂度：O(nlogn)

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
    int mid = (l + r) / 2;
    merge_sort(q, l, mid);
    merge_sort(q, mid + 1, r);
    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)
    {
        if (q[i] <= q[j])
            tmp[k++] = q[i++];
        else
            tmp[k++] = q[j++];
    }
    while (i <= mid)
        tmp[k++] = q[i++];
    while (j <= r)
        tmp[k++] = q[j++];
    for (int i = l, j = 0; i <= r; i++, j++)
        q[i] = tmp[j];
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> q[i];
    merge_sort(q, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << q[i] << " ";
    return 0;
}