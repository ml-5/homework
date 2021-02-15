/*
��Դ���·:������յ㶼ȷ��
��Դ�����·:����һ����㵽����һ���յ�

���·�㷨�ص��ǽ�ͼ����ζ����ͱ�
���ص�dijkstra
ʱ�临�Ӷ�o(N^2+M) n��ʾ����,m��ʾ����,�Ƚ��ʺ��ó���ͼ�����ڽӾ�������
Ҳ���Ǳ����϶��ͼ���������m��O(n^2)��һ������
*/
#include <cstring>
#include <iostream>
using namespace std;
const int N = 510;
int n, m;
int g[N][N]; //�ڽӾ���洢ÿһ����
int dist[N]; //�洢1�ŵ㵽ÿ�������̾���
bool st[N];  //�洢ÿ��������·���Ƿ�ȷ��
//��1�ŵ㵽n�ŵ�����·����������ھͷ���-1
int dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0; //���ȳ�ʼ�����룬ֻ��������Ϊ0�����඼Ϊ������
    for (int i = 0; i < n - 1; i++)
    { //n�����г������֮�⣬����n-1������̾���δȷ����ÿѭ��һ�ξͿ���ȷ��һ�������̾���
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
        g[a][b] = min(g[a][b], c); //�����رߺ��Ի����������·����˵������̵ı߾Ϳ�����
    }
    cout << disjkstra << endl;
}