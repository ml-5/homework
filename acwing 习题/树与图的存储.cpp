/*
树是无环连通图，智考虑图的存储，图分为有向图与无向图，对于无向图，对于无向图来说
存储两条边，
所以只考虑有向图的存储
两大类存储方式
1.邻接矩阵：g[a][b] 存储边a->b的信息，空间复杂度较大，n^2，针对稠密图存储
2.邻接表（常用）

*/
#include<iostream>
using namespace std;
const int N=100010,M=2*N;
//对于每个点k ,开一个单链表，存储所有可以走到的点，h[k]存储这个单链表的头节点
//e[M],ne[M] 表示指向节点的值和下一个节点
//在数中，每个节点最多可能被两条边所指向,所以M=2*N
int h[N],e[M],ne[M],idx;
void add(int a,int b)
{
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
int main()
{
    // 初始化
    idx = 0;
    memset(h, -1, sizeof h);//单链表初始化，让所有头结点指向-1
}