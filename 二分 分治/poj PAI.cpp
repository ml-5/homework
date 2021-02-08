#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
const double pi = acos(-1.0);
int n, f;
double a[maxn] = {};
bool check(double x)
{
    int num = 0; //���ΰ�x��Ϊ�뾶���Է��������
    for (int i = 0; i < n; i++)
    {
        num += a[i] / x;
        if (num > f + 1)
            return true;
    }
    return false;
}
int main()
{
    //��������
    scanf("%d%d", &n, &f);
    double r = 0, l;
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &a[i]);
        a[i] = pi * a[i] * a[i];
        r = max(r, a[i]);
    }
    //���ֲ���
    double EPS = 1e-5;
    double mid;
    while (r - l > EPS)
    {
        mid = (l + r) / 2;
        if (check(mid))
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    printf("%.3lf\n", left);
}