/**
 描述
石头剪刀布是常见的猜拳游戏。石头胜剪刀，剪刀胜布，布胜石头。如果两个人出拳一样，则不分胜负。

一天，小A和小B正好在玩石头剪刀布。已知他们的出拳都是有周期性规律的，比如：“石头-布-石头-剪刀-石头-布-石头-剪刀……”，就是以“石头-布-石头-剪刀”为周期不断循环的。请问，小A和小B比了N轮之后，谁赢的轮数多？

输入
输入包含三行。
第一行包含三个整数：N，NA，NB，分别表示比了N轮，小A出拳的周期长度，小B出拳的周期长度。0 < N,NA,NB < 100。
第二行包含NA个整数，表示小A出拳的规律。
第三行包含NB个整数，表示小B出拳的规律。
其中，0表示“石头”，2表示“剪刀”，5表示“布”。相邻两个整数之间用单个空格隔开。
输出
输出一行，如果小A赢的轮数多，输出A；如果小B赢的轮数多，输出B；如果两人打平，输出draw。
样例输入
10 3 4
0 2 5
0 5 0 2
样例输出
A
提示
对于测试数据，猜拳过程为：
A：0 2 5 0 2 5 0 2 5 0
B：0 5 0 2 0 5 0 2 0 5
A赢了4轮，B赢了2轮，双方打平4轮，所以A赢的轮数多。

思路:为了让数组存储的数据变成这样，我们可以设置一循环，因为最开始我们设置的数组a只存入了0 2 5三个数，但剩下还有7个数没有存入；
把具体的数值带进去可以便于理解，NA=3,N=10,i=0,j=3,当i<3,j<10时，a[3]=a[0]=0，a[4]=a[1]=2，a[5]=a[2]=5；这样就解决了后续的出拳规律的存储问题。最后用两个if，判断一下谁赢了次数就加1，最后比较谁赢的次数多就可以得出结果了
**/
#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int n, na, nb;
    int i, j;
    int a[105], b[105];
    int num_a, num_b;
    cin >> n >> na >> nb;
    for (i = 0; i < na; i++)
        cin >> a[i];
    for (i = 0; i < nb; i++)
        cin >> b[i];
    for (i = 0, j = na; i < na, j < n; i++, j++)
        a[j] = a[i];
    for (i = 0, j = nb; i < nb, j < n; i++, j++)
        b[j] = b[i];
    num_a = num_b = 0;
    for (i = 0; i < n; i++)
    {
        if ((a[i] == 0 && b[i] == 2) || (a[i] == 2 && b[i] == 5) || (a[i] == 5 && b[i] == 0))
            num_a++;
        if ((b[i] == 0 && a[i] == 2) || (b[i] == 2 && a[i] == 5) || (b[i] == 5 && a[i] == 0))
            num_b++;
    }
    if (num_a > num_b)
        printf("A");
    if (num_b > num_a)
        printf("B");
    if (num_a == num_b)
        printf("draw");
}