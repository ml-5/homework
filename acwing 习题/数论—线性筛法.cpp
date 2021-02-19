/*
线性筛法  O(n) 数据级别为1e7时，比上个方法快一倍
void get_primes(int n)
{
    for (int i = 2; i <= n; i ++ )
    {
        if (!st[i]) primes[cnt ++ ] = i;
        for (int j = 0; primes[j] <= n / i; j ++ )
        {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
}
*/#include <iostream>

using namespace std;

const int N= 1000010;

int primes[N], cnt;// primes[]存储所有素数
bool st[N];// st[x]存储x是否被筛掉

void get_primes(int n)
{
    for (int i = 2; i <= n; i ++ )
    {
//n只会被它的最小质因子删掉
        if (!st[i]) primes[cnt ++ ] = i;
        for (int j = 0; primes[j] <= n / i; j ++ )
        {
//对于任意一个合数x，假设pj为x最小质因子，当外层循环的i枚举到x/pj时，x一定会被筛掉
//也就是说当i枚举到x时，在此之前i一定会枚举到比x小的x/pj，而这个时候，x就会被筛掉
//每次筛的数都是用最小质因子去筛的
//primes[j] <= n / i是因为primes[j] * i要<=n，这样st[primes[j] * i]才有效
//思路是从小到大枚举所有的质数，去这个质数去筛掉它一定作为最小质因子的那个合数
//循环条件是这个合数primes[j] * i<=n也就是primes[j] <= n / i
            st[primes[j]*i] = true;
            //cout<<primes[j]*i<<endl;
            if (i % primes[j] == 0) break;
//这句话成立时，primes[j]一定是i的最小质因子，也一定是primes[j] * i的最小质因子
//这句话不成立时，primes[j]一定小于i的所有质因子，也一定是primes[j] * i的最小质因子
        }
    }
//总体思路是外层循环遍历每一个数，以每一个数为基准，遍历之前的质数来筛掉对应的合数
//一直遍历到当前的质数是此时外层循环遍历到的数的最小质因子为止
//内层循环的终止条件是要确保当前primes[j]是primes[j]*i的最小质因子，它最大只能
//等于i的最小质因子，如果更大一点它就不是primes[j]*i的最小质因子了
}

int main()
{
    int n;
    cin >> n;

    get_primes(n);

    cout << cnt << endl;

    return 0;
}