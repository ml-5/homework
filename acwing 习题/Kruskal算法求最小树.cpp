/*
稀疏图 O(mlogm)
*/
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100010, M = 200010, INF = 0X3f3f3f3f;
int n, m;
int p[N];
struct Edge
{
    int a, b, w;
    bool opeator < (const Edge &W)
    {
        return w < W.w;
    }
} edges[M];
int find(int x)
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}
int kruskal()
{
    sort(edges, edges + m); //将所有边按照权重大小从小到大排序
    for (int i = 1; i <= n; i++)
        p[i] = i;
    int res = 0, cnt = 0;
    for (int i = 0; i < m; i++)
    {
        int a = edges.a, b = edges.b, w = edges.w;
        a = find(a), b = find(b);
        if (a != b)
        {
            p[a] = b;
            res += w;
            cnt++;
        }
    }
    if (cnt < n - 1)
        return INF;
    return res;
}
int main()
{
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        edges[i] = {a, b, w};
    }

    int t = kruskal();

    if (t == INF)
        puts("impossible");
    else
        cout << t << endl;

    return 0;
}