/*
记忆化搜索 利用memo保存结果避免重复计算多次
*/

#include<iostream>
using namespace std;
int memo[MAX_N+1];
int fib(int n)
{
    if(n<=1) return n;
    if(meom[n]!=0) return meom[n];
    return meom[n]=fib(n-1)+fib(n-2);
}