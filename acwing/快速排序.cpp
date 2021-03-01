/*
快速排序基于分治法
1.在数组中找一个元素作为分界点x
2.根据分界点x重新划分区间，使得所有小于x的在左边，大于x的在右边(使得x在它该在的位置)
    利用双指针
3.递归处理左右两边(这样让每一个元素都在该在的位置)
*/
#include<iostream>
using namespace std;
const int N=100010;
int n;
int q[N];
void quick_sort(int q[],int l,int r)
{
    if(l>=r) return;
    int i=l-1,j=r+1,x=q[(l+r)/2];
    while(i<j)
    {
        do i++;while(q[i]<x);
        do j--;while(q[j]>x);
        if(i<j)swap(q[i],q[j]);
    }
    quick_sort(q,l,j);
    quick_sort(q,j+1,r);
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++) cin>>q[i];
    quick_sort(q,0,n-1);
    for(int i=0;i<n;i++) cout<<q[i]<<' ';
    cout<<endl;
}