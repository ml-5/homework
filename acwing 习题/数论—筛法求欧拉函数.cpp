/*
ŷ������
��a��n���ʣ���a^(n��ŷ������)ģn����1
���ۣ���n������ʱ a^(n-1)ģn����1 ������
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
��ŷ�����������У�ֻ�����������ĳ�������ӣ��ͳ�(1-1/pj)������������ӵĴ���û�й�ϵ
����6��ŷ������==6*(1-1/2)(1-1/3)  
����һ����n==2^100 * 3^100������ŷ������==n*(1-1/2)(1-1/3)���ʹ����޹�

primes[j] * i��ŷ��������i��ŷ�������Ĺ�ϵ��

��i % primes[j] == 0ʱ��primes[j]��i����С�����ӣ�Ҳ��primes[j] * i����С�����ӣ�
����primes[j] * i��i������������ͬ�ģ�����euler[primes[j] * i] = euler[i] * primes[j]

��i % primes[j] != 0ʱ��primes[j]С��i����С�����ӣ���primes[j] * i����С�����ӣ�
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