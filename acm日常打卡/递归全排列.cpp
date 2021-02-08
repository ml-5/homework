#include <bits/stdc++.h>
using namespace std;
int n, pd[100], used[100];
void print()
{
    int i;
    for (i = 0; i < n; i++)
        printf("%5d", used[i]);
    printf("\n");
}
void dfs(int k)
{
    if (k == n)
    {
        print();
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!pd[i])
        {
            pd[i] = 1;
            used[k] = i;
            dfs(k + 1);
            pd[i] = 0;
        }
    }
}
int main()
{
    scanf("%d", &n);
    dfs(0);
}