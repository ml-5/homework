/*
两个特别大的整数相加
把大的整数转到容器里面去，每一位存一位数字，低位在前便于进位，这样就在数组的最后去操作
*/
#include<vector>
#include<iostream>
using namespace std;
vector<int> add(vector<int>&A,vector<int>&B)
{
    if(A.size()<B.size()) return add(B,A);
    vector<int>C;//定义答案
    int t=0;
    for(int i=0;i<A.size();i++)
    {
        t+=A[i];
        if(i<B.size())t+=B[i];
        C.push_back(t%10);
        t/=10;
    }
    if(t) C.push_back(t);
    return C;

}
int main()
{
    string a,b;
    vector<int> A,B;//存到vector
    cin>>a>>b;
    for(int i=a.size()-1;i>=0;i--) A.push_back(a[i]-'0');
    for(int i=b.size()-1;i>=0;i--) B.push_back(b[i]-'0');
    auto C=add(A,B);
    for(int i=C.size()-1;i>=0;i--) cout<<C[i];
    return 0;

}