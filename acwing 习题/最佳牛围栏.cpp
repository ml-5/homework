#include <cstdio>
#include <iostream>

const int N = 100005;
int cows[N];
double sum[N];

int n, m;

bool check(double avg)
{
    for (int i = 1; i <= n; i++)
    {
        sum[i] = sum[i - 1] + cows[i] - avg;
    }

    double minv = 0;
    for (int i = 0, j = m; j <= n; j++, i++)
    {
        minv = std::min(minv, sum[i]);
        if (sum[j] - minv >= 0)
            return true;
    }
    return false;
}

int main()
{
    scanf("%d %d", &n, &m);
    double l = 0, r = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &cows[i]);
        r = std::max(r, (double)cows[i]);
    }

    while (r - l > 1e-5)
    {
        double mid = (l + r) / 2;
        if (check(mid))
            l = mid;
        else
            r = mid;
    }
    printf("%d\n", (int)(r * 1000));
    return 0;
}
