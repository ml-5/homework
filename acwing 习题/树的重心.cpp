/*
时间复杂度 O(n+m), n 表示点数，m 表示边数
bool st[N];//存储哪些点被遍历过
void dfs(int u)//dfs节点u
{
    st[u] = true; // st[u] 表示点u已经被遍历过

    for (int i = h[u]; i != -1; i = ne[i])//对节点u所指向所有未被遍历过的节点dfs
    {
        int j = e[i];
        if (!st[j]) dfs(j);
    }
}
*/
#include <cstring>//memset需要
#include <iostream>

using namespace std;

const int N = 100010, M = N * 2;

int n;
int h[N], e[M], ne[M], idx;
int ans = N;//全局答案
bool st[N];

void add(int a, int b)
{
//e数组存储的是节点本身，下标表示节点对应的下标
//ne数组下标表示当前节点对应的下标，存储的是当前节点所指向下一个节点的下标
//h数组存储的是节点对应的下标，下标表示节点本身
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}
//dfs返回以u为根的子树的节点数
int dfs(int u)
{
    st[u] = true;

    int size = 0, sum = 1;//size表示删除节点u之后，每一个连通块节点数最大值
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (!st[j]){
            int s = dfs(j);//既可以表示以j为子树的节点数，也可以表示包含j的连通块大小
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
    //cout<<idx<<endl; 初始化为0
    for (int i = 0; i < n - 1; i ++ )//输入n个节点，n-1条边
    {
        int a, b;
        cin>>a>>b;
        add(a, b), add(b, a);
    }

    //dfs(1);
    dfs(n);//从哪个点开始搜都一样

    cout<<ans<<endl;

    return 0;
}