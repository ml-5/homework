//枚举算法
/**
题目:
数组配对
任务描述：
给你一个长度为n的数组A和一个正整数k，问从数组中任选两个数使其和是k的倍数，有多少
种选法。对于数组a1=1 , a2=2 , a3=2而言：
(a1,a2)和(a2,a1)被认为是同一种选法；
(a1,a2)和(a1,a3)被认为是不同的选法。 输 入：
第一行有两个正整数n，k。n<=1000000，k<=1000 第二行有n个正整数，每个数的大小不超
过1e9 输 出：
选出一对数使其和是k的倍数的选法个数
样例：
5 6 
1 2 3 4 5
**/
/**解法1:采用二重循环加if判断，
逐一列举
for(i=0; i<n; i++)
for(j=i+1; j<n; j++)
逐一验证
(ai + aj)%k = 0
复杂度为O(n^2)
缺点数据过大时所用的时间过长
解法2:改变枚举对象
𝑂𝑏𝑗(𝑎𝑖, 𝑎𝑗), 1 <= 𝑖 < 𝑗 <= 𝑛
(𝑎𝑖 + 𝑎𝑗)%𝑘 = 0 -> (𝑎𝑖%𝑘 + 𝑎𝑗%𝑘)%𝑘 = 0
逐一验证
𝑗 = (𝑘 − 𝑖)%𝑘
coun𝑡 = 𝑏𝑖 ∗ 𝑏𝑗
当j<i count = 0 
当j=i count=bi*(bj-1)/2;
**/
#include <iostream>
#include <cstring>
#define LL long long
int n, k;
int a[1000001]; //全局变量
void init()
{
    int t;
    memset(a, 0, sizeof(a));
    std::cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        std::cin >> t;
        a[t % k]++; //复用数组
    }
}
void work()
{
    LL ans = 0;
    for (int i = 0; i < k; i++)
    {
        int j = (k - i) % k;
        if (j < i)
            break;
        else if (j == i)
            ans += 1LL * a[i] * (a[i] - 1) / 2;
        else
            ans += 1LL * a[i] * a[j];
    }
    std::cout << ans <<std::endl;
}
int main()
{
    init();
    work();
    return 0;
}
