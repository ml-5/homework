//与01背包问题类似，分组背包问题可按照第i组物品不选，或者选第1,2…si个去分类
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110;

int n, m;
int v[N][N], w[N][N], s[N];
int f[N];//直接一维优化版本

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i ++ )//i=0,i<n也行
    {
        cin >> s[i];
        for (int j = 0; j < s[i]; j ++ )
            cin >> v[i][j] >> w[i][j];
    }
//如果转移时候用的是上一层(本层)的状态，就从大到小(从小到大)枚举体积
    for (int i = 1; i <= n; i ++ )//i=0,i<n也行
        for (int j = m; j >= 0; j -- )//从大到小
            for (int k = 0; k < s[i]; k ++ )
                if (v[i][k] <= j)
                    f[j] = max(f[j], f[j - v[i][k]] + w[i][k]);

    cout << f[m] << endl;

    return 0;
}
