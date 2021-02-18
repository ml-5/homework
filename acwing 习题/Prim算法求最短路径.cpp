/*
稠密图 时间复杂度是 O(n^2+m), n 表示点数，m 表示边数
朴素版prim算法和dijkstra算法非常相似
*/
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 510, INF = 0x3f3f3f3f;

int n, m;           // n表示点数
int g[N][N];        // 稠密图用邻接矩阵，存储所有边
int dist[N];        // 存储其他点到当前最小生成树的距离
bool st[N];         // 存储每个点是否已经在生成树中

// 如果图不连通，则返回INF(值是0x3f3f3f3f), 否则返回最小生成树的树边权重之和
int prim()
{
    memset(dist, 0x3f, sizeof dist);//初始化距离

    int res = 0;//最小生成树所有边长度之和
    for (int i = 0; i < n; i ++ )
//迭代n次，这里的dijkstra是n-1，因为已经先选中了一个点，剩下n-1个点
//而这里一个点都未选中，所以是n
    {
        int t = -1;
        for (int j = 1; j <= n; j ++ )//每次迭代中，找到集合外距离最近的点
        //集合是在当前生成树，连通块中的点
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
    //说明图不连通
        if (i && dist[t] == INF) return INF;

        if (i) res += dist[t];
        st[t] = true;
        //用t更新与t相关联的其他点到集合的距离
        //dijkstra是更新到起点的距离
        for (int j = 1; j <= n; j ++ ) dist[j] = min(dist[j], g[t][j]);
    }
    return res;
}

int main()
{
    cin>>n>>m;

    memset(g, 0x3f, sizeof g);//初始化

    while (m -- )
    {
        int a, b, c;
        cin>>a>>b>>c;
        g[a][b] = g[b][a] = min(g[a][b], c);//重边保留最小边，无向图建两次边
    }

    int t = prim();

    if (t == INF) puts("impossible");//所有点不连通，不存在生成树
    else cout<<t<<endl;

    return 0;
}