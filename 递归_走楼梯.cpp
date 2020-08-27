/**
用递归将问题分解为规模更小的子问题进行求解
例题: 爬楼梯
树老师爬楼梯，他可以每次走1级或者2级，输入楼梯的级数，
求不同的走法数
例如：楼梯一共有3级，他可以每次都走一级，或者第一次走一
级，第二次走两级，也可以第一次走两级，第二次走一级，一
共3种方法。
输入
输入包含若干行，每行包含一个正整数N，代表楼梯级数，1 <= N <= 30输出不同的走法数，每一行输入对应一行
样例输入
5 
8
10
样例输出
8 
34
89
**/
/**
思路:n级台阶的走法=先走一级后，n-1级台阶的走法 +先走两级后，n-2级台阶的走法
F(N)=F(N-1)+F(N-2)
边界条件
F(1)=1; F(2)=2;
**/
#include <iostream>
using namespace std;
int N;
int stairs(int n)
{
    if (n == 1)
        return 1;
    else if (n == 2)
        return 2;
    else
        return stairs(n - 1) + stairs(n - 2);
}
int main()
{
    while (cin >> N)
    {
        cout << stairs(N) << endl;
    }
    return 0;
}