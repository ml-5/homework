/*10万组1<a<b<2000  递推
1万组预处理 1<b<a<1e5 预处理
cab=a!/(a-b)!b！ fact[i]=i!%mod 1e9+7
infact[i]=1/(i!) mod 1e9+7
上一道题的数据范围 
1≤n≤10000   给定一万组询问
1≤b≤a≤2000  2000*2000==4e6的时间复杂度预处理出来所有C a b的值，递推求解
这道题的数据范围
1≤n≤10000 
1≤b≤a≤100000 预处理出来阶乘
首先预处理出所有阶乘取模的余数fact[N]，以及所有阶乘取模的逆元infact[N]
如果取模的数是质数，可以用费马小定理求逆元
*/
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=100010,mod=1e9+7;
int fact[N],infact[N];//fact表示阶乘 infact表示阶乘的逆元
int qmi(int a,int k,int p)
{
    int res=1;
    while(k)
    {
        if(k&1) res=(ll)res*a%p;
        a=(ll)a*a%p;
        k>>=1;
    }
    return res;
}
int main()
{
    fact[0]=infact[0]=1;
    for(int i=1;i<N;i++)
    {
      fact[i]=(ll)fact[i-1]*i%mod;
      infact[i]=(ll)infact[i-1]*qmi(i,mod-2,mod)%mod;
    }
    int n;cin>>n;
    while(n--)
    {
        int a,b;
        cin>>a>>b;
        cout<<(ll)fact[a]*infact[b]%mod*infact[a-b]%mod<<endl;
    }

}