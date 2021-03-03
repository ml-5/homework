#include<iostream>
using namespace std;
const int MAX=1e6;
bool use[MAX];
int perm[MAX];
void dfs(int d,int n)
{
    if(d==n)
    {

        for(int i=0;i<n;i++)
        cout<<perm[i]<<endl;
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(!use[i])
        {
            perm[d]=i;
             use[i]=true;
             dfs(d+1,n);
             use[i]=false;
        }
    }
    return;
}
