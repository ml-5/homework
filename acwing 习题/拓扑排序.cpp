/*
求拓扑序是图的宽搜很经典的应用，首先拓扑序列是针对有向图来说，无向图没有拓扑序列
对于图中每一条有向边(x,y)，x都出现在y的前面，则称这个点序列为图的拓扑序列，
也就是说所有边都是从前指向后的
存在环的话一定不存在拓扑序，可以证明一个有向无环图一定存在拓扑序列，所以有向无环图被称为
拓扑图，可以证明一个有向无环图至少存在一个入度为0的点
当前入度为0的可以作为起点，所以求拓扑序列的第一步是把所有入度为0的点入队，然后就是一个宽搜
的过程
时间复杂度O(n+m), n表示点数，m表示边数

bool topsort()
{
    int hh=0,tt=-1;
    for(int i=1;i<=n;i++)
    {
        if(!d[i])
        q[++tt]=i;
    }
    while (hh <= tt)//队列不空时
    {
        int t = q[hh ++ ];//取出队头元素

        for (int i = h[t]; i != -1; i = ne[i])//枚举所有出边
        {
            int j = e[i];
            if (-- d[j] == 0)//
                q[ ++ tt] = j;
        }
    }
    // 如果所有点都入队了，说明存在拓扑序列；否则不存在拓扑序列。
    return tt == n - 1;
}*/
#include <cstring>
#include <iostream>

using namespace std;

const int N = 100010;

int n, m;
int h[N], e[N], ne[N], idx; //邻接表的存储方式
int d[N];                   //点的入度
int q[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool topsort()
{
    int hh = 0, tt = -1; //tt为-1还是0取决于你在++t时，队中是否已经插入元素
    //迷宫那道题已经把起点入队了，所以从0开始

    for (int i = 1; i <= n; i++)
        if (!d[i])
            q[++tt] = i; //队列中始终放入入度为0的元素

    while (hh <= tt)
    {
        int t = q[hh++];

        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (--d[j] == 0)
                q[++tt] = j;
        }
    }

    return tt == n - 1; //判断是否所有点都入队
}
int main()
{
    cin >> n >> m;

    memset(h, -1, sizeof h);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        add(a, b);

        d[b]++;
    }

    if (!topsort())
        puts("-1");
    else
    {
        for (int i = 0; i < n; i++)
            cout << q[i] << ' ';
        puts("");
    }

    return 0;
}
