/*
Lucas 定理 cab=ca%p b%p*ca/p*cb/p(mod p)
复杂度 log N *(p+log p)
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int qmi(int a, int k, int p)
{
    int res = 1;
    while (k)
    {
        if (k & 1)
            res = (ll)res * a % p;
        k >>= 1;
        a = (ll)a * a % p;
    }
    return res;
}
int C(int a, int b, int p)
{
    if (b > a)
        return 0;
    //优化写法 if(b>a-b) b=a-b;
    int up = 1, down = 1;
    for (int i = 1, j = a; i <= b; i++, j--)
    {
        up = (ll)up * j % p;
        down = (ll)down * i % p;
    }
    return (ll)up * qmi(down, p - 2, p) % p;
}
int lucas(ll a, ll b, int p)
{
    if (a < p && b < p)
        return C(a, b, p) % p;
    else
        return (ll)C(a % p, b % p, p) * lucas(a / p, b / p, p) % p;
}
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        ll a, b, p;
        cin >> a >> b >> p;
        cout << lucas(a, b, p) % p << endl;
    }
}