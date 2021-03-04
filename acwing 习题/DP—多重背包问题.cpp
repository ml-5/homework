/*
����ȫ��������,���ر�������ɰ��յ�i����Ʒѡ0,1,2...k������
(ע��:��Ȼÿ����Ʒ���s[i]����ѡ,�ټ��ϱ�������������,�������ѡk��
����k������������k*v[i]<=ÿ��ת̬�ı�������j&&k<=s[i])
����ת̬ת�Ʒ���f(i,j)=max(f(i-1,j-k*v[i])+k*w[i])

//�������� ��ά
#include <iostream>
using namespace std;
const int N = 110;
int n, m;
int v[N], w[N], s[N];
int f[N][N];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i] >> s[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            //k�����������Ǵ�ʱ�����������������
            for (int k = 0; k * v[i] <= j && k <= s[i]; k++)
                f[i][j] = max(f[i][j], f[i - 1][j - k * v[i]] + k * w[i]);
        }
    }
    cout << f[n][m] << endl;
    return 0;
}*/
//�ռ��Ż�
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 110;
int n, m;
int f[N];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int v, w, s;
        cin >> v >> w >> s;
        for (int j = m; i >= 0; j--)
            for (int k = 0; k * v <= j && k <= s; k++)
            {
                f[j] = max(f[j], f[j - k * v] + k * w);
            }
    }
    cout << f[m] << endl;
    return 0;
}