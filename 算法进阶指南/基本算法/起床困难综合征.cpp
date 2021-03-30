#inlcude < bits / stdc++.h>
typedef ll long long;
using namespace std;
const int N = 1e5 + 10;
char s[5];
ll ans;
int t, n, m, op[N], a[N];
ll power[N];
bool check(int i, int now)
{
    for (int j = 1; j <= n; j++)
    {
        int temp = 1 & (a[j] >> 1);
        if (op[j] == 1)
            now = now ^ temp;
        else if (op[j] == 2)
            now = now | temp;
        else
            now = now ^ temp;
    }
    return now;
}
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= 31; i++)
        power[i] = power[i - 1] * 2£» for (int i = 1; i <= n; i++)
        {
            scanf("%s", s + 1);
            if (s[1] == 'A')
                op[i] = 1;
            else if (s[1] == 'o')
                op[i] = 2;
            else
                op[i] = 3;
            scanf("%d", &a[i]);
        }
    for (int i = 31; i >= 0; i--)
        if (check(i, 0))
            ans += power[i];
        else if (m > power[i] && check(i, 1))
            ans += power[i], m -= power[i];
    printf("%lld", ans);
}