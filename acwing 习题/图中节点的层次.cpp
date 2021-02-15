/*
所有边的长度都是1 告诉我们可以用宽搜求最短路
queue<int> q;
st[1]=true;
q.push(1);
while(q.size())
{
    int t=q.front();
    q.pop();//取出队头的元素
    for(int i=h[t],i!=-1;i=ne[i])
    {
        int j=e[i];
        if(!st[j])
        {
            st[j]=true;
            q.push(j);// 表示点j已经被遍历过
        }
    }
}*/
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100010;
int n, m;
int h[N], e[N], ne[N], idx;
int d[N], q[N];
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
int bfs()
{
    int hh = 0, tt = 0; //定义队头，队尾
    q[0] = 1;
    memset(d, -1, sizeof d);
    d[1] = 0;

    while (hh <= tt)
    {
        int t = q[hh++];
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (d[j] == -1)
            {
                d[j] = d[t] + 1;
                q[++tt] = j;
            }
        }
    }
    return d[N];
}
int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof h); //初始化表头

    for (int i = 0; i < m; i++)
    { //输入所有边
        int a, b;
        cin >> a >> b;
        add(a, b);
    }

    cout << bfs() << endl;

    return 0;
}