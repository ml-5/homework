/*
����������k���ߵ����·��ʱ�临�Ӷ�ΪO(mn)
*/
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 510, M = 10010;
struct Edge
{
    int a, b, c;
} edgs[M];
int n, m, k;
int dist[N]; //dist[x]�洢1��x����̾���
int last[N];
//��1�ߵ�n�ľ��룬����޷���1�ߵ�n,�򷵻�-1
void bellman_ford()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    // �����n�ε�����Ȼ���ɳ����ǲ���ʽ����˵������һ��������n+1�����·��
    //�ɳ���ԭ��·�������ٴ���������ͬ�ĵ㣬˵��ͼ�д��ڸ�Ȩ��·
    //�����·ʱ��������ڸ�Ȩ��·�����·��һ������
    for (int i = 0; i < k; i++) //����������k��
    {
        //����k�ε���֮���dist��������1�ŵ㾭��������k�����ߵ�ÿ�������̾���
        memcpy(last, dist, sizeof dist); //����dist���飬�Է�����
        for (int j = 0; j < m; j++)      //ÿ��ѭ�����бߣ���˴洢��ʽ������
        {
            auto e = edges[j];
            dist[e.b] = min(dist[e.b], last[e.a] + e.c);
        }
    }
    int main()
    {
        cin >> n >> m >> k;

        for (int i = 0; i < m; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            edges[i] = {a, b, c};
        }

        bellman_ford();
        //��Ϊ���ڸ�Ȩ�ߣ����ڵ����������ܱ��������������
        if (dist[n] > 0x3f3f3f3f / 2)
            puts("impossible");
        else
            cout << dist[n];

        return 0;
    }