/**题意：把 [公式] 个数分成 [公式] 块，求每一块和的最小值最大

题解：二分答案是求最小值最大的通用套路，我们二分这个最小值最大，然后去看能不能这样子分  [公式] 块即可
**/
#include <cstdio>
#include <algorithm>
#define N 100100
using namespace std;
int n, m, a[N];
inline bool check(int mid)
{
    int sum = 0, cnt = 0;
    for (int i = 0; i <= n; i++)
    {
        sum += a[i];
        if (sum > mid)
        {
            sum = a[i];
            ++cnt
        }
    }
    return cnt < m;
}
