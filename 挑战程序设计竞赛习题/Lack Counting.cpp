#include <iostream>
const int MAX_N = 101;
char filed[MAX_N][MAX_N];
void dfs(int x, int y)
{
    filed[x][y] = '.';
    for (int dx = -1; dx <= 1; dx++)
        for (int dy = -1; dy <= 1; dy++)
        {
            int nx = x + dx, ny = y + dy;
            if (0 <= nx && nx < N && 0 <= ny && ny < M && filed[nx][ny] == 'W')
                dfs(nx, ny);
        }
    return;
}
void solve()
{
    int res = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            if (filed[i][j] == 'W')
            {
                dfs(i, j);
                res++;
            }
    }
    cout << res << endl;
}