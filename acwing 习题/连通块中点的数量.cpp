/*
���鼯��չ��
ά��size�Ĳ��鼯(Ҫ��̬֪��ÿ�����ϵ�ǰ�ж���Ԫ��)
int p[N], size[N];
p[]�洢ÿ��������ڽڵ�, size[]ֻ�����ڽڵ�������壬��ʾ���ڽڵ����ڼ����еĵ������
// ����x�����ڽڵ�
int find(int x)
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}
��ʼ�����ٶ��ڵ�����1~n
for (int i = 1; i <= n; i ++ )
{
    p[i] = i;
    size[i] = 1;
}
�ϲ�a��b���ڵ��������ϣ�
size[find(b)] += size[find(a)];
p[find(a)] = find(b);
*/
#include <iostream>
using namespace std;
const int N = 100010;
int p[N], cnt[N];

int find(int x)
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        p[i] = i;
        cnt[i] = 1;
    }

    while (m--)
    {
        string op;
        int a, b;
        cin >> op;
        if (op == "C")
        {
            cin >> a >> b;
            a = find(a), b = find(b);
            if (a != b)
            {
                p[a] = b;
                cnt[b] += cnt[a];
            }
        }
        else if (op == "Q1")
        {
            cin >> a >> b;
            if (find(a) == find(b))
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
        else
        {
            cin >> a;
            cout << cnt[find(a)] << endl;
        }
    }
    return 0;
}