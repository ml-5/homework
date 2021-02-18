/*
经过不超过k条边的最短路，时间复杂度为O(mn)
*/
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 510, M = 10010;
struct Edge
{
    int a, b, c;
} edgs[M];
int n, m, k;
int dist[N]; //dist[x]存储1到x的最短距离
int last[N];
//求1走到n的距离，如果无法从1走到n,则返回-1
void bellman_ford()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    // 如果第n次迭代仍然会松弛三角不等式，就说明存在一条长度是n+1的最短路径
    //由抽屉原理，路径中至少存在两个相同的点，说明图中存在负权回路
    //求最短路时，如果存在负权回路，最短路不一定存在
    for (int i = 0; i < k; i++) //迭代不超过k次
    {
        //比如k次迭代之后的dist数组代表从1号点经过不超过k条边走到每个点的最短距离
        memcpy(last, dist, sizeof dist); //备份dist数组，以防串联
        for (int j = 0; j < m; j++)      //每次循环所有边，因此存储方式不限制
        {
            auto e = edges[j];
            dist[e.b] = min(dist[e.b], last[e.a] + e.c);
        }
    }
    int main()
    {
        cin >> n >> m >> k;

        for (int i = 0; i < m; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            edges[i] = {a, b, c};
        }

        bellman_ford();
        //因为存在负权边，最后节点的正无穷可能被其他正无穷更新
        if (dist[n] > 0x3f3f3f3f / 2)
            puts("impossible");
        else
            cout << dist[n];

        return 0;
    }