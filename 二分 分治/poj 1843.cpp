//?????
#include <bits/stdc++.h>
using namespace std;
intA[500005];
int n, a, b;
inline bool juge(int m)
{
    int cnt = 0;
    for (int i = 1; i <=n; i++)
    {
        int v = A[i] - a * m;
        if (v > 0)
        {
             cnt+=v/b;
         if(v%b) cnt++;
        }
    }
    if (cnt > m)
        return 0;
        return 1;
}
int main()
{
    int l=1,r;
    scanf("%d%d%d", &n, &a, &b);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &A[i]);
        r = max(r, A[i]);
    }
  
    while (l < r)
    {
      long long mid = l+(r-l)/2;
        if (juge(mid))
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    printf("%lld\n",r);
    return 0;
}