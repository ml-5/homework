/*
从定义出发，结果很大，需要使用高精度计算
先将 C  a b 分解为质因数之后变成p1^a1*p2^a2...,这样只需要实现高精度乘法
当我们需要求出组合数的真实值，而非对某个数的余数时，分解质因数的方式比较好用
1.通过筛法求出范围内所有的质数
2.通过C(a,b)=a!/b!(a-b)!这个公式求出每个质因子的次数
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 5010;
int primes[N], cnt; //存储所有质数
int sum[N];
bool st[N];
void get_primes(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (!st[i])
            primes[cnt++] = i;
        for (int j = 0; primes[j] <= n / i; j++)
        {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0)
                break;
        }
    }
}
int get(int n, int p)
{
    int res = 0;
    while (n)
    {
        res += n / p;
        n /= p;
    }
    return res;
}
vector<int> mul(vector<int> a, int b)
{
    vector<int> c;
    int t = 0;
    for (int i = 0; i < a.size(); i++)
    {
        t += a[i] * b;
        c.push_back(t % 10);
        t /= 10;
    }
    while (t)
    {
        c.push_back(t % 10);
        t /= 10;
    }
    return c;
}
int main()
{
    int a, b;
    cin >> a >> b;
    get_primes(a);
    for (int i = 0; i < cnt; i++)
    {
        int p = primes[i];
        sum[i] = get(a, p) - get(a - b, p) - get(b, p);
    }
    vector<int> res;
    res.push_back(1);
    for (int i= 0; i < cnt; i++)
    {
        for (int j = 0; j < sum[i]; j++)
            res = mul(res, prime[i]);
    }
    for (int i = res.size() - 1; i >= 0; i--)
        cout << res[i];
    puts("");
    return 0;
}