/*
��һ��5*5��01�����У��������һ��λ�ã���λ���Լ����������ң��ĸ�����
��λ�õ����鶼��仯(0-1,1-0),��������Ҫ���ٴε�����԰�һ��������0-1
����ȫ���0����

1.ÿ��λ�������һ��
2.���̶��˵�һ�У��Ͳ��ܸı��һ�У�����������ĵ����������ֻ��һ��
��ԭ����:��i��ĳһ��Ϊ1ʱ����ǰi���ѱ��̶���ֻ�ܵ��i+1�и�λ�õ����ֲ���
��i�е���һλ���0
3.������Ⱥ�˳��Ӱ�����ս��
*/

#include <iostream>
using namespace std;
int dx[5] = {0, -1, 1, 0, 0}, dy[5] = {0, 0, 0, -1, 1};
const int N = 5, INF = 1000000;
int m[N][N] = {0};
void turn(int x, int y)
{
    for (int i = 0; i < 5; i++)
    {
        int a = x + dx[i], b = y + dy[i];
        if ((a >= 0 && a <= 5) || (b >= 0 && b <= 5))
        {
            m[a][b] ^= 1;
        }
    }
}
int main(void)
{
    int backup[5][5];
    int ans = INF;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            cin >> m[i][j];
    for (int i = 0; i < 1 << 5; i++)
    {
        int res = 0;
        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 5; j++)
                backup[i][j] = m[i][j];
        for (int j = 0; j < 5; j++)
        {
            if (i >> j & 1)
            {
                res++;
                turn(0, j);
            }
        }
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 5; j++)
                if (m[i][j] == 1)
                {
                    res++;
                    turn(i + 1, j);
                }
        bool is_successful = true;
        for (int j = 0; j < 5; j++)
            if (m[4][j] != 1)
            {
                is_successful = false;
                break;
            }

        if (is_successful)
        {
            cout << res;
        }
        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 5; j++)
                m[i][j] = backup[i][j];
    }
   // cout << ans;
}
