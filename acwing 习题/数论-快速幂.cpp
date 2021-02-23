/*
快速求出来 a^k mod p，时间复杂度 O(logk)
核心思路是反复平方，预处理出来a^(2^0) mod p，a^(2^1) mod p，...a^(2^logk) mod p
把a^k mod p 拆成前面预处理的logk个数的乘积，k转换成二进制
*/
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
LL qmi(int a, int b, int p)
{
    LL res = 1;
    while (k)
    {
        if (k & 1)
            res = res * a % p;
        k >>= 1;
        a = a * a % p;
    }
    return res;
}
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int a, b, p;
        cin >> a >> b >> p;
        cout << qmi(a, b, p) << endl;
    }

    return 0;
}