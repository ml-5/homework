/*
单源最短路:起点与终点都确定
多源汇最短路:任意一个起点到任意一个终点

最短路算法重点是建图，如何定义点和边
朴素的dijkstra
时间复杂度o(N^2+M) n表示点数,m表示边数,比较适合用稠密图，用邻接矩阵来存
也就是边数较多的图，比如边数m与O(n^2)是一个级别
*/
#include <cstring>
#include <iostream>
using namespace std;
const int N = 510;
int n, m;
int g[N][N]; //邻接矩阵存储每一条边
int dist[N]; //存储1号点到每个点的最短距离
bool st[N];  //存储每个点的最短路径是否确定
//求1号点到n号点的最短路，如果不存在就返回-1
int dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0; //首先初始化距离，只有起点距离为0，其余都为正无穷
    for (int i = 0; i < n - 1; i++)
    { //n个点中除了起点之外，还有n-1个点最短距离未确定，每循环一次就可以确定一个点的最短距离
        int t = -1;
        for (int j = 1; j < n; j++)
        {
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        }
        for (int j = 1; j <= n; j++)
            dist[j] = min(dist[j], dist[t] + g[t][j]);
        st[t] = true;
    }
    if (dist[n] == 0x3f3f3f3f)
        return -1;
    return dist[n];
}
int main()
{
    cin >> n >> m;
    memset(g, 0x3f, sizeof g);
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = min(g[a][b], c); //存在重边和自环，对于最短路径来说保留最短的边就可以了
    }
    cout << disjkstra << endl;
}