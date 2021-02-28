/*10����1<a<b<2000  ����
1����Ԥ���� 1<b<a<1e5 Ԥ����
cab=a!/(a-b)!b�� fact[i]=i!%mod 1e9+7
infact[i]=1/(i!) mod 1e9+7
��һ��������ݷ�Χ 
1��n��10000   ����һ����ѯ��
1��b��a��2000  2000*2000==4e6��ʱ�临�Ӷ�Ԥ�����������C a b��ֵ���������
���������ݷ�Χ
1��n��10000 
1��b��a��100000 Ԥ��������׳�
����Ԥ��������н׳�ȡģ������fact[N]���Լ����н׳�ȡģ����Ԫinfact[N]
���ȡģ�����������������÷���С��������Ԫ
*/
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=100010,mod=1e9+7;
int fact[N],infact[N];//fact��ʾ�׳� infact��ʾ�׳˵���Ԫ
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