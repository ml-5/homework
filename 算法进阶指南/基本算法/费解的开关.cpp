/*
在一个5*5的01矩阵中，点击任意一个位置，该位置以及它上下左右，四个相邻
的位置的数组都会变化(0-1,1-0),问最少需要多少次点击可以把一个给定的0-1
矩阵全变成0矩阵

1.每个位置最多点击一次
2.若固定了第一行，就不能改变第一行，则满足题意的点击方案至多只有一种
其原因是:当i的某一行为1时候，若前i行已被固定，只能点击i+1行该位置的数字才能
第i行的这一位变成0
3.点击的先后顺序不影响最终结果
*/

#include <iostream>
using namespace std;
int dx[5] = {0, -1, 1, 0, 0}, dy[5] = {0, 0, 0, -1, 1};
const int N = 5, INF = 1000000;
int m[N][N] = {0};
void turn(int x, int y)
{
    for (int i = 0; i < 5; i++)
    {
        int a = x + dx[i], b = y + dy[i];
        if ((a >= 0 && a <= 5) || (b >= 0 && b <= 5))
        {
            m[a][b] ^= 1;
        }
    }
}
int main(void)
{
    int backup[5][5];
    int ans = INF;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            cin >> m[i][j];
    for (int i = 0; i < 1 << 5; i++)
    {
        int res = 0;
        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 5; j++)
                backup[i][j] = m[i][j];
        for (int j = 0; j < 5; j++)
        {
            if (i >> j & 1)
            {
                res++;
                turn(0, j);
            }
        }
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 5; j++)
                if (m[i][j] == 1)
                {
                    res++;
                    turn(i + 1, j);
                }
        bool is_successful = true;
        for (int j = 0; j < 5; j++)
            if (m[4][j] != 1)
            {
                is_successful = false;
                break;
            }

        if (is_successful)
        {
            cout << res;
        }
        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 5; j++)
                m[i][j] = backup[i][j];
    }
   // cout << ans;
}
