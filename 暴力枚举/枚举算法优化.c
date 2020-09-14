/**
 查找问题
任务描述：
给定长度为 n 的单调不下降数列 {𝑎0, ⋯ , 𝑎𝑛−1} 和目标数𝑘，
求满足条件𝑎𝑖 ≥ 𝑘的最小值 𝑖。不存在的情况下输出n。 输 入：
n = 5
a = {2, 3, 3, 5, 6}
k =4
输 出：
3
**/
/**
   解法1:一层for循环加判断，按照i从小到大遍历  复杂度为O(n)
   解法2:二分枚举 复杂度为O(log(n))
**/
#include <stdio.h>
int main()
{
    int n = 5, l = 0, r = n-1, mid, a[] = {2, 3, 3, 3, 5, 6}, k;
    scanf("%d", &k);
    while (r - l)
    {
        mid = (l + r) / 2;
        if (a[mid] >= k)
            r = mid;
        else
            l = mid + 1;
    }
    printf("%d", l);
}
