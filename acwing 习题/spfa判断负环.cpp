/*
时间复杂度是 O(nm)
*/
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 2010, M = 10010;

int n, m;      // 总点数
int h[N], w[M], e[M], ne[M], idx;       // 邻接表存储所有边
int dist[N], cnt[N]; 
// dist[x]存储1号点到x的最短距离，cnt[x]存储1到x的最短路中边数
bool st[N];     // 存储每个点是否在队列中


void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}

// 如果存在负环，则返回true，否则返回false。
bool spfa()
{
    // 不需要初始化dist数组，因为没有求距离，求的是是否存在负环
    // 原理：如果某条最短路径上有n个点（除了自己）
    //那么加上自己之后一共有n+1个点，由抽屉原理一定有两个点相同，所以存在环。
    queue<int> q;
    for (int i = 1; i <= n; i ++ )
    {
        q.push(i);
        st[i] = true;
    }
//这里最开始把所有元素入队，而不是只入第一个点，因为负环可能从任意一点开始

    while (q.size())
    {
        auto t = q.front();
        q.pop();

        st[t] = false;

        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;
                if (cnt[j] >= n) return true;       
// 如果从1号点到x的最短路中经过至少n条边，也就是n+1个点，则说明存在负环
                if (!st[j])
                {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }

    return false;
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

    if (spfa()) puts("Yes");
    else puts("No");

    return 0;
}