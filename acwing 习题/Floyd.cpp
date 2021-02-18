/*
时间复杂度是O(n^3), n表示点数
*/
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 210, INF = 1e9;

int n, m, Q;
int d[N][N]; //邻接矩阵存储所有边

// 算法结束后，d[a][b]表示a到b的最短距离
void floyd()
{
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

int main()
{
    cin >> n >> m >> Q;
    //初始化
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i == j)
                d[i][j] = 0;
            else
                d[i][j] = INF;

    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        d[a][b] = min(d[a][b], c); //有多条边的话保留最短的边
    }

    floyd();

    while (Q--)
    {
        int a, b;
        cin >> a >> b;

        int t = d[a][b];
        if (t > INF / 2)
            puts("impossible");
        else
            cout << t << endl;
    }

    return 0;
}