/*
ʱ�临�Ӷ� O(n+m), n ��ʾ������m ��ʾ����
bool st[N];//�洢��Щ�㱻������
void dfs(int u)//dfs�ڵ�u
{
    st[u] = true; // st[u] ��ʾ��u�Ѿ���������

    for (int i = h[u]; i != -1; i = ne[i])//�Խڵ�u��ָ������δ���������Ľڵ�dfs
    {
        int j = e[i];
        if (!st[j]) dfs(j);
    }
}
*/
#include <cstring>//memset��Ҫ
#include <iostream>

using namespace std;

const int N = 100010, M = N * 2;

int n;
int h[N], e[M], ne[M], idx;
int ans = N;//ȫ�ִ�
bool st[N];

void add(int a, int b)
{
//e����洢���ǽڵ㱾���±��ʾ�ڵ��Ӧ���±�
//ne�����±��ʾ��ǰ�ڵ��Ӧ���±꣬�洢���ǵ�ǰ�ڵ���ָ����һ���ڵ���±�
//h����洢���ǽڵ��Ӧ���±꣬�±��ʾ�ڵ㱾��
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}
//dfs������uΪ���������Ľڵ���
int dfs(int u)
{
    st[u] = true;

    int size = 0, sum = 1;//size��ʾɾ���ڵ�u֮��ÿһ����ͨ��ڵ������ֵ
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (!st[j]){
            int s = dfs(j);//�ȿ��Ա�ʾ��jΪ�����Ľڵ�����Ҳ���Ա�ʾ����j����ͨ���С
            size = max(size, s);
            sum += s;
        }
    }
    size = max(size, n - sum);
    ans = min(ans, size);
    return sum;
}
int main()
{
    cin>>n;

    memset(h, -1, sizeof h);
    //cout<<idx<<endl; ��ʼ��Ϊ0
    for (int i = 0; i < n - 1; i ++ )//����n���ڵ㣬n-1����
    {
        int a, b;
        cin>>a>>b;
        add(a, b), add(b, a);
    }

    //dfs(1);
    dfs(n);//���ĸ��㿪ʼ�Ѷ�һ��

    cout<<ans<<endl;

    return 0;
}