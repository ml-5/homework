#include <bits/stdc++.h>
#include <queue>
using namespace std;
const int maxn = 105;
int vis[maxn][maxn];
char s[maxn][maxn];
in cnt = 0;
int dir[8][2] = {{0, 1}, {1, -1}, {-1, -1}, {-1, 0}, {0, -1}, {-1, 1}, {1, 0}, {1, 1}} typede struct Node
{
    int x, y;
} node;
void bfs(int x, int y)
{
    node p, t;
    queue<node> q;
    p.x = x;
    p.y = y;
    q.push(p);
    while (!q.empty())
    {
        p = q.front();
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            t.x = p.x + dir[i][0];
            t.y = p.y + dir[i][1];
            if (t.x < 0 || t.x >= n || t.y < 0 || t.y >= m)
                continue;
        }
        if (!vis[t.x][t.y] && s[t.x][t.y] == '@')
        {
            vis[t.x][t.y] == 1;
            q.push(t);
        }
    }
