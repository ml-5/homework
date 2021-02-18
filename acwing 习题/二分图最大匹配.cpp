//O(nm)，但实际运行时间远小于nm，可能是线性
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 510, M = 100010;
int n1, n2, m;
int h[N], e[M], ne[M], idx;
// 邻接表存储所有边
//匈牙利算法中只会用到从所枚举的第一个集合指向第二个集合的边
//所以这里只用存一个方向的边
int match[N]; // 存储第二个集合中的每个点当前匹配的第一个集合中的点是哪个
bool st[N];   // 对于第一个集合的所有点来说，第二个集合中的每个点是否已经被遍历过

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool find(int x)
{
    for (int i = h[x]; i != -1; i = ne[i]) //枚举第二部分的相邻点
    {
        int j = e[i]; //j表示当前集合中点的编号
        if (!st[j])
        {
            st[j] = true; //这一步一定要先写，这样才是在j已经确定的情况下
            //看match[j]能不能找到下家
            if (match[j] == 0 || find(match[j]))
            //如果未匹配或者能在j匹配此时的x的前提下(也就是st[j] = true)，为match[j]找到下家
            {
                match[j] = x;
                return true;
            }
        }
    }

    return false;
}

int main()
{
    cin >> n1 >> n2 >> m;

    memset(h, -1, sizeof h);

    while (m--)
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }

    int res = 0;                  //当前匹配数量
    for (int i = 1; i <= n1; i++) //枚举第一个集合
    {    //枚举第一个集合当前节点时，确保第二个集合中每个节点都被考虑到
        //可以这样理解，每个男生去找女朋友时，不管那个女生有没有男朋友
         //这个男生都会考虑她,如果这个男生喜欢她，她没有男朋友最好，哪怕有
         //也看能不能抢过来,给她喜欢的那个男生找好下家
        memset(st, false, sizeof st);
        if (find(i))
            res++;
    }

    cout << res << endl;

    return 0;
}