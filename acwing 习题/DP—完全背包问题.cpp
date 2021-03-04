/*
对于01背包问题,可以按照第i种物品选0个或一个分类，类似的,完全背包也可以按照第i中
物品选0,1,2,...k个分类
(注意:虽然每种物品有无限个可选，但背包容量有限，所以最多选k个，其中k的限制条件
是k*v[i]<=每个状态考虑的背包容量j)
所以状态转移方程f(i,j)=max(f(i-1,j-k*v[i])+k*w[i]) k>=0&&k*v[i]<=j

//朴素做法 会超时
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
    //枚举所有的状态
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            for (int k = 0; k * v[i] <= j; k++)
                f[i][j] = max(f[i][j], f[i - 1][j - k * v[i]] + k * w[i]);
        }
    }
    cout << f[n][m] << endl;
    return 0;
}

状态转移方程
f(i,j)  =max(f(i-1,j),f(i-1,j-v[i])+w[i],f(i-1,j-2*v[i])+2*w[i],...,f(i-1,j-k*v[i])+k*w[i])
f(i,j-v)=max(         f(i-1,j-v[i])     ,f(i-1,j-2*v[i])+  w[i],...,f(i-1,j-k*v[i])+(k-1*w[i])

f(i,j)=max( f(i-1,j) , f(i, j-vi)+wi )     完全背包问题优化方程
f(i,j)=max( f(i-1,j) , f(i-1,j-vi)+wi )     01背包问题方程

//二维优化做法
#include <iostream>
#include <algorithm>
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
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            f[i][j] = f[i - 1][j];
            if (j >= v[i])
                f[i][j] = max(f[i][j], f[i][j - v[i]] + w[i]);
        }
    }
    cout << f[n][m] << endl;
    return 0;
}*/
//一维优化做法
#include <iostream>
#include <algorithm>
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
    for (int i = 1; i <= n; i++)
    {
        for (int j = v[i]; j <= m; j++)
            f[j] = max(f[j], f[j - v[i]] + w[i]);
    }
    cout << f[m] << endl;
    return 0;
}
