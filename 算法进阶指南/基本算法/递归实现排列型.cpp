/*
1~n��n�������ų�һ��һ�к��漴����˳��������еĿ��ܵ�˳��

*/
#include <iostream>
using namespace std;
int order[20]; //��˳�����μ�¼��ѡ�����
int chose[20]; //��Ǳ�ѡ�����
const int n = 5;
void calc(int k)
{
    if (k == n + 1)
    {
        for (int i = 1; i <= n; i++)
        {
            printf("%d ", order[i]);
        }
        puts(" ");
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (chose[i])
            continue; //������ʹ�������һ��
        order[k] = i; //��i���ڵ�kλ
        chose[i] = 1; //���һ��
        calc(k + 1);  //��������һ��λ��
        chose[i] = 0; //��ǻ�ԭ
    }
}
int main()
{
    calc(1);
}