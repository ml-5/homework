/*
欧拉定理
若a与n互质，则a^(n的欧拉函数)模n等于1
推论：当n是质数时 a^(n-1)模n等于1 费马定理
*/
#include <iostream>
using namespace std;
typedef long long LL;
const int N = 1000010;
int primes[N], cnt;
int phi[N];
bool st[N];
int get_eulers(int n)
{
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!st[i])
        {
            primes[cnt++] = i;
            phi[i] = i - 1;
        }
        for (int j = 0; primes[j] <= n / i; j++)
        { /*
求欧拉函数过程中，只有这个数包含某个质因子，就乘(1-1/pj)，与这个质因子的次数没有关系
比如6的欧拉函数==6*(1-1/2)(1-1/3)  
另外一个数n==2^100 * 3^100，它的欧拉函数==n*(1-1/2)(1-1/3)，和次数无关

primes[j] * i的欧拉函数与i的欧拉函数的关系：

当i % primes[j] == 0时，primes[j]是i的最小质因子，也是primes[j] * i的最小质因子，
所以primes[j] * i与i的质因子是相同的，所以euler[primes[j] * i] = euler[i] * primes[j]

当i % primes[j] != 0时，primes[j]小于i的最小质因子，是primes[j] * i的最小质因子，
euler[primes[j] * i] == euler[i] * primes[j] * (primes[j] - 1) / primes[j]
                     == euler[i] * (primes[j] - 1)
*/
            st[primes[j] * i] = true;
            if (i % primes[j] == 0)
            {
                phi[primes[j] * i] = phi[i] * primes[j];
                break;
            }
            phi[primes[j] * i] = phi[i] * (primes[j] - 1);
        }
    }

    LL res = 0;
    for (int i = 1; i <= n; i++)
    {
        /* cout << phi[i] << endl;*/
        res += phi[i];
    }
    return res;
}
int main()
{
    int n;
    cin >> n;
    cout << get_eulers(n) << endl;
}