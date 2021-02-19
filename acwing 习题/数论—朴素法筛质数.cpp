/*
����ɸ�� ʱ�临�Ӷȿ��Կ���nlogn
��i==2ʱ������n/2�Σ����ƣ��������
n/2+n/3+...n/n==n(1/2+1/3+...1/n)==n*���ͼ���==n*(ln n + c)<nlogn
*/
#include <iostream>
using namespace std;

const int N = 1000010;

int primes[N], cnt;
bool st[N];

void get_primes(int n)
{
    for (int i = 2; i <= n; i++)
    {   //��ǰ���󿴣���ÿһ�����ı���ɸ��������ʣ�µ���һ��������
        //���pû��ɸ����˵��2��p-1��û��˭�ı�����p��Ҳ����û��p��Լ�������pΪ����
        if (!st[i])
        {
            primes[cnt++] = i;
        }
        for (int j = i + i; j <= n; j += i)
            st[j] = true;
    }
}

int main()
{
    int n;
    cin >> n;

    get_primes(n);

    cout << cnt << endl; //���cnt���ɣ�����Ҫ�ټ�һ����Ϊcnt�Ѿ�++

    return 0;
}