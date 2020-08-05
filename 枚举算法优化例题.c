/**
题目：
绳子切割问题
任务描述：
有N条绳子，它们的长度分别为𝐿𝑖(≤ 1000)。如果从它们中切割出K条长度相
同的绳子的话，这K条绳子每条最长能有多长？答案保留到小数点后2位。
输 入：
N = 4
K = 11
L = {8.02, 7.43, 4.57, 5.39}
输 出：
2.00 (每条绳子分别可以得到4条、3条、2条、2条，共计11条)
**/
/**
解法1:一层for循环遍历 求和结果>=k第一个满足条件的即为答案
解法2:二分枚举
**/
#include <stdio.h>
int k = 11;
float L[4] = {8.02, 7.43, 4.57, 5.39};
int check(float mid, float *L);
float CutRope(int n);
int main()
{
    printf("%0.2f", CutRope(1000));
}
float CutRope(int n)
{
    float l, r = n, mid;
    while (r - l > 0.001)
    {
        mid = (l + r) / 2;
        if (check(mid, L))
            l = mid;
        else
            r = mid - 1;
    }
    return l;
}
int check(float mid, float *L)
{
    int sum = 0;
    for (int i = 0; i < 4; i++)
    {
        sum += (int)L[i] / mid;
    }
    return sum >= k ? 1 : 0;
}
