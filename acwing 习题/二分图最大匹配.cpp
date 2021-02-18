//O(nm)����ʵ������ʱ��ԶС��nm������������
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 510, M = 100010;
int n1, n2, m;
int h[N], e[M], ne[M], idx;
// �ڽӱ�洢���б�
//�������㷨��ֻ���õ�����ö�ٵĵ�һ������ָ��ڶ������ϵı�
//��������ֻ�ô�һ������ı�
int match[N]; // �洢�ڶ��������е�ÿ���㵱ǰƥ��ĵ�һ�������еĵ����ĸ�
bool st[N];   // ���ڵ�һ�����ϵ����е���˵���ڶ��������е�ÿ�����Ƿ��Ѿ���������

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool find(int x)
{
    for (int i = h[x]; i != -1; i = ne[i]) //ö�ٵڶ����ֵ����ڵ�
    {
        int j = e[i]; //j��ʾ��ǰ�����е�ı��
        if (!st[j])
        {
            st[j] = true; //��һ��һ��Ҫ��д������������j�Ѿ�ȷ���������
            //��match[j]�ܲ����ҵ��¼�
            if (match[j] == 0 || find(match[j]))
            //���δƥ���������jƥ���ʱ��x��ǰ����(Ҳ����st[j] = true)��Ϊmatch[j]�ҵ��¼�
            {
                match[j] = x;
                return true;
            }
        }
    }

    return false;
}

int main()
{
    cin >> n1 >> n2 >> m;

    memset(h, -1, sizeof h);

    while (m--)
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }

    int res = 0;                  //��ǰƥ������
    for (int i = 1; i <= n1; i++) //ö�ٵ�һ������
    {    //ö�ٵ�һ�����ϵ�ǰ�ڵ�ʱ��ȷ���ڶ���������ÿ���ڵ㶼�����ǵ�
        //����������⣬ÿ������ȥ��Ů����ʱ�������Ǹ�Ů����û��������
         //����������ῼ����,����������ϲ��������û����������ã�������
         //Ҳ���ܲ���������,����ϲ�����Ǹ������Һ��¼�
        memset(st, false, sizeof st);
        if (find(i))
            res++;
    }

    cout << res << endl;

    return 0;
}