/*
求x, y，使得ax + by = gcd(a, b)
裴蜀定理
对于任意正整数a,b 那么一定存在非零整数x,y使得ax + by = gcd(a, b)
如果ax + by = d 则d一定是gcd(a, b)的倍数
*/
#include<iostream>
#include<algorithm>
using namespace std;
/*int gcd(int a,int b,int &x,int &y)
{
    if(!b)
    {
        return a;
    }
    return gcd(b,a%b);
}*/
int exgcd(int a,int b,int &x,int &y)
{
    if(!b)
    {
        x=1,y=0;
        return a;
    }
    int d=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}

int main()
{
    int n;
    cin>>n;

    while (n -- )
    {
        int a, b;
        cin>>a>>b;
        int x, y;
        exgcd(a, b, x, y);
        cout<<x<<' '<<y<<endl;
    }

    return 0;
}
