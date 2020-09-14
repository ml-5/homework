/**
小数背包问题
问题描述：给定𝑛种物品和一个背包。物品𝑖的重量是𝑊𝑖，其价值为𝑉𝑖，背包的容量为C，应如何
选择装入背包的物品使得装入背包中物品的总价值最大? 这里，在选择物品𝑖装入背包时，可以选
择物品𝑖的一部分，而不一定要全部装入背包。
输入：多组测试数据。每组测试包括三行：第一行输入物品的总数𝑛(𝑛 < 1000）和背包的容量
𝐶(𝐶 < 1000)。第二行输入𝑛个整数，表示物品的重量。第三行输入物品的价值。
输出：输出装入背包的总价值，每组测试数据输出一行。
输入样例：
3 50
10 20 30
60 100 120
输出样例：
240
**/
/**
策略一：在不超出当前背包的剩余容量前提下，优先选择价值最大的物品，这样使得装
入价值增长最快。
策略二：在不超出当前背包的剩余容量前提下，优先选择重量最轻的物品，这样使得背包
容量增长最慢。
策略三：在不超出当前背包的剩余容量前提下，优先选择价值率（价值除以重量）最
大的物品，这样使得背包中单位重量价值增长最快。
策略三为最优

小数背包问题的贪心算法思路
1. 预处理，把物品按照价值率进行降序排列
2. 选择第一个物品 根据贪心策略，首先选择价值率最大的物品，并记录该物
品装入的重量。
3. 贪心选择后续活动 依次扫描每一个物品，在没有超出背包容量的条件下，
尽可能多地装入当前价值率最高的物品，并记录该物品装入的重量。
**/
#include <stdio.h>
#include <algorithm>
using namespace std;
#define MaxItems 1000
struct item
{
    int weight;
    int value;
    bool operator<(const item &bb) const
    {                                                                 //定义比较函数（小于号）
        return value / (1.0 * weight) > (1.0 * bb.value) / bb.weight; //为什么乘以1.0？
    }
}; //定义物品的结构体
double greedyKnapsack(int n, int capacity, item *itemSet)
{
    double ans = 0;
    sort(itemSet, itemSet + n); //STL中的快速排序算法
    for (int i = 0; i < n; i++)
        if (capacity >= itemSet[i].weight)
        {
            ans += itemSet[i].value; //选择单价最大的物品
            capacity -= itemSet[i].weight;
        }
        else
        {
            ans += capacity * (itemSet[i].value * 1.0) / itemSet[i].weight; //最后一个物品只能装部分
            break;
        }
    return ans;
}