/*
��������� a^k mod p��ʱ�临�Ӷ� O(logk)
����˼·�Ƿ���ƽ����Ԥ�������a^(2^0) mod p��a^(2^1) mod p��...a^(2^logk) mod p
��a^k mod p ���ǰ��Ԥ�����logk�����ĳ˻���kת���ɶ�����
*/
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
LL qmi(int a, int b, int p)
{
    LL res = 1;
    while (k)
    {
        if (k & 1)
            res = res * a % p;
        k >>= 1;
        a = a * a % p;
    }
    return res;
}
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int a, b, p;
        cin >> a >> b >> p;
        cout << qmi(a, b, p) << endl;
    }

    return 0;
}