/*
�����Ż���Bellman-Ford�㷨,ʱ�临�Ӷ� ƽ������� O(m)�������� O(nm)
ͼ�в����ڸ���������spfa�������ڸ���������٣����Ƕ����Ż���Bellman-Ford�㷨
ǰ��ÿ���ڲ�����������бߣ���������ÿ���߶�����£������a��С����b�Ż��С
spfa�Դ��ö���bfs�Ż��������д洢����Ҫ��С�������µĽڵ�
����˼·�Ǹ��¹�˭������˭ȥ���±���
��dijkstra�ǳ�����Ȼ˵��Ȩͼһ����dijkstra�㷨������ʵ�󲿷���ȨͼҲ������spfa
*/#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 100010;

int n, m;      // �ܵ���
int h[N], w[N], e[N], ne[N], idx;       // �ڽӱ�洢���б�
int dist[N];        // �洢ÿ���㵽1�ŵ����̾���
bool st[N];     // �洢ÿ�����Ƿ��ڶ�����

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}
// ��1�ŵ㵽n�ŵ�����·���룬�����1�ŵ��޷��ߵ�n�ŵ��򷵻�-1
int spfa()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;//��ʼ�����е�ľ���

    queue<int> q;//����һ�����д洢���д����µĵ�
    q.push(1);
    st[1] = true;//�ж�ÿ�����Ƿ��ڶ��е��У���ֹ�����д洢�ظ��ĵ�

    while (q.size())
    {
        auto t = q.front();
        q.pop();//ȡ����ͷ

        st[t] = false;//��ʱ��t�Ѿ����ڶ�����

        for (int i = h[t]; i != -1; i = ne[i])
        {//����������tΪ�������г���
            int j = e[i];
            if (dist[j] > dist[t] + w[i])//������³ɹ��Ļ�
            {
                dist[j] = dist[t] + w[i];
                if (!st[j])     // ����������Ѵ���j������Ҫ��j�ظ�����
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
