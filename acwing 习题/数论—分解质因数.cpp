/*
//暴力 O(n)
void divide(int x)
{
    for (int i = 2; i <= x; i ++ )

从小到大枚举x的所有数，这里没有枚举质元素，会有问题吗？不会，因为枚举到i时，
x已经把i前面的(2到i-1)质因子全部都除干净了，此时x % i == 0的话，x是i的倍数，
且不包含任何2到i-1中的质因子，i中也不包含任何2到i-1中的质因子，所以i是质数

if (x % i == 0)
{
    int s = 0;
    while (x % i == 0)
        x /= i, s++;
    cout << i << ' ' << s << endl;
}
if (x > 1)
    cout << x << ' ' << 1 << endl;
cout << endl;
}

判定质数算法时间复杂度一定是根号n，但这道题时间复杂度不一定是根号n，
最好情况下是除一个数就除干净了，也就是除logn次
所以时间复杂度是logn到根号n之间
*/
#include <iostream>

    using namespace std;

void divide(int x)
{
    //任意大于1的自然数，最多只有一个大于sqrt(n)的质因子，反证法可证
    //所以先在2到sqrt(n)的范围去找质因子
    for (int i = 2; i <= x / i; i++)
    {
        /*
从2开始依次遍历，每次遍历到此时的i时，此时的x是已经把从2到i-1之间可能存在的质因子
全部除干净的x，如果这个时候的i仍然是此时的x的因数的话，那此时的i必然也是质数
*/
        if (x % i == 0)
        {
            int s = 0;
            //每次遍历到这个质因子时，x将这个质因子除干净
            while (x % i == 0)
                x /= i, s++;
            cout << i << ' ' << s << endl;
        }
    }
    /*
如果此时已经把sqrt(n)之前的质因子全部除干净的n仍然大于1的话，那此时的n就是
那个大于sqrt(n)的质因子
*/
    if (x > 1)
        cout << x << ' ' << 1 << endl;
    cout << endl;
}

int main()
{
    int n;
    cin >> n;

    while (n--)
    {
        int x;
        cin >> x;
        divide(x);
    }

    return 0;
}