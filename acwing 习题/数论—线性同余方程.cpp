#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;


int exgcd(int a, int b, int &x, int &y)
{
    if (!b)
    {
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}


int main()
{
    int n;
    cin>>n;
    while (n -- )
    {
        int a, b, m;
        cin>>a>>b>>m;

        int x, y;
        int d = exgcd(a, m, x, y);//扩展欧几里得算法求出最大公约数d
        if (b % d) puts("impossible");//b能够整除最大公约数d有解
        else cout<<(LL)b / d * x % m<<endl;//x扩大若干倍模到m范围内即可
    }

    return 0;
}