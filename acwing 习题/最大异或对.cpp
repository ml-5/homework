/*
������XOR������������ͬΪ0����ͬΪ1
����
for(int i=0;i<n;i++){
    for(int j=0;j<i;j++){//��ΪA^B=B^A�����Եڶ���ѭ��ֻ����i֮ǰ��Ԫ�ر��ڼ����ظ�
        res=max(res,a[i]^a[j]);
    }
}
�Ż�
�Ż�
����trie�Ż��ڲ�ѭ��:�ڹ̶�a[i]��Ѱ��a[i]ǰ����a[i]�������Ԫ��
ÿһ���������Կ���31λ�Ķ����ƴ�����a[i]ǰ�����Щ����Ӧ�Ķ����ƴ���
�����λ��ʼ̽������ĳһλ�Ķ���������a[i]����ͬλ��ͬʱ��ֻ����̽����һЩ��ͬ������
�����Ҳ�ͬ��������trie���洢��Щ������ѯʱ�Ӹ��ڵ㿪ʼ��
ÿһ�ξ������뵱ǰ��һλ��ͬ����һЩλ����
֮ǰ�ڲ�ѭ��ʱ�临�Ӷ���0(n) �������Ӹ��ڵ��ߵ�Ҷ�ڵ㣬
�ڲ�ѭ��ʱ�临����ʮ�򼶱��n��Ϊ31
*/
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100010, M = 31 * N;

int n;
int a[N];
int son[M][2], idx;
//trie����ÿһ����֧����һ������ÿ����֧��31���ڵ㣬���������310����ڵ�
void insert(int x)
{
    int p = 0; //�Ӹ��ڵ㿪ʼ̽��
    for (int i = 30; i >= 0; i--)
    {                       //�����λ��ʼ̽��
        int u = x >> i & 1; //�õ�x�ĵ�iλ������
        if (!son[p][u])
            son[p][u] = ++idx;
        p = son[p][u];
    }
    //�������ַ���һ����¼ÿ���ڵ��β�ĵ����ж��ٸ�
    //����Ϊÿһ��������31λ��������ڸ��ǵ����
}
int query(int x)
{
    int p = 0, res = 0;
    for (int i = 30; i >= 0; i--)
    {
        int u = x >> i & 1;
        if (son[p][!u])
            p = son[p][!u], res = res * 2 + !u; //�������뵱ǰ��һλ��ͬ�ķ�����
        else
            p = son[p][u], res = res * 2 + u;
    }
    return res;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        //���ѭ��������ö��ÿ����
        insert(a[i]);
        int t = query(a[i]); //�Ȳ����ٲ�ѯ���ڴ���߽�����
        res = max(res, a[i] ^ t);
    }
    cout << res << endl;
    return 0;
}
