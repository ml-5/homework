/*
cab=ca-1b+ca-1b-1
数据范围 1<n<10000 给定十万组询问
1<b<a<2000 2000*2000==4e6的时间复杂度预处理求出来所有 C a b
*/
#include<iostream>
#include<algorithm>
using namespace std;
const int N=2010,mod=1e9+7;
int c[N][N];
void init()
{
    for(int i=0;i<N;i++)
    for(int j=0;j<=i;j++)
    if(!j) c[i][j]==1;
    else c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
}
int main()
{
    cin>>n;
    while(n--)
    {
        int a,b;
        cin>>a>>b;
        cout<<c[a][b]<<endl;
    }
    return 0;
}