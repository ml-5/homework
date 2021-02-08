#include <iostream>
using namespace std;
int n;
const int maxn = 1e6 + 10;
int a[maxn];
void quick_sort(int a[], int l, int r)
{
    if (l >= r)
        return;
    int i = l - 1, j = r + 1, x = a[(l+r)/2];
    while (i < j)
    {
        do
            i++;
        while (a[i] < x);
        do
            j--;
        while (a[j] > x);
        if (i < j)
            swap(a[i], a[j]);
    }
    quick_sort(a, l, j);
    quick_sort(a, j+1, r);
}
int main(void)
{

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    quick_sort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}
