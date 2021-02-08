/*
����ģ�ⵥ������struct+ָ��ķ�ʽ,ÿ����Ҫ����new������̬�����½ڵ㣬�ǳ���
    -������:�õ��������ڽӱ�
    -˫����:�Ż�ĳЩ����
    ��������:e[N],ne[N]��ʾÿ���ڵ��ֵ����һ���ڵ��λ�ã��սڵ��±���-1��ʾ
*/
#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int head, e[N], ne[N],idx;
/*
head��ʾ��ǰ�����ʱͷ�����±�
e[]�洢ÿ���ڵ��ֵ���±��ʾ��ǰ�ڵ���±꣬�����д洢���ǵ�ǰ�ڵ��ֵ
ne[]�洢ÿ���ڵ��nextָ�룬e��ne�������±����
�±��ʾ��ǰ�ڵ���±꣬�����д洢���ǵ�ǰ�ڵ����ָ����һ���ڵ���±�
idx���±꣬��ʾ��ǰ���Դ��Ķ���ʼ�����½ڵ�
Ҳ����˵����������idx����±����������ʾ�µĽڵ��ֵ��nextָ��
*/
// ��ʼ��
void init()
{
    head = -1; //�սڵ���-1��ʾ
    idx = 0;   //��ǰ���Դ��±�0��ʼ�����½ڵ�
}

// ������ͷ����һ��ֵΪa�Ľڵ�
void add_to_head(int a)
{ /*
    e[idx] = a; �����½ڵ�
    ne[idx] = head; ���½ڵ�ָ��ǰ�����ʱ��ͷ���
    head = idx ++ ; ���µ�ǰ����ͷ�����±��idx
    */
    e[idx] = a, ne[idx] = head, head = idx++;
}
/*
��ֵΪx�Ľڵ�嵽�±���k�ĵ����
ע���±�Ϊk�����Ӧ�ڵ���±����k�����������Ŀ�е������ǵ�k�����룬��k�������
�ڵ�Ļ�������ڵ��Ӧ���±���k-1
*/
void add(int k, int x)
{
    e[idx] = x, ne[idx] = ne[k], ne[k] = idx++;
}
// ���±���k�ĵ����ĵ�ɾ����һ��ע����Ŀ���������Ľڵ���±�
void remove(int k)
{
    ne[k] = ne[ne[k]];
}
int main()
{
    int m;
    cin >> m;

    init();
    // head=-1;
    // idx=0;

    while (m--)
    {
        char op;
        int x, k;

        cin >> op;
        if (op == 'H')
        {
            cin >> x;
            add_to_head(x);
            // e[idx]=x;
            // ne[idx]=head;
            // head=idx++;
        }
        else if (op == 'D')
        {
            cin >> k;
            if (!k)
                head = ne[head];
            else
            {
                remove(k - 1);
                // ne[k-1]=ne[ne[k-1]];
            }
        }
        else
        {
            cin >> k >> x;
            add(k - 1, x);
            // e[idx]=x;
            // ne[idx]=ne[k-1];
            // ne[k-1]=idx++;
        }
    }

    for (int i = head; i != -1; i = ne[i])
        cout << e[i] << ' ';
    cout << endl;
    return 0;
}