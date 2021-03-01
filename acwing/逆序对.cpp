#include<iostream>
using namespace std;
const int N=100010;
typedef long long ll;
int n;
int q[N],tmp[N];
ll merge_sort(int l,int r)
{
    if(l>=r) return 0;
    int mid=(l+r)>>1;
    ll res=merge_sort(l,mid)+merge_sort(mid+1,r);
    int i=l,j=mid+1,k=0;
    while(i<=mid&&j<=r)
    {
        if(q[i]<=q[j]) tmp[k++]=q[i++];
        else
        {
            res+=mid-i+1
            tmp[k++]=q[j++];
        }
    }
    while(i<=mid) tmp[k++]=q[i++];
    while(j<=r) tmp[k++]=q[j++];
    for(int i=l,j=0;i<=r;i++,j++) q[i]=tmp[j];
    return res;
}