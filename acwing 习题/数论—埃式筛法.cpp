/*
埃式筛法-O(nloglogn) 时间复杂度约等于O(n)
*/
#include <iostream>
using namespace std;
const int N = 1000010;
int primes[N], cnt;
bool st[N];
void get_primes(int n)
{
    for (int i = 2; i <= n; i++)
    {
        //删掉所有质数的倍数，因为我们判断p是否为质数时
        //并不需要判断2到p-1的所有数的倍数是否为p，只要判断这其中的质数的倍数是否为p就行
        //因为这其中不是质数的那些书也是前面的质数的倍数
        //所有当一个数不是质数的时候，就不需要删掉它的所有倍数
        if (!st[i])
        {
            primes[cnt++] = i;
            for (int j = i + i; j <= n; j += i)
                st[j] = true;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    get_primes(n);
    cout << cnt << endl;
    return 0;
}