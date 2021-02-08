#include <iostream>
#include <cstring>
const int maxn = 105;
char pic[maxn][maxn];
int m, n, idx[maxn][maxn];
void dfs(int r, int c, int id)
{
    if (r < 0 || c >= m || c < 0 || c >= n)
        return;
    if (idx[r][c] > 0 || pic[r][c] != '@')
        return 0;
    idx[r][c] = id;
    for (int dr = -1; dr <= 1; dr++)
        for (int dc = -1; dc <= 1; dc++)
            if (dr != 0 || dc != 0)
                dfs(r + dr, c + dc, id);
}
int main()
{
    while (scanf("%d %d", &m, &n) == 2 && m && n)
    {
        for (int i; i < m; i++)
            scanf("%s", pic[i]);
        memset(idx, 0, sizeof(idx));
        int cnt = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (idx[i][j] == 0 && pic[i][j == '@'])
                    dif(i, j, ++cnt);
        printf("%d\n", cnt);
    }
}
int main()

{
    while (scanf("%d %d", &n, &m) && (n + m))
    {
        memset(vis, 0, sizeof vis);
        cnt = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%s", s[i]);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && s[i][j] == '@')
                {
                    vis[i][j] = 1;
                    cnt++;
                    bfs(i, j);
                }
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
