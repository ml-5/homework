/*
求 a*b对p取模 1<=a,b,p<=10^18
a*bmod p=a*b-[a*b/p]下取整*p
*/
#include <iostream>
using namespace std;
typedef long long ll;
ll qmi(ll a, ll b, ll p)
{
    ll ans = 0;
    for (; b; b >= 1)
    {
        if (b & 1)
            ans = (ans + a) % p;
        a = a * 2 % p;
    }
    return ans;
}
ll mul(ll a, ll b, ll p)
{
    a %= p, b %= p;
    ll c = a * b / p;
    ll ans = a * b - c * p;
    if (ans < 0)
        ans += p;
    else if (ans >= p)
        ans -= p;
    return ans;
}
