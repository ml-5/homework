/*
1.�̻�һ�����Ž�Ľṹ����
2.�ݹ�ĵ������Ž��ֵ
3.��������Ž��ֵ��ͨ�������Ե����ϵķ���
4.�����Ѿ����������Ϣ����һ�����Ž�

�����и���������� rn=max(rn,r1+rn-1,r2+rn-2.....)
��һ������pn��Ӧ���иֱ�ӳ���nӢ��ĸ����ķ�����������n-1��������Ӧ����n-1�з����Ա�


*/


#include <iostream>
#include <algorithm>
using namespace std;
int pi[11] = {0, 1, 5, 8},pimax[11]={0,1,5,8,9,10,17,17,20,24,30};
int main()
{
    int i, k, j;
    for (i = 4; i <= 10; i++)
    {
        for (j = 1, k = i - 1; j <= k; j++, k--)
        {
            pimax[i] = max(pimax[i], pi[j] + pi[k]);
        }
        
    }
    for (int i = 1; i <= 10; i++)
        printf("%d  %d \n", i, pimax[i]);
}