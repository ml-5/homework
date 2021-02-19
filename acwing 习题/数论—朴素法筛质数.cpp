/*
朴素筛法 时间复杂度可以看做nlogn
当i==2时，运算n/2次，类推，运算次数
n/2+n/3+...n/n==n(1/2+1/3+...1/n)==n*调和级数==n*(ln n + c)<nlogn
*/
#include <iostream>
using namespace std;

const int N = 1000010;

int primes[N], cnt;
bool st[N];

void get_primes(int n)
{
    for (int i = 2; i <= n; i++)
    {   //从前往后看，把每一个数的倍数筛掉，这样剩下的数一定是质数
        //如果p没被筛掉，说明2到p-1中没有谁的倍数是p，也就是没有p的约数，因此p为质数
        if (!st[i])
        {
            primes[cnt++] = i;
        }
        for (int j = i + i; j <= n; j += i)
            st[j] = true;
    }
}

int main()
{
    int n;
    cin >> n;

    get_primes(n);

    cout << cnt << endl; //输出cnt即可，不需要再加一，因为cnt已经++

    return 0;
}