/*
��ʽɸ��-O(nloglogn) ʱ�临�Ӷ�Լ����O(n)
*/
#include <iostream>
using namespace std;
const int N = 1000010;
int primes[N], cnt;
bool st[N];
void get_primes(int n)
{
    for (int i = 2; i <= n; i++)
    {
        //ɾ�����������ı�������Ϊ�����ж�p�Ƿ�Ϊ����ʱ
        //������Ҫ�ж�2��p-1���������ı����Ƿ�Ϊp��ֻҪ�ж������е������ı����Ƿ�Ϊp����
        //��Ϊ�����в�����������Щ��Ҳ��ǰ��������ı���
        //���е�һ��������������ʱ�򣬾Ͳ���Ҫɾ���������б���
        if (!st[i])
        {
            primes[cnt++] = i;
            for (int j = i + i; j <= n; j += i)
                st[j] = true;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    get_primes(n);
    cout << cnt << endl;
    return 0;
}