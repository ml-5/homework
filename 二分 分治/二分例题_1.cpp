/**
求下面方程的一个根：f(x) = x3-5x2+10x-80 = 0
若求出的根是a，则要求 |f(a)| <= 10-6
**/
/*
解法：对f(x)求导，得f'(x)=3x2-10x+10。由一元二次方程求根公式知方程
f'(x)= 0 无解，因此f'(x)恒大于0。故f(x)是单调递增的。易知 f(0) < 0且
f(100)>0,所以区间[0,100]内必然有且只有一个根。由于f(x)在[0,100]内是单
调的，所以可以用二分的办法在区间[0,100]中寻找根。
*/
#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
double EPS = 1e-6;
double f(double x) { return x * x * x - 5 * x * x + 10 * x - 80; }
int main()
{
    double root, x1 = 0, x2 = 100, y;
    root = x1 + (x2 - x1) / 2;
    int triedTimes = 1; //记录一共尝试多少次，对求根来说不是必须的
    y = f(root);
    while (fabs(y) > EPS)
    {
        if (y > 0)
            x2 = root;
        else
            x1 = root;
        root = x1 + (x2 - x1) / 2;
        y = f(root);
        triedTimes++;
    }
    printf("%.8f\n", root);
    printf("%d", triedTimes);
    return 0;
}