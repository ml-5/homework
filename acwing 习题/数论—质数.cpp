/*
质数(素数)是指在大于1的自然数中，除了1和它本身以外不再有其他因数(约数)的自然数
1.严格大于1，本身大于等于2
2.除了1和自身之外没有其他因数，也就是只能整除这两个数
//暴力 O(n)
bool is_prime(int x)
{
    if (x < 2) return false;//严格大于1
    for (int i = 2; i < x; i ++ )//在2到n-1中存在某个数被x整除
        if (x % i == 0)
            return false;
    return true;
}
*/
#include <iostream>
using namespace std;
//优化 每个数的约数都是成对出现，如果i是n的约数，则n/i也是n的约数
bool is_prime(int x)
{
    if (x < 2) return false;
/*
可以枚举每一对约数中较小的那个数即可，较小的约数的范围是1到根号n(从2开始枚举)
也可以这样理解，从小到大枚举每个可能是约数的数，循环条件是这个可能是约数的数
小于与它配对的那个约数
i<=sqrt(x)不推荐，因为每次都要执行这个较慢的操作
i*i<=n也不推荐，当n大道接近int最大值时，i*i可能溢出变成负数
时间复杂度sqrt(n)
*/
    for (int i = 2; i <= x / i; i ++ )
        if (x % i == 0)
            return false;
    return true;
}

int main()
{
    int n;
    cin >> n;

    while (n -- )
    {
        int x;
        cin >> x;
        if (is_prime(x)) puts("Yes");//输出且换行
        else puts("No");
    }

    return 0;
}