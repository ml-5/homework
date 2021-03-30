/*
1~n这n个整数排成一排一行后随即打乱顺序，输出所有的可能的顺序

*/
#include <iostream>
using namespace std;
int order[20]; //俺顺序依次记录被选择的数
int chose[20]; //标记被选择的数
const int n = 5;
void calc(int k)
{
    if (k == n + 1)
    {
        for (int i = 1; i <= n; i++)
        {
            printf("%d ", order[i]);
        }
        puts(" ");
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (chose[i])
            continue; //如果访问过就找下一个
        order[k] = i; //把i放在第k位
        chose[i] = 1; //标记一下
        calc(k + 1);  //继续找下一个位置
        chose[i] = 0; //标记还原
    }
}
int main()
{
    calc(1);
}