/*
从1~n这n个整数中随机选取m个,输出所有的可能的选择
方案
*/
#include <iostream>
#include <vector>
using namespace std;
int n = 10;
int m = 2;
vector<int> chosen;
void calc(int x)
{
    if (chosen.size() > m || chosen.size() + (n - x + 1) < m)
        return;
    if (x == n + 1)
    {
        for (int i = 0; i < chosen.size(); i++)
            cout << chosen[i];
        puts("");
        return;
    }
    calc(x + 1);         //求解子问题
    chosen.push_back(x); //记录x已被选择
    calc(x + 1);         //求解子问题
    chosen.pop_back();   //回溯，还原现场
}
int main()
{
    calc(1);
}
