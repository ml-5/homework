/*
����ͼ ʱ�临�Ӷ��� O(n^2+m), n ��ʾ������m ��ʾ����
���ذ�prim�㷨��dijkstra�㷨�ǳ�����
*/
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 510, INF = 0x3f3f3f3f;

int n, m;           // n��ʾ����
int g[N][N];        // ����ͼ���ڽӾ��󣬴洢���б�
int dist[N];        // �洢�����㵽��ǰ��С�������ľ���
bool st[N];         // �洢ÿ�����Ƿ��Ѿ�����������

// ���ͼ����ͨ���򷵻�INF(ֵ��0x3f3f3f3f), ���򷵻���С������������Ȩ��֮��
int prim()
{
    memset(dist, 0x3f, sizeof dist);//��ʼ������

    int res = 0;//��С���������б߳���֮��
    for (int i = 0; i < n; i ++ )
//����n�Σ������dijkstra��n-1����Ϊ�Ѿ���ѡ����һ���㣬ʣ��n-1����
//������һ���㶼δѡ�У�������n
    {
        int t = -1;
        for (int j = 1; j <= n; j ++ )//ÿ�ε����У��ҵ��������������ĵ�
        //�������ڵ�ǰ����������ͨ���еĵ�
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
    //˵��ͼ����ͨ
        if (i && dist[t] == INF) return INF;

        if (i) res += dist[t];
        st[t] = true;
        //��t������t������������㵽���ϵľ���
        //dijkstra�Ǹ��µ����ľ���
        for (int j = 1; j <= n; j ++ ) dist[j] = min(dist[j], g[t][j]);
    }
    return res;
}

int main()
{
    cin>>n>>m;

    memset(g, 0x3f, sizeof g);//��ʼ��

    while (m -- )
    {
        int a, b, c;
        cin>>a>>b>>c;
        g[a][b] = g[b][a] = min(g[a][b], c);//�ر߱�����С�ߣ�����ͼ�����α�
    }

    int t = prim();

    if (t == INF) puts("impossible");//���е㲻��ͨ��������������
    else cout<<t<<endl;

    return 0;
}