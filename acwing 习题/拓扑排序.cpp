/*
����������ͼ�Ŀ��Ѻܾ����Ӧ�ã����������������������ͼ��˵������ͼû����������
����ͼ��ÿһ�������(x,y)��x��������y��ǰ�棬������������Ϊͼ���������У�
Ҳ����˵���б߶��Ǵ�ǰָ����
���ڻ��Ļ�һ�������������򣬿���֤��һ�������޻�ͼһ�������������У����������޻�ͼ����Ϊ
����ͼ������֤��һ�������޻�ͼ���ٴ���һ�����Ϊ0�ĵ�
��ǰ���Ϊ0�Ŀ�����Ϊ��㣬�������������еĵ�һ���ǰ��������Ϊ0�ĵ���ӣ�Ȼ�����һ������
�Ĺ���
ʱ�临�Ӷ�O(n+m), n��ʾ������m��ʾ����

bool topsort()
{
    int hh=0,tt=-1;
    for(int i=1;i<=n;i++)
    {
        if(!d[i])
        q[++tt]=i;
    }
    while (hh <= tt)//���в���ʱ
    {
        int t = q[hh ++ ];//ȡ����ͷԪ��

        for (int i = h[t]; i != -1; i = ne[i])//ö�����г���
        {
            int j = e[i];
            if (-- d[j] == 0)//
                q[ ++ tt] = j;
        }
    }
    // ������е㶼����ˣ�˵�������������У����򲻴����������С�
    return tt == n - 1;
}*/
#include <cstring>
#include <iostream>

using namespace std;

const int N = 100010;

int n, m;
int h[N], e[N], ne[N], idx; //�ڽӱ�Ĵ洢��ʽ
int d[N];                   //������
int q[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool topsort()
{
    int hh = 0, tt = -1; //ttΪ-1����0ȡ��������++tʱ�������Ƿ��Ѿ�����Ԫ��
    //�Թ��ǵ����Ѿ����������ˣ����Դ�0��ʼ

    for (int i = 1; i <= n; i++)
        if (!d[i])
            q[++tt] = i; //������ʼ�շ������Ϊ0��Ԫ��

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

    return tt == n - 1; //�ж��Ƿ����е㶼���
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
