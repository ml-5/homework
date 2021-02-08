//进击的奶牛 https://www.luogu.com.cn/problem/P1824#submit
#include <bits/stdc++.h>
using namespace std;
int n, c, l, r, a[100000 + 10];
bool juge(int m)
{
    int s = 0, last = 1;         //记录上一个位置
    for (int i = 2; i <= n; i++) //依次枚举每个牛栏
    {
        if (a[i] - a[last] < m)
            s++; //若此距离不满足答案的话，所需要的牛栏加一
        else
            last = i; //否则就更新上一次牛栏的位置
        if (s > n - c)
            return false; //若需要的牛栏数大于最大的牛栏数则不满足
    }
    return true;
}
bool juge2(int m)
{
    int ans = 1, last = 1;
    for (int i = 2; i <= n; i++)
    {
        if (a[i] - a[last] >= m)
        {
            ans++;
            last = i;
        }
    }
    if (ans >= c)
        return true;
    return false;
}
int main(void)
{
    scanf("%d%d", &n, &c);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    l = 1;
    r = a[n] - a[1];
    sort(a + 1, a + 1 + n);
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (juge2(mid))
            l = mid + 1;
        else
            r = mid - 1;
    }
    printf("%d\n", r);
    return 0;
}