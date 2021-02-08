#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int a[N], n;
int main(void)
{
    int s = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a + n);
    for (int i = 0; i < n; i++)
        s += abs(a[i] - a[n / 2]);
    printf("%d", s);
}
