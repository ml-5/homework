/*
 a1,a2,a3...an
 �ж��Ƿ����ѡ����������ʹ���ǵĺ�ǡ��Ϊk
 */

#include<iostream>
using namespace std;
const int MAX_N=21;
int a[MAX_N];
int n,k;
bool dfs(int i,int sum)
{
  if(i==n) return sum==k;
  if(dfs(i+1,sum)) return true;
  if(dfs(i+1,sum+a[i])) return true;
  return false;
}
void solve()
{
    int (dfs(0,0)) cout<<"Yes";
    else cout<<"No";
}