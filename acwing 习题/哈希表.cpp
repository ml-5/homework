/*
哈希表：
    存储结构：
        开放寻址法
        拉链法
    字符串哈希方式
把一个比较庞大的空间，值域，映射到比较小的空间，比如把(0,1e9)这些数映射到(0,1e5)
这道题中操作个数是1e5，每一个数的范围最多是1e9，值域较大，从中选一些(最多1e5)数插入或查询
通过一个哈希函数h(x)(输入在-1e9到1e9，输出在0到1e5)
哈希函数怎么写：一般可以写成x mod 1e5
(直接取模就行，模的这个数一般取尽可能离2的整次幂尽可能远的一个质数，数学可证明，这样冲突概率最小)
冲突：因为值域比较大，映射范围比较小，可能把两个不同的数映射为同一个数，所以需要处理冲突
按照冲突处理方式，一般分为开放寻址法  拉链法
之前讲的离散化是一种特殊的哈希方式(需要保序)，这里是一般意义的哈希
*/
/*
拉链法：开一个一维数组来存储所有哈希值，比如开一个1e5的数组，如何处理冲突 
如果两个数冲突，就会用一条链全部存下来，平均情况下，每条链的长度可以看做一个常数，所以一般情况下，哈希表
时间复杂度可以看成O(1)，算法题中一般情况下只会从哈希表中插入，查找元素，一般不会删除元素
如果要实现删除的话，不会真的把点删掉，一般是开一个数组，打一个标记，开一个布尔变量，记录即可
1) 拉链法
    int h[N], e[N], ne[N], idx;

    // 向哈希表中插入一个数
    void insert(int x)
    {
        int k = (x % N + N) % N;
        e[idx] = x;
        ne[idx] = h[k];
        h[k] = idx ++ ;
    }

    // 在哈希表中查询某个数是否存在
    bool find(int x)
    {
        int k = (x % N + N) % N;
        for (int i = h[k]; i != -1; i = ne[i])
            if (e[i] == x)
                return true;

        return false;
    }
*/
#include <cstring>
#include <iostream>
using namespace std;

const int N = 100003;//它是大于1e5的第一个质数，注意如何求质数
int h[N], e[N], ne[N], idx;
//h数组类似于每条拉链的槽或者说头结点编号，拉链就是链表，就是存储图用到的邻接表
void insert(int x)
{   
//首先想一个哈希函数，把x映射到从0到N之间的数 x%N在C++中结果正负由x的正负决定，再+N %N之后必然为正数
    int k = (x % N + N) % N; //这个操作本身和高精度减法很像
    e[idx] = x;//接下来就是链表插入头节点操作
    ne[idx] = h[k];
    h[k] = idx ++ ;
}
bool find(int x)
{
    int k = (x % N + N) % N;
    for (int i = h[k]; i != -1; i = ne[i])
        if (e[i] == x)
            return true;

    return false;
}
int main()
{
    int n;
    cin>>n;

    memset(h, -1, sizeof h);//清空数组

    while (n -- )
    {
        string op;
        int x;
        cin>>op>>x;

        if (op == "I") insert(x);
        else
        {
            if (find(x)) puts("Yes");
            else puts("No");
        }
    }

    return 0;
}
/*
开放寻址法
只开了一个一维数组，没有开链表，但是数组长度经验上来说要开到题目数据范围的两到三倍
比如这道题中输入了1e5个数，数组长度开到2e5到3e5，这是一个经验值，这样冲突概率较低
(2) 开放寻址法
    int h[N];

    // 如果x在哈希表中，返回x的下标；如果x不在哈希表中，返回x应该插入的位置
    int find(int x)
    {
        int t = (x % N + N) % N;
        while (h[t] != null && h[t] != x)
        {
            t ++ ;
            if (t == N) t = 0;
        }
        return t;
    }
*/
#include <cstring>
#include <iostream>
using namespace std;
//大于2e5的一个最小的质数
const int N = 200003, null = 0x3f3f3f3f;
int h[N];

int find(int x)//如果x在哈希表中存在，返回x所在的位置，如果不存在，返回它应该存储的位置
{
    int t = (x % N + N) % N;
    while (h[t] != null && h[t] != x)//循环条件是这个位置存储元素并且这个元素不是x
    {//跳出循环的条件要么是这个位置没有存储元素，要么是存储了元素，并且这个元素就是x
        t ++ ;
        if (t == N) t = 0;//探索到最后一个位置，然后再循环看第一个位置
    }
    return t;
}

int main()
{
    memset(h, 0x3f, sizeof h);
    //h数组存储的是每一个插入的数，初始化为+-1e9以外的数表示这个位置没有存放元素
   //按字节来0x3f，所以int4个字节，每个int是0x3f3f3f3f
    int n;
    cin>>n;

    while (n -- )
    {
        string op;
        int x;
        cin>>op>>x;
        if (op == "I") h[find(x)] = x;
        else
        {
            if (h[find(x)] == null) puts("No");
            else puts("Yes");
        }
    }

    return 0;
}
