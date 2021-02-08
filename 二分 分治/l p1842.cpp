//��������ţ https://www.luogu.com.cn/problem/P1824#submit
#include <bits/stdc++.h>
using namespace std;
int n, c, l, r, a[100000 + 10];
bool juge(int m)
{
    int s = 0, last = 1;         //��¼��һ��λ��
    for (int i = 2; i <= n; i++) //����ö��ÿ��ţ��
    {
        if (a[i] - a[last] < m)
            s++; //���˾��벻����𰸵Ļ�������Ҫ��ţ����һ
        else
            last = i; //����͸�����һ��ţ����λ��
        if (s > n - c)
            return false; //����Ҫ��ţ������������ţ����������
    }
    return true;
}
bool juge2(int m)
{
    int ans = 1, last = 1;
    for (int i = 2; i <= n; i++)
    {
        if (a[i] - a[last] >= m)
        {
            ans++;
            last = i;
        }
    }
    if (ans >= c)
        return true;
    return false;
}
int main(void)
{
    scanf("%d%d", &n, &c);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    l = 1;
    r = a[n] - a[1];
    sort(a + 1, a + 1 + n);
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (juge2(mid))
            l = mid + 1;
        else
            r = mid - 1;
    }
    printf("%d\n", r);
    return 0;
}