/**
 总时间限制: 1000ms 内存限制: 65536kB
描述
一个长度为n（n>0）的序列中存在“有趣的跳跃”当前仅当相邻元素的差的绝对值经过排序后正好是从1到(n-1)。例如，1 4 2 3存在“有趣的跳跃”，因为差的绝对值分别为3,2,1。当然，任何只包含单个元素的序列一定存在“有趣的跳跃”。你需要写一个程序判定给定序列是否存在“有趣的跳跃”。
输入
一行，第一个数是n（0 < n < 3000），为序列长度，接下来有n个整数，依次为序列中各元素，各元素的绝对值均不超过1,000,000,000。
输出
一行，若该序列存在“有趣的跳跃”，输出"Jolly"，否则输出"Not jolly"。
样例输入
4 1 4 2 3
样例输出
Jolly
**/
//思路:定义个数组保存差值，后排序进行比对判断
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>//提供sort
using namespace std;
long long num[3001]; //保存数据
long long dis[3001]; //保存差值
long long nums[3001];
int main()
{
    int n;
    long long flag = 1;
    long long sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    for (int i = 0; i < n; i++)
    {
        dis[i] = abs(num[i + 1] - num[i]);//赋值给dis
    }
    sort(dis, dis + n); //对差值进行排序
    for (int i = 0; i < n; i++)//比对
    {
        if (nums[i] == dis[i])
            sum++;
    }
    if (sum == n - 1 || n == 1)//判断是否sum==n-1既有n-1个差值
        cout << "Jolly" << endl;
    else
        cout << "Not jolly" << endl;
    return 0;
}