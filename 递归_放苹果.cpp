/**
例题：放苹果
把M个同样的苹果放在N个同样的盘子里，允许有的盘子空着不放，
问共有多少种不同的分法？5，1，1和1，5，1 是同一种分法。
输入
第一行是测试数据的数目t（0 <= t <= 20）。以下每行均包含二个整
数M和N，以空格分开。1<=M，N<=10。
输出
对输入的每组数据M和N，用一行输出相应的K。
样例输入
1 
7 3
样例输出
8

思路: 设i个苹果放k个盘子的总数是f(i,k),则

1.k>i时, f(i,k)=f(i,i) 空盘子直接拿走

2.k<=i时,总方法=有盘子为空方法+没盘子没空的方法
         f(i,k)=f(i,k-1)+f(i-k,k)
**/
#include <iostream>
using namespace std;
int f(int m, int n)
{
    if (n > m) //盘子数大于苹果数
        return f(m, m);
    if (m == 0) //苹果数为0
        return 1;
    if (n <= 0) //盘子数为0
        return 0;
    return f(m, n - 1) + f(m - n, n);
}
int main()
{
    int t, m, n;
    cin >> m >> n;
    cout << f(m, n) << endl;
    return 0;
}