/*
������Ч�洢�Ͳ����ַ������ϵ����ݽṹ
*/
#include <iostream>
using namespace std;
const int N = 100010;
/*
son[][]�洢����ÿ���ڵ���ӽڵ㣬��Ŀ�����ַ���������СдӢ����ĸ
����ÿһ���ڵ������26���ӽڵ�
*/
int son[N][26];
//��ʾ��ǰ��N��β�ĵ����ж��ٸ�
int cnt[N];
/*
idx�뵥������idx��һ���������idx��ʾ���һ��������ĸ���±꣬����ĸ����ʱ
��Ӧ���±���++idx�����������е�idxֱ�ӾͿ�������������µĽڵ�
�±���0�ĵ㣬���Ǹ��ڵ㣬Ҳ�ǿսڵ�
ע��������++idx������Ӳ������������ΪҪ��idx=0��ʾ�սڵ㣬��˵����ʼ��idxΪ0ʱ
���½ڵ�ĸ�ֵ������++֮���ٸ�ֵ��������Ҳ��ȫ�����ȳ�ʼ��idx=1��֮��ֵ��idx++
*/
int idx;
void insert(char str[])
{
    int p = 0; //�Ӹ��ڵ�����̽��
    for (int i = 0; str[i]; i++)
    {
        int u = str[i] - 'a'; //��ǰ������ĸ��Ӧ���ӽڵ���
        if (!son[p][u])
            son[p][u] = ++idx;
        p = son[p][u];
    }
    cnt[p]++;
}
int query(char str[])
{

    int p = 0;
    for (int i = 0; str[]; i++)
    {
        int u = str[i] - 'a';
        if (!son[p][u])
            return 0;
        p = son[p][u];
    }
    return cnt[p];
}
int main()
{
    int n;
    cin >> n;
    char str[N];
    while (n--)
    {
        string op;
        cin >> op >> str;
        if (op == "I")
            insert(str);
        else
            cout << "query(str)" << endl;
    }
    return 0;
}
