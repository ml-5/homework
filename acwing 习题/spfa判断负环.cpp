/*
ʱ�临�Ӷ��� O(nm)
*/
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 2010, M = 10010;

int n, m;      // �ܵ���
int h[N], w[M], e[M], ne[M], idx;       // �ڽӱ�洢���б�
int dist[N], cnt[N]; 
// dist[x]�洢1�ŵ㵽x����̾��룬cnt[x]�洢1��x�����·�б���
bool st[N];     // �洢ÿ�����Ƿ��ڶ�����


void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}

// ������ڸ������򷵻�true�����򷵻�false��
bool spfa()
{
    // ����Ҫ��ʼ��dist���飬��Ϊû������룬������Ƿ���ڸ���
    // ԭ�����ĳ�����·������n���㣨�����Լ���
    //��ô�����Լ�֮��һ����n+1���㣬�ɳ���ԭ��һ������������ͬ�����Դ��ڻ���
    queue<int> q;
    for (int i = 1; i <= n; i ++ )
    {
        q.push(i);
        st[i] = true;
    }
//�����ʼ������Ԫ����ӣ�������ֻ���һ���㣬��Ϊ�������ܴ�����һ�㿪ʼ

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
// �����1�ŵ㵽x�����·�о�������n���ߣ�Ҳ����n+1���㣬��˵�����ڸ���
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