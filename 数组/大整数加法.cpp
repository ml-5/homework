

/**
 * Description
比利经常会碰到超大整数的加法运算，而普通的计算器上无法进行。因此他想你帮他写一个程序来计算结果。

Input
输入数据有多组。首先输入一个整数T，表示有T组输入。

每组输入两个大整数，并用空格隔开。每个整数最多1000位。没有负数输入。

思路:
（1）运算顺序：两个数靠右对齐；从低位向高位运算；先计算低位再计算高位；
（2）运算规则：同一位的两个数相加，然后再加上从低位来的进位，成为该位的和；
       这个和再去掉向高位的进位就成为该位的值；如上例：3+8+1=12，向前一位进1，本位的值是2；
       可借助MOD、DIV运算完成这一步；
（3）最后一位的进位：如果完成两个数的相加后，进位位值不为0，则应添加一位；
（4）如果两个加数位数不一样多，则按位数多的一个进行计算；
**/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
    char a1[100], b1[100];
    int a[100], b[100], c[100];
    int a1_len, b1_len, lenc, i, x;
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(c, 0, sizeof(c));
    int T;
    cin >> T;

    while (T--)
    {
        //输入加数与被加数
        cin >> a1 >> b1;

        a1_len = strlen(a1);
        b1_len = strlen(b1);
        /*数字存入char型数组，要存入int型数组，需要减去48，可以查看ascii码表。
		道理如同大写字母变小写字符需要加32是一样的*/
        for (i = 0; i <= a1_len - 1; i++)
        {
            //将操作数逆序放入a数组
            a[a1_len - i] = a1[i] - 48;
        }

        for (i = 0; i <= b1_len - 1; i++)
        {
            //将操作数逆序放入b数组
            b[b1_len - i] = b1[i] - 48;
        }

        lenc = 1;
        x = 0;

        while (lenc <= a1_len || lenc <= b1_len)
        {
            c[lenc] = a[lenc] + b[lenc] + x; //两数相加
            x = c[lenc] / 10;                //要进的位
            c[lenc] = c[lenc] % 10;          //进位后的数
            lenc++;                          //数组下标加一
        }
        c[lenc] = x;
        if (c[lenc] == 0)
        {
            lenc--; //处理最高进位
        }

        for (i = lenc; i >= 1; i--)
        {
            cout << c[i]; //输出结果
        }
        cout << endl;
    }
    return 0;
}