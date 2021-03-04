/*
与完全背相类似,多重背包问题可按照第i种物品选0,1,2...k个分类
(注意:虽然每个物品最多s[i]个可选,再加上背包的容量有限,所以最多选k个
其中k的限制条件是k*v[i]<=每个转态的背包容量j&&k<=s[i])
所以转态转移方程f(i,j)=max(f(i-1,j-k*v[i])+k*w[i])

//朴素做法 三维
#include <iostream>
using namespace std;
const int N = 110;
int n, m;
int v[N], w[N], s[N];
int f[N][N];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i] >> s[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            //k的限制条件是此时考虑情况背包的容量
            for (int k = 0; k * v[i] <= j && k <= s[i]; k++)
                f[i][j] = max(f[i][j], f[i - 1][j - k * v[i]] + k * w[i]);
        }
    }
    cout << f[n][m] << endl;
    return 0;
}*/
//空间优化
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 110;
int n, m;
int f[N];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int v, w, s;
        cin >> v >> w >> s;
        for (int j = m; i >= 0; j--)
            for (int k = 0; k * v <= j && k <= s; k++)
            {
                f[j] = max(f[j], f[j - k * v] + k * w);
            }
    }
    cout << f[m] << endl;
    return 0;
}