/*
核心思想：将字符串看成P进制数，P的经验值是131或13331，取这两个值的冲突概率低
小技巧：取模的数用2^64，这样直接用unsigned long long存储，溢出的结果就是取模的结果

typedef unsigned long long ULL;
ULL h[N], p[N]; // h[k]存储字符串前k个字母的哈希值, p[k]存储 P^k mod 2^64

// 初始化
p[0] = 1;
for (int i = 1; i <= n; i ++ )
{
    h[i] = h[i - 1] * P + str[i];
    p[i] = p[i - 1] * P;
}

// 计算子串 str[l ~ r] 的哈希值
ULL get(int l, int r)
{
    return h[r] - h[l - 1] * p[r - l + 1];
}字符串哈希是一个比较重要的哈希方式，很多字符串问题都可以用哈希来做，不一定非要kmp
字符串前缀哈希法：先预处理出来字符串所有前缀的哈希值
h[0]表示前0个字母的哈希值，h[i]表示前i个字母的哈希值
如何定义某一个前缀的哈希值：把字符串看作一个p进制的数
比如“ABCD”看成p进制的1234 所有可以转化成一个数字：1*p^3+..4*p^0得到的数可能很大，所以取模Q
这样就可以把任意一个字符串映射到0(去掉)1到Q-1中的数
注意：一般情况下不能把某一个字母映射成数字0，这样的话比如a映射为0，aaa同样映射为0,
这样会把不同字符串映射成同一个数字
哈希数字可能存在冲突，这里是假定不存在冲突，经验值是p取131或13331，Q取2^64一般不会冲突，这里有一个
小技巧，h数组中所有前缀的哈希值都用unsigned long long来存，这样溢出就相当于取模
配合前缀哈希后，可以利用前缀哈希算出任意一个子串的哈希值
已知从1到l-1，1到r的哈希值h[l-1]，h[r]

这道题首先先求出来原字符串所有前缀哈希值，算出两个区间字符串的哈希值，
这两个哈希值都是从0到2^64-1的一个数，哈希值相同就认为两个字符串相同
*/
#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned long long ULL;//用unsigned long long存储所有h，溢出就相当于取模

const int N = 100010, P = 131;

int n, m;
char str[N];
ULL h[N], p[N];
//前者存储给定字符串所有前缀的哈希值，h[0]前0个字母的哈希值，h[2]前2个字母的哈希值，后者存储次方，这里预处理出来

ULL get(int l, int r)
{//从l到r的哈希值
    return h[r] - h[l - 1] * p[r - l + 1];//把h[l-1]左移若干位与h[r]对齐
}

int main()
{
    cin>>n>>m>>str + 1;//字符串下标从1开始

    p[0] = 1;//p的0次方==1
    for (int i = 1; i <= n; i ++ )
    {//预处理所有前缀的哈希值和次方
        h[i] = h[i - 1] * P + str[i];
        p[i] = p[i - 1] * P;
    }

    while (m -- )
    {
        int l1, r1, l2, r2;
        cin>>l1>>r1>>l2>>r2;

        if (get(l1, r1) == get(l2, r2)) puts("Yes");
        else puts("No");
    }

    return 0;
}