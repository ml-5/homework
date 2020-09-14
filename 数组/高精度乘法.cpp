/**
题目描述
求两个不超过 200 位的非负整数的积。

输入
有两行，每行是一个不超过 200 位的非负整数，没有多余的前导 0。

输出
一行，即相乘后的结果。结果里不能有多余的前导 0，即如果结果是 342，那么就不能输出为 0342。

样例输入
12345678900
98765432100
样例输出
1219326311126352690000


思路:1、定义存储数组。

2、读入数据处理。

3、从个位开始模拟竖式乘法的过程，完成整个乘法。

4、删除前导 0 。所谓前导零，就是出现类似这样数据 01234，这个 0 实际是不需要的。

5、输出结果。倒序输出减法的结果数组 C，因为我们的个位是存储在下标为 0 的地方

**/
#include <iostream>
using namespace std;
const int MAXN = 200 + 4; //根据题目的最大值。+4为了防止A+B出现进位
char s1[MAXN] = {};       //存储字符串
char s2[MAXN] = {};       //存储字符串
int a[MAXN] = {};         //存储加数A
int b[MAXN] = {};         //存储加数B
int c[2 * MAXN] = {};     //存储和B
int main()
{
    scanf("%s %s", s1, s2); //读入字符串

    //处理负数
    bool flaga = false; //乘数a的符号
    if ('-' == s1[0])
    {
        flaga = true;
        strcpy(s1, &s1[1]); //删除负号
    }
    bool flagb = false; //乘数b的符号
    if ('-' == s2[0])
    {
        flagb = true;
        strcpy(s2, &s2[1]); //删除负号
    }

    //处理输出的负号
    if ((true == flaga && false == flagb) || (false == flaga && true == flagb))
    {
        printf("-");
    }

    //处理乘数1
    int lena = strlen(s1);
    for (int i = 0; i < lena; i++)
    {
        a[lena - i - 1] = s1[i] - '0';
    }

    //处理乘数2
    int lenb = strlen(s2);
    for (int i = 0; i < lenb; i++)
    {
        b[lenb - i - 1] = s2[i] - '0';
    }

    //模拟竖式乘法
    int jw; //上一轮计算进位
    for (int i = 0; i < lena; i++)
    {
        jw = 0;
        for (int j = 0; j < lenb; j++)
        {
            //交叉乘积
            c[i + j] = a[i] * b[j] + jw + c[i + j]; //当前乘积+上次乘积进位+原数
            jw = c[i + j] / 10;                     //处理进位
            c[i + j] %= 10;
        }
        c[i + lenb] = jw; //进位设置
    }

    //删除前导零
    int lenc = lena + lenb;
    for (int i = lenc - 1; i >= 0; i--)
    {
        //因为我们是从索引 0 开始，所以最高位是保存在 len-1
        if (0 == c[i] && lenc > 1)
        {
            //注意要有 lenc>1 这个条件。考虑特殊情况，加法结果为 00，我们实际要输出 0。
            lenc--;
        }
        else
        {
            //第一个不是零的最高位，结束删除
            break;
        }
    }

    //逆序打印输出
    for (int i = lenc - 1; i >= 0; i--)
    {
        printf("%d", c[i]);
    }
    printf("\n");

    return 0;
}