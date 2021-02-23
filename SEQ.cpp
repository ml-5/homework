#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int a[N], n;
int main()
{
    scanf("%d", &n);
    // for(int i=0;i<n;i++)
    int rmax[n], max = -N;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        if (i == 0)
            rmax[i] = a[i];
        if (i != 0 && rmax[i - 1] >= 0)
        {
            rmax[i] = a[i] + rmax[i - 1];
        }
        else if (rmax[i - 1] < 0)
        {
            rmax[i] = a[i];
        }
        if (max < rmax[i])
            max = rmax[i];
    }
    printf("%d", max);
}