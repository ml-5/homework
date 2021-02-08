#include <iostream>
using namespace std;
const int N = 1e6 + 10;
int q[N], tmp[N], n;
void Merge_sort(int q[], int l, int r)
{
    int mid = (l + r) >> 1;
    if (l >= r)
        return;
    Merge_sort(q, l, mid), Merge_sort(q, mid + 1, r);
    int i = l, j = mid + 1, k = 0;
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
int main(void)
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &q[i]);
    Merge_sort(q, 0, n - 1);
    for (int i = 0; i < n; i++)
        printf("%d ", q[i]);
    return 0;
}