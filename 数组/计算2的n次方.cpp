/**
计算2的N次方
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
任意给定一个正整数N(N<=100)，计算2的n次方的值。
输入
输入一个正整数N。
输出
输出2的N次方的值。
样例输入
5
样例输出
32

思路:数字太大，不能用基本数据类型，利用数组来计算
高精度计算
**/
#include <stdio.h>
int main()
{
    int a[50] = {0}; //创建保存数据的数组
    a[49] = 1;       //用数组存储
    int n;
    int i;
    int x = 0; // x代表进位
    scanf("%d", &n);
    while (n--)
    { //做n次循环
        int i = 49;
        while (i > 0)
        {
            int flag = 2 * a[i] + x; //计算2的阶乘
            printf("%d %d",a[i],x);
            a[i] = flag % 10;        //留下个位
            x = flag / 10;           //取走十位
            i--;
        }
    }

    for (i = 0; i < 50; i++) //出去数组多余的0
        if (a[i] != 0)
            break;
    for (; i < 50; i++) //按序输出
        printf("%d", a[i]);
    return 0;
}