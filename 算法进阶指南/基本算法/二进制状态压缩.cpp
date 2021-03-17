/*
取出整数n在二进制下表示的第k位 (n>>k)&1
取出整数n在二进制下的第0~k-1位(后k位)  n&((1<<k)-1)
把整数n在二进制表示下第k位取反 nxor(1<<k)
n在二进制表示下的第k位赋值1 n|(1<<k)
n在二进制的表示下第k位赋值0 n&(~(1<<k))
*/
#include<iostream>
using namespace std;
int main()
{
    int n=15;/* 1111  0010*/
    for(int i=0;i<4;i++)
    {   
        cout<<"第"<<i<<"位";
        cout<<((n>>i)&1)<<endl;
    }
}