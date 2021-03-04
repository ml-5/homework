/*
先尝试完全背包问题优化思路f(i,j)，从转移方程入手

完全：背包最多放k个v  最后始终是-k*wi  求所有前缀最大值
f(i,j)  =max(f(i-1,j),f(i-1,j-v[i])+w[i],...f(i-1,j-k*v[i])+k*w[i])
f(i,j-v)=max(         f(i-1,j-v[i])     ,...f(i-1,j-k*v[i])+(k-1)*w[i])
f(i,j-2v)=max(        f(i-1,j-2v[i])    ,... f(i-1,j-k*v[i])+(k-2)*w[i])

多重：第i类物品有s个  最后始终是+s*wi  求滑动窗口最大值
f(i,j)  =max(f(i-1,j),f(i-1,j-v[i])+w[i],...f(i-1,j-s*v[i])+s*w[i]    )
f(i,j-v)=max(         f(i-1,j-v[i])     ,...f(i-1,j-s*v[i])+(s-1)*w[i],f(i-1,j-(s+1)*v[i])+s*w[i])

尝试失败

二进制优化数量
单调队列优化体积

二进制优化

假设第i种物品有s[i]个，将若干个第i种物品打包放一块儿考虑
比如1023个物品分为10组，每组各有1,2,4,8...512个物品，每一组要么一起选，要么都不选
类似01背包问题，经分析可知，我们可以用这十组拼凑出1023的任意一个数，
这样原来需要枚举1024次，现在只需要枚举10次
第i种物品有s[i]个，先拆分成logs[i]组，对于每一组用01背包问题去解决
时间复杂度：NVS->NlogS V=NVlogS
*/
//二进制做法 二维
#include<iostream>
#include<algorithm>
using namespace std;
//原来N表示多少种物品，现在N表示总共有多少组物品，所以N=n范围*logS范围
const int N=110010,M=2010;
int n,m;
int v[N],w[N];//存放每一组物品的总共的体积与价值
int f[N];//直接优化到01背包问题的一维

int main(){
    cin>>n>>m;//表示多少种物品与背包的容量
    
    int cnt=0;//表示有多少组物品
    for(int i=1;i<=n;i++){
        int a,b,s;
        cin>>a>>b>>s;//输入当前这一种物品的体积，价值与个数
        int k=1;//从1开始分组，每一组有k个物品
        while(k<=s){
            cnt++;
            v[cnt]=a*k;
            w[cnt]=b*k;
            s-=k;
            k*=2;
        }
        if(s>0) {
            cnt++;
            v[cnt]=a*s;
            w[cnt]=b*s;
        }
    }
    
    n=cnt;//此时n表示当前有多少组
    
    for(int i=1;i<=n;i++){//这儿不能改成从0开始，因为w[i]从下标1开始
        for(int j=m;j>=v[i];j--){
                f[j]=max(f[j],f[j-v[i]]+w[i]);
        }
    }

    cout<<f[m]<<endl;
    return 0;
}
