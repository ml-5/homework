/*
队列优化的Bellman-Ford算法,时间复杂度 平均情况下 O(m)，最坏情况下 O(nm)
图中不存在负环才能用spfa，但存在负环情况较少，它是队列优化的Bellman-Ford算法
前者每次内层迭代遍历所有边，但并不是每条边都会更新，比如点a变小，点b才会变小
spfa对此用队列bfs优化，队列中存储所有要变小，待更新的节点
基本思路是更新过谁，再拿谁去更新别人
和dijkstra非常像，虽然说正权图一般用dijkstra算法，但其实大部分正权图也可以用spfa
*/#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 100010;

int n, m;      // 总点数
int h[N], w[N], e[N], ne[N], idx;       // 邻接表存储所有边
int dist[N];        // 存储每个点到1号点的最短距离
bool st[N];     // 存储每个点是否在队列中

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}
// 求1号点到n号点的最短路距离，如果从1号点无法走到n号点则返回-1
int spfa()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;//初始化所有点的距离

    queue<int> q;//定义一个队列存储所有待更新的点
    q.push(1);
    st[1] = true;//判断每个点是否在队列当中，防止队列中存储重复的点

    while (q.size())
    {
        auto t = q.front();
        q.pop();//取出队头

        st[t] = false;//此时点t已经不在队列中

        for (int i = h[t]; i != -1; i = ne[i])
        {//遍历更新以t为起点的所有出边
            int j = e[i];
            if (dist[j] > dist[t] + w[i])//如果更新成功的话
            {
                dist[j] = dist[t] + w[i];
                if (!st[j])     // 如果队列中已存在j，则不需要将j重复插入
                {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }

    return dist[n];
}

int main()
{
    cin>>n>>m;

    memset(h, -1, sizeof h);

    while (m -- )
    {
        int a, b, c;
        cin>>a>>b>>c;
        add(a, b, c);
    }

    int t = spfa();

    if (t  > 0x3f3f3f3f /2) puts("impossible");
    else cout<<t;

    return 0;
}
