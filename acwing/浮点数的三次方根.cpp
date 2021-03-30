#include<iostream>
using namespace std;
double x;
int main()
{
    cin>>x;
    doubel l=-100,r=100;
    while(l-r>1e-8)
    {
        //保留6位小数1e-8 4位小数 1e-6
        double mid=(l+r)>>1;
        if(mid*mid*mid>=x) r=mid;
        else l=mid;
    }
    printf("%.6f",l);
    return 0;
}
6+10+8+5+9+4=42/6=7