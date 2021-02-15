/*
���бߵĳ��ȶ���1 �������ǿ����ÿ��������·
queue<int> q;
st[1]=true;
q.push(1);
while(q.size())
{
    int t=q.front();
    q.pop();//ȡ����ͷ��Ԫ��
    for(int i=h[t],i!=-1;i=ne[i])
    {
        int j=e[i];
        if(!st[j])
        {
            st[j]=true;
            q.push(j);// ��ʾ��j�Ѿ���������
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
    int hh = 0, tt = 0; //�����ͷ����β
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
    memset(h, -1, sizeof h); //��ʼ����ͷ

    for (int i = 0; i < m; i++)
    { //�������б�
        int a, b;
        cin >> a >> b;
        add(a, b);
    }

    cout << bfs() << endl;

    return 0;
}