/*
��̬�滮����һ��������Ƕȿ��ǣ��ֱ���״̬��ʾ��״̬����
״̬�����ʾ:��ʾ��ά״̬,ÿһ�����ϵĺ�����ʲôf(i,j)
��ʾ��������ĳЩ������ĳ�ּ��ϵ�ĳ������
DP�Ż��ǶԴ���ĵȼ۱���
״̬��ʾһ��������Ƕȿ��ǣ��ֱ��Ǽ���������
1.ֻ����ǰi����Ʒ
2.ѡ��������Ʒ�������С�ڵ���j
����һ�������֣����ֵ����Сֵ������
����f(i,j)��ָֻ����ǰi����Ʒ��������Ʒ�����������j��ѡ���м�ֵ�����ֵ
״̬���㣺���ϵĻ���  ��ΰѵ�ǰ���ϲ��ز�©�Ļ��ֳ����ɸ���С���Ӽ�
(��©һ��Ҫ���㣬���ؿ����)
�������⣺
for ��Ʒ
    for ���
        for ����

f(i,j)=max( f(i-1,j) , f(i-1,j-vi)+wi )

��ά
f(i,j)��ָֻ����ǰi����Ʒ��������Ʒ�������������j��ѡ���м�ֵ���ֵ
f(i,j)��Ϊ������,�ֱ��ǰ�����i����Ʒ
������f(i-1,j-v[i])+w[i]
������:f(i-1,j)
f(i,j)=max(f(i-1,j),f(i-1,j-v[i])+w[i])

#include <iostream>
using namespace std;
const int N = 1010;
int n, m;
int v[N], w[N];
int f[N][N];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i];
    //�±�� 1��ʼ����Ϊ״̬������Ҫ�õ�i-1
    //��ʼ��ö�����е�״̬,Ҳ����f[0~n][0~m],����f[0][0~m]��˵,��ȻΪ0
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= m; j++)
        {
            //����f(i,j)=max(f[i-1][j]+f[i-1][j-v[i]]+w[i]);
            f[i][j] = f[i - 1][j];
            if (j >= v[i])
                f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);
        }
    cout << f[n][m] << endl;
    return 0;
}*/
#include <algorithm>
#include <iostream>
using namespace std;
const int N = 1010;
int n, m;
int v[N], w[N];
int f[N];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i];
    //�Ż���ά���һά���ܹ��Ż���ӦΪf[i]��һ��ļ���ֻ�õ�f[i-1]�����һ��
    //f[i]���õ�j��j-v[i]��С�ڵ���j,���Կ��Ը�Ϊһά����
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= v[i]; j--)
        {
            //����j-v[i]�ϸ�С��j,���Դ��ڲ�ѭ�������С�������,������ȥ����j-v[i],Ȼ�����j
            //���Լ���f[j]ʱ���õ���j-v[i]��ʵ��ʵ�ǵ�i��ģ�������i-1���j-v[i]
            //����Ż����ڴ�ѭ���ı�����Ϊ�Ӵ�С
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }
    cout << f[m] << endl;
    return 0;
}
//һά�Ż�֮�󣬴��±�0��ʼҲ�ǳ�����
#include<iostream>
using namespace std;
const int N=1010;
int n,m;
int v[N],w[N];
int f[N];
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>v[i]>>w[i];
    for(int i=0;i<n;i++)
    {
        for(int j=m;j>=v[i];j--)
        f[j]=max(f[j],f[j-v[i]]+w[i]);
    }
    cout<<f[m]<<endl;
    return 0;
}