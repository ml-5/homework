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
        int d = exgcd(a, m, x, y);//��չŷ������㷨������Լ��d
        if (b % d) puts("impossible");//b�ܹ��������Լ��d�н�
        else cout<<(LL)b / d * x % m<<endl;//x�������ɱ�ģ��m��Χ�ڼ���
    }

    return 0;
}