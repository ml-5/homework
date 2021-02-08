/*
ע���������������ɾ�����޸ĵ�k�������Ԫ��(�����뵥����˫����������)
���Ի���Ҫ�����ҵ���k�������Ԫ��
��������������
*/
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100010;
int h[N], ph[N], hp[N], cnt;
/*
ph[k]����ǵ�k�������Ԫ���ڶ��е��±�
hp[k]����Ƕ����±���k�Ľڵ��ǵڼ�������ĵ�
֮ǰ������ʱ�򣬲��漰���ڼ������룬���Խ�����ֵ���У������ﲻ�У�
����ʱ����Ҫ֪�������ڵ�����ǵڼ�������Ľڵ㣬Ȼ���ٰѰѵڼ��������Ԫ���ڶ��е��±�ı�
*/

void heap_swap(int a, int b)
{
    swap(ph[hp[a]], ph[hp[b]]);
    swap(hp[a], hp[b]);
    swap(h[a], h[b]);
}

void down(int u)
{
    int t = u;
    if (u * 2 <= cnt && h[u * 2] < h[t])
        t = u * 2;
    if (u * 2 + 1 <= cnt && h[u * 2 + 1] < h[t])
        t = u * 2 + 1;
    if (u != t)
    {
        heap_swap(u, t);
        down(t);
    }
}

void up(int u)
{
    while (u / 2 && h[u] < h[u / 2])
    {
        heap_swap(u, u / 2);
        u >>= 1;
    }
}

int main()
{
    int n, m = 0; //m��ʾ�ڼ��������Ԫ��
    cin >> n;
    while (n--)
    {
        string op;
        int k, x;
        cin >> op;
        if (op == "I")
        {
            cin >> x;
            cnt++;
            m++;
            ph[m] = cnt, hp[cnt] = m;
            h[cnt] = x;
            up(cnt);
        }
        else if (op == "PM")
            cout << h[1] << endl;
        else if (op == "DM")
        {
            heap_swap(1, cnt);
            cnt--;
            down(1);
        }
        else if (op == "D")
        {
            cin >> k;  //��ʱ��k�ǵ�k������
            k = ph[k]; //���ڵ�k�ǵ�k�������Ԫ���ڶ��е��±�
            heap_swap(k, cnt);
            cnt--;
            up(k);
            down(k);
        }
        else
        {
            cin >> k >> x;
            k = ph[k];
            h[k] = x;
            up(k);
            down(k);
        }
    }

    return 0;
}