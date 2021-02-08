#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100010;
int a[N];int nums;
unsigned long result = 0;
void merge_sort(int array[], int l, int r)
{
    if (l >= r)
        return;
    int mid = (l + r) / 2;
    merge_sort(array, l, mid);
    merge_sort(array, mid + 1, r);
    int temp[r - l + 1];
    int lptr = l;
    int rptr = mid + 1;
    int tempptr = 0;
    while (lptr <= mid && rptr <= r)
    {
        if (array[lptr] <= array[rptr])
        {
            temp[tempptr++] = array[lptr++];
        }
        else
        {
            temp[tempptr++] = array[rptr++];
            result += (mid - lptr + 1); //注意这里，是直接加的，后面的不需要比较了。
        }
    }
    while (lptr <= mid)
    {
        temp[tempptr++] = array[lptr++];
    }
    while (rptr <= r)
    {
        temp[tempptr++] = array[rptr++];
    }
    for (int i = l, j = 0; i <= r; i++, j++)
    {
        array[i] = temp[j];
    }
}

int main()
{
    scanf("%d", &nums);
    for (int i = 0; i < nums; i++)
    {
        scanf("%d", &a[i]);
    }
    merge_sort(a, 0, nums - 1);
    cout << result;
    return 0;
}
