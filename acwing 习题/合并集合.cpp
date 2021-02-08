#include <iostream>
using namespace std;
const int N = 100010;
int p[N]; //表示每个节点对应的父节点
int find(int x)
{ //返回x的根节点(所在集合的编号)+路径压缩
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        p[i] = i; //初始时，每个节点的树根是自己
    while (m--)
    {
        char op[2];
        int a, b;
        cin >> op >> a >> b;

        if (op[0] == 'M')
        {
            if (find(a) == find(b))
                continue;
            else
                p[find(a)] = find(b);
        }
        else
        {
            if (find(a) == find(b))
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
    return 0;
}