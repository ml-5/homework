/*
从 1~n这n个整数中随机选任意多个，输出所有的可能方案
*/
#include <iostream>
#include <vector>
using namespace std;
int n=6;
vector<int> chosen;
void calc(int x)
{
    if (x == n + 1)
    {
        for (auto x : chosen)
            cout << x;
        puts("");
        return;
    }
    calc(x + 1);         //求解子问题不选x
    chosen.push_back(x); //记录x已被选择
    calc(x + 1);
    chosen.pop_back(); //回溯，还原现场
}
int main()
{
    calc(1);
}
