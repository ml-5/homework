#include <cstdio>
#include <cmath>
using namespace std;
const int M = 10005;
const double intf = 200005.0;
double L[M];
int n, k;
bool judeg(double x)
{
    int num;
    for (int i = 0; i < n; i++)
    {
        num += (int)(L[i] / x);
    }
    return num >= k;
}
void solve()
{
    double left = 0, right = intf;
    for (int i = 0; i < 100; i++) //代替while(r>l) 避免精度的问题
    {
        //1次循环可以把区间缩小一半，100可以达到10^-30的精度
        double mid = (left + right) / 2;
        if (judeg(mid))
            left = mid;
        else
            right = mid;
    }
    printf("%0.2f\n", floor(right * 100) / 100);
}
int main()
{
    int i;
    while (scanf("%d%d", &n, &k) != -1)
    {
        for (i = 0; i < n; i++)
        {
            scanf("%lf", &L[i]);
        }
        solve();
    }
}
