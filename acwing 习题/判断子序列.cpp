/*
����a��ÿ��Ԫ���ܷ�˳��ӳ�䵽b
��ǰ����ɨ������b��ÿ��ɨ��ʱ���鿴����b�е�ǰ��������a�е�ǰ���Ƿ�һ��
���һ������ʱa[i]��b[j]ƥ�䣬i++
��֮����������b��һ��һ������a[i]��ƥ���Ԫ�أ�ƥ��ɹ���i++
*/
#include <iostream>

using namespace std;

const int N = 100010;

int n, m;
int a[N], b[N];

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];

    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (a[i] == b[j])
            i++;
        j++;
    }

    if (i == n)
        puts("Yes");
    else
        puts("No");

    return 0;
}