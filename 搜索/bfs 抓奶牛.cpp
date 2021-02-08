#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int N, K;
const int MAXN = 1e5;
int visited[MAXN + 10]; //判重标记
struct Step
{
    int x;    //位置
    int step; // 到达所需要的步数
    Step(int xx, int s)::x(xx), steps(s) {}
};
queue<Step> q; //队列
int main()
{
    cin >> N >> K;
    memset(visited, 0, sizeof(visited));
    q.push(step(N, 0));
    visited[N] = 1;
    while (!q.empty())
    {
        Step s = q.front();
        if (s.x == k)
        {
            cout << s.step << endl;
            return 0;
        }
        else
        {
            if (s.x - 1 >= 0 && !visited[s.x - 1])
            {
                q.push(Step(s.x - 1, s.steps + 1));
                visited[s.x - 1] = 1;
            }
            if (s.x + 1 <= MAXN && !visited[s.x + 1])
            {
                q.push(Step.(s.x + 1, s.steps + 1));
                visited[s.x + 1] = 1;
            }
            if (s.x * 2 <= MAXN && !visited[s.x * 2])
            {
                q.push(Step(s.x * 2, s.step + 1));
                visited[s.x * 2] = 1;
            }
            q.pop();
        }
    }
    return 0;
}

/**广度优先搜索(Breadth First Search, BFS)
是对树的逐层遍历，或者说，是对树的横向遍历。bfs是盲目的。

    bfs常被用来求解达到某目标所需的 最少步骤数。例如poj3278，给定两个自然数n与k，每一步的移动有三种可能，n +
    1、n - 1和n * 2，问，从n出发，到达k所需要的最小移动次数。举个例子，n = 5，k = 17，则bfs步骤如下： 有 两点 需要说明： 1.注意红色的叉，在搜索过程中可能产生已经搜索过的节点，这时要跳过。 2.已经搜索过第i层的节点，那么第i +
                                                                                  1层的搜索从哪个节点开始？这时需要设置一个队列，i层已经搜索过的节点入队（在对第i - 1层的节点分叉时），然后依次作为第i + 1层节点的父节点出队。

                                                                                  下面是代码： int step[MAX]; //访问到指定节点所需的步数
bool visited[MAX];                                                                                            //指定节点是否已被访问
queue<int> bfstree;                                                                                           //已访问的节点入队，用以引出要访问的下一层节点

memset(visited, false, sizeof(visited)); //初始时，所有节点都未被访问

int bfs()
{
    int head, next;

    visited[n] = 1;  //第一个节点被访问
    step[n] = 0;     //需要0步到达第一个节点
    bfstree.push(n); //进队，用以引出下一层

    while (!bfstree.empty())
    {
        head = bfstree.front();
        bfstree.pop();

        //父节点有三个分支
        for (int i = 0; i < 3; ++i)
        {
            if (i == 0)
                next = head - 1;
            else if (i == 1)
                next = head + 1;
            else
                next = head * 2;

            if (next < 0 || next >= MAX)
                continue; //防止访问的节点越界

            if (!visited[next]) //已访问的节点需要被跳过
            {
                visited[next] = 1;
                step[next] = step[head] + 1;
                bfstree.push(next);
            }

            if (next == k)
                return step[next];
        }
    }

    return -1;
}
**/