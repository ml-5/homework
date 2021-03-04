/*
动态规划问题一般从两个角度考虑，分别是状态表示与状态计算
状态计算表示:表示几维状态,每一个集合的含义是什么f(i,j)
表示的是满足某些条件的某种集合的某种性质
DP优化是对代码的等价变形
状态表示一般从两个角度考虑，分别是集合与属性
1.只考虑前i个物品
2.选出来的物品的总体积小于等于j
属性一般有三种：最大值，最小值，数量
所以f(i,j)是指只考虑前i个物品，所有物品总体积不超过j的选法中价值的最大值
状态计算：集合的划分  如何把当前集合不重不漏的划分成若干个更小的子集
(不漏一定要满足，不重看情况)
背包问题：
for 物品
    for 体积
        for 决策

f(i,j)=max( f(i-1,j) , f(i-1,j-vi)+wi )

二维
f(i,j)是指只考虑前i个物品，所有物品的总体积不超过j的选法中价值最大值
f(i,j)分为两大类,分别是包含第i个物品
包含：f(i-1,j-v[i])+w[i]
不包含:f(i-1,j)
f(i,j)=max(f(i-1,j),f(i-1,j-v[i])+w[i])

#include <iostream>
using namespace std;
const int N = 1010;
int n, m;
int v[N], w[N];
int f[N][N];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i];
    //下标从 1开始是因为状态计算需要用到i-1
    //初始化枚举所有的状态,也就是f[0~n][0~m],对于f[0][0~m]来说,必然为0
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= m; j++)
        {
            //对于f(i,j)=max(f[i-1][j]+f[i-1][j-v[i]]+w[i]);
            f[i][j] = f[i - 1][j];
            if (j >= v[i])
                f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);
        }
    cout << f[n][m] << endl;
    return 0;
}*/
#include <algorithm>
#include <iostream>
using namespace std;
const int N = 1010;
int n, m;
int v[N], w[N];
int f[N];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i];
    //优化二维变成一维，能够优化是应为f[i]这一层的计算只用到f[i-1]上面的一层
    //f[i]就用到j和j-v[i]都小于等于j,所以可以改为一维数组
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= v[i]; j--)
        {
            //由于j-v[i]严格小于j,所以从内层循环如果从小到大遍历,所以先去更新j-v[i],然后才是j
            //所以计算f[j]时所用到的j-v[i]其实其实是第i层的，而不是i-1层的j-v[i]
            //因此优化，内存循环的遍历改为从大到小
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }
    cout << f[m] << endl;
    return 0;
}
//一维优化之后，从下标0开始也非常方便
#include<iostream>
using namespace std;
const int N=1010;
int n,m;
int v[N],w[N];
int f[N];
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>v[i]>>w[i];
    for(int i=0;i<n;i++)
    {
        for(int j=m;j>=v[i];j--)
        f[j]=max(f[j],f[j-v[i]]+w[i]);
    }
    cout<<f[m]<<endl;
    return 0;
}