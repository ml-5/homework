/*
��x, y��ʹ��ax + by = gcd(a, b)
������
��������������a,b ��ôһ�����ڷ�������x,yʹ��ax + by = gcd(a, b)
���ax + by = d ��dһ����gcd(a, b)�ı���
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
