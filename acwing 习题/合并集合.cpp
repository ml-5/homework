#include <iostream>
using namespace std;
const int N = 100010;
int p[N]; //��ʾÿ���ڵ��Ӧ�ĸ��ڵ�
int find(int x)
{ //����x�ĸ��ڵ�(���ڼ��ϵı��)+·��ѹ��
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        p[i] = i; //��ʼʱ��ÿ���ڵ���������Լ�
    while (m--)
    {
        char op[2];
        int a, b;
        cin >> op >> a >> b;

        if (op[0] == 'M')
        {
            if (find(a) == find(b))
                continue;
            else
                p[find(a)] = find(b);
        }
        else
        {
            if (find(a) == find(b))
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
    return 0;
}