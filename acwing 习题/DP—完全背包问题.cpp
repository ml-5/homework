/*
����01��������,���԰��յ�i����Ʒѡ0����һ�����࣬���Ƶ�,��ȫ����Ҳ���԰��յ�i��
��Ʒѡ0,1,2,...k������
(ע��:��Ȼÿ����Ʒ�����޸���ѡ���������������ޣ��������ѡk��������k����������
��k*v[i]<=ÿ��״̬���ǵı�������j)
����״̬ת�Ʒ���f(i,j)=max(f(i-1,j-k*v[i])+k*w[i]) k>=0&&k*v[i]<=j

//�������� �ᳬʱ
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
    //ö�����е�״̬
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            for (int k = 0; k * v[i] <= j; k++)
                f[i][j] = max(f[i][j], f[i - 1][j - k * v[i]] + k * w[i]);
        }
    }
    cout << f[n][m] << endl;
    return 0;
}

״̬ת�Ʒ���
f(i,j)  =max(f(i-1,j),f(i-1,j-v[i])+w[i],f(i-1,j-2*v[i])+2*w[i],...,f(i-1,j-k*v[i])+k*w[i])
f(i,j-v)=max(         f(i-1,j-v[i])     ,f(i-1,j-2*v[i])+  w[i],...,f(i-1,j-k*v[i])+(k-1*w[i])

f(i,j)=max( f(i-1,j) , f(i, j-vi)+wi )     ��ȫ���������Ż�����
f(i,j)=max( f(i-1,j) , f(i-1,j-vi)+wi )     01�������ⷽ��

//��ά�Ż�����
#include <iostream>
#include <algorithm>
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
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            f[i][j] = f[i - 1][j];
            if (j >= v[i])
                f[i][j] = max(f[i][j], f[i][j - v[i]] + w[i]);
        }
    }
    cout << f[n][m] << endl;
    return 0;
}*/
//һά�Ż�����
#include <iostream>
#include <algorithm>
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
    for (int i = 1; i <= n; i++)
    {
        for (int j = v[i]; j <= m; j++)
            f[j] = max(f[j], f[j - v[i]] + w[i]);
    }
    cout << f[m] << endl;
    return 0;
}
