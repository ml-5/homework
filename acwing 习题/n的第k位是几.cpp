#include<iostream>
using namespace std;
int main(void)
{
    int n=10;
    for(int k=3;k>=0;k--) cout<<(n>>k&1)<<endl;
    return 0;
}