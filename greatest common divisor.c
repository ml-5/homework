//欧几里得算法 (辗转相除法)
//思路：
// 1.输入两个正整数
// 2.用m/n,余数为r,如果r=0,则n是最大公约数。算法结束，否则执行第三步
//3.把n值赋给m，把r的值赋给n，继续执行第二步
#include <stdio.h>
int FindDivisor(int m, int n)
{
    if (m % n == 0)
        return n;
    else
        return FindDivisor(n, m % n);
}
int main()
{
    int m, n;
    printf("请输入 m n:\t");
    scanf("%d %d", &m, &n);
    printf("最大公约数为:%d", FindDivisor(m, n));
}