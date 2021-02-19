/*
����ɸ��  O(n) ���ݼ���Ϊ1e7ʱ�����ϸ�������һ��
void get_primes(int n)
{
    for (int i = 2; i <= n; i ++ )
    {
        if (!st[i]) primes[cnt ++ ] = i;
        for (int j = 0; primes[j] <= n / i; j ++ )
        {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
}
*/#include <iostream>

using namespace std;

const int N= 1000010;

int primes[N], cnt;// primes[]�洢��������
bool st[N];// st[x]�洢x�Ƿ�ɸ��

void get_primes(int n)
{
    for (int i = 2; i <= n; i ++ )
    {
//nֻ�ᱻ������С������ɾ��
        if (!st[i]) primes[cnt ++ ] = i;
        for (int j = 0; primes[j] <= n / i; j ++ )
        {
//��������һ������x������pjΪx��С�����ӣ������ѭ����iö�ٵ�x/pjʱ��xһ���ᱻɸ��
//Ҳ����˵��iö�ٵ�xʱ���ڴ�֮ǰiһ����ö�ٵ���xС��x/pj�������ʱ��x�ͻᱻɸ��
//ÿ��ɸ������������С������ȥɸ��
//primes[j] <= n / i����Ϊprimes[j] * iҪ<=n������st[primes[j] * i]����Ч
//˼·�Ǵ�С����ö�����е�������ȥ�������ȥɸ����һ����Ϊ��С�����ӵ��Ǹ�����
//ѭ���������������primes[j] * i<=nҲ����primes[j] <= n / i
            st[primes[j]*i] = true;
            //cout<<primes[j]*i<<endl;
            if (i % primes[j] == 0) break;
//��仰����ʱ��primes[j]һ����i����С�����ӣ�Ҳһ����primes[j] * i����С������
//��仰������ʱ��primes[j]һ��С��i�����������ӣ�Ҳһ����primes[j] * i����С������
        }
    }
//����˼·�����ѭ������ÿһ��������ÿһ����Ϊ��׼������֮ǰ��������ɸ����Ӧ�ĺ���
//һֱ��������ǰ�������Ǵ�ʱ���ѭ����������������С������Ϊֹ
//�ڲ�ѭ������ֹ������Ҫȷ����ǰprimes[j]��primes[j]*i����С�����ӣ������ֻ��
//����i����С�����ӣ��������һ�����Ͳ���primes[j]*i����С��������
}

int main()
{
    int n;
    cin >> n;

    get_primes(n);

    cout << cnt << endl;

    return 0;
}