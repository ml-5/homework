/*
并查集维护额外信息，并查集中每个集合是一棵树的形式，不管题目中告诉的两个元素是同类还是异类，只要知道两个动物的关系，就把他们放到一个集合里面中，
就可以推断出来同一个集合中所有动物的关系，那么如何确定他们之间的关系呢？
记录每个点与根节点之间的距离，表示两者的关系，从而推断出任意两点之间的关系，如果某个点到根节点距离为1的话，表示他可以吃根节点，
距离为2表示他可以被根节点吃，距离为3的话表示与根节点同类。
比如在一个组织中，我不需要知道任意两个人之间的关系，这样的话是n^2级别，只需要知道每个人与领袖之间的关系，然后可以推断出来任意两个人之间的关系
*/
#include <iostream>
using namespace std;
const int N = 50010;
int n, m;
int p[N], d[N];
int find(int x)
{
    if (p[x] != x)
    {
        int t = find(p[x]);
        d[x] += d[p[x]];
        p[x] = t;
    }
    return p[x];
}

int main()
{
    cin>>n>>m;

    for (int i = 1; i <= n; i ++ ) p[i] = i;

    int res = 0;
    while (m -- )
    {
        int t, x, y;
        cin>>t>>x>>y;

        if (x > n || y > n) res ++ ;
        else
        {
            int px = find(x), py = find(y);
            if (t == 1)
            {
                if (px == py && (d[x] - d[y]) % 3) res ++ ;
                else if (px != py)
                {
                    p[px] = py;
                    d[px] = d[y] - d[x];//因为xy同类，所以(d[px]+d[x]-d[y])%3==0
                }
            }
            else
            {
                if (px == py && (d[x] - d[y] - 1) % 3) res ++ ;
                else if (px != py)
                {
                    p[px] = py;
                    d[px] = d[y] + 1 - d[x];
                }
            }
        }
    }
    cout<<res;
    return 0;
}