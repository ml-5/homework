/*
手写堆:一棵完全二叉树
1.插入一个数 
    heap[++size]=x; up(size);
2.求集合中的最小值 
    heap[1]
3.删除最小值 一维数组删除头结点很困难，但是删除尾节点很方便
    heap[1]=heap[size];size--;down(1);
(前三个STL中优先队列支持)
4.删除任意一个元素
    heap[k]=heap[size];size--;down(k);up(K);
    前两步操作之后可能变大也可能变小，所以直接down(k);up(K);这两步只会执行一步
5.修改任意一个元素
    heap[k]=x;down(k);up(k);


以小根堆为例，每一个点都小于等于左右儿子，根节点是整棵树的最小值
堆的存储：一维数组来存储
1号点是根节点，节点x的左儿子是2x，右儿子是2x+1
两个基本操作：时间复杂度与树的高度成正比，logn
up(x)：往上调整 堆中某个元素变小之后需要往上调整
down(x)：往下调整 堆中某个元素变大之后需要往下调整
下标从1开始，如果从0开始，0号节点的左儿子还是0，冲突

这道题是堆排序，就是先把整个待排序的数组建成堆，每次输出堆顶元素
首先要建堆，然后输出堆顶，然后再把堆顶删掉 这些操作只需要down操作
求最小值O(1) 插入和删除都是O(logn)
*/
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100010;
int n, m;
int h[N], cnt;//cnt表示当前有多少元素

void down(int u)
{
    int t = u;//用t表示三个点的最小值的节点编号
    //前者是判断有无左右儿子
    if (u * 2 <= cnt && h[u * 2] < h[t]) t = u * 2;
    if (u * 2 + 1 <= cnt && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
    if (u != t)
    {
        swap(h[u], h[t]);
        down(t);//
    }
}

void up(int u)
{
    while (u / 2 && h[u] < h[u / 2])
    {
        swap(h[u], h[u / 2]);
        u >>= 1;
    }
}


int main()
{
    cin>>n>>m;
    for (int i = 1; i <= n; i ++ ) cin>>h[i];//下标从1开始
    cnt = n;
    /*
    如何建堆：一个一个元素往堆里面插的时间复杂度是O(nlogn)
    O(n)的建堆方式 从n/2 down 到1就行
    n/2也就是从倒数第二层开始往下down，倒数第二层n/4个元素down 1次
    倒数第三层n/8个元素down 2次...依次递推
    n/4+n/8*2+n/16*3+...<n
    */
    for (int i = n / 2; i; i -- ) down(i);

    while (m -- )
    {
        cout<<h[1]<<' ';
        h[1] = h[cnt -- ];
        down(1);
    }

    puts("");

    return 0;
}