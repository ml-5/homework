/*
ȡ������n�ڶ������±�ʾ�ĵ�kλ (n>>k)&1
ȡ������n�ڶ������µĵ�0~k-1λ(��kλ)  n&((1<<k)-1)
������n�ڶ����Ʊ�ʾ�µ�kλȡ�� nxor(1<<k)
n�ڶ����Ʊ�ʾ�µĵ�kλ��ֵ1 n|(1<<k)
n�ڶ����Ƶı�ʾ�µ�kλ��ֵ0 n&(~(1<<k))
*/
#include<iostream>
using namespace std;
int main()
{
    int n=15;/* 1111  0010*/
    for(int i=0;i<4;i++)
    {   
        cout<<"��"<<i<<"λ";
        cout<<((n>>i)&1)<<endl;
    }
}