/*
常见模型：找出滑动窗口中的最大值/最小值
int hh = 0, tt = -1;
for (int i = 0; i < n; i ++ )
{
    while (hh <= tt && check_out(q[hh])) hh ++ ;  // 判断队头是否滑出窗口
    while (hh <= tt && check(q[tt], i)) tt -- ;
    q[ ++ tt] = i;
}
*/
#include <iostream>
using namespace std;

const int N = 1000010;
int a[N], q[N];

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int hh = 0, tt = -1;
    /*
队列中存储的是下标索引，这样才能时刻保证队列长度小于等于窗口
每次遍历是准备把一个元素的下标入队
但必须保证这个下标入队后，队列仍然单调递增(因为此时是求滑动窗口最小值)
*/
    for (int i = 0; i < n; i++)
    {
        /*
首先判断当这个元素的下标入队后，当前的队头元素是否会滑出窗口
i - k + 1 代表当前元素的下标i入队后，队列大小为k的队头元素的下标
而且又因为每次遍历最多一个下标入队，一个下标出队，所以if就行，不需要模板的while
*/
        if (hh <= tt && i - k + 1 > q[hh])
            hh++;
        //注意这里的q[tt]和i都是数组a的下标
        while (hh <= tt && a[q[tt]] >= a[i])
            tt--;
        q[++tt] = i;
        /*
另外这里是先把下标入队之后再去判断是否要输出答案，所以不需要像单调栈一样
先考虑跳出while循环是否因为队列为空，是否要输出-1
*/
        if (i >= k - 1)
            cout << a[q[hh]] << ' ';
        /*
前几个元素不需要输出答案，以及当前入队的下标对应的元素可能会是之后窗口的最小值
但此时窗口的最小值是队头元素这个下标所对应的元素
*/
    }
    //输出格式，换行注意
    puts("");

    hh = 0, tt = -1;
    for (int i = 0; i < n; i++)
    {
        if (hh <= tt && i - k + 1 > q[hh])
            hh++;

        while (hh <= tt && a[q[tt]] <= a[i])
            tt--;
        q[++tt] = i;

        if (i >= k - 1)
            cout << a[q[hh]] << ' ';
    }

    puts("");

    return 0;
}