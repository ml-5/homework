//假定数组初始的时候都是0
#include <iostream>
using namesapce std;
const int N = 100010;
int n, m;
int a[N], b[N]; //a是b前缀和 b是a的差分
void insert(int l, int r, int c)
{
    b[l] += c;
    b[r + 1] -= c;
}
int main(void)
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
        insert(i, i, a[i]);
    while (m--)
    {
        int l, r, c;
        scanf("%d%d%d", &l, &r, &c);
        insert(l, r, c);
    }
    for (int i = 1; i <= n; i++)
        b[i] += b[i - 1];
    for (int i = 1; i <= n; i++)
        printf("%d ", b[i]);
    return 0;
}