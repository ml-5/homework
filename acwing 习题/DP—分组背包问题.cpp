//��01�����������ƣ����鱳������ɰ��յ�i����Ʒ��ѡ������ѡ��1,2��si��ȥ����
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110;

int n, m;
int v[N][N], w[N][N], s[N];
int f[N];//ֱ��һά�Ż��汾

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i ++ )//i=0,i<nҲ��
    {
        cin >> s[i];
        for (int j = 0; j < s[i]; j ++ )
            cin >> v[i][j] >> w[i][j];
    }
//���ת��ʱ���õ�����һ��(����)��״̬���ʹӴ�С(��С����)ö�����
    for (int i = 1; i <= n; i ++ )//i=0,i<nҲ��
        for (int j = m; j >= 0; j -- )//�Ӵ�С
            for (int k = 0; k < s[i]; k ++ )
                if (v[i][k] <= j)
                    f[j] = max(f[j], f[j - v[i][k]] + w[i][k]);

    cout << f[m] << endl;

    return 0;
}
