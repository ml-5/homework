/**
思路:  在求解迷宫问题中，首先是用栈的来实现操作，一步步入栈出栈，最后找到出路，虽然找到的路劲不是最佳路径，
但是这是一种人工智能的算法，符合人的思维方式，是现实生活中人解决迷宫问题的方式；
而用队列实现迷宫问题的求解时，依次探索路径放入队列中，并对每个元素设置好前驱标志，
这样一直遍历到终点时，按照前驱进行探索，输出整个迷宫的倒序，并对这些坐标进行编码，
再一次遍历迷宫输出路径，即队列实现迷宫的方法；
**/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MaxSize 60
#define M 8
#define N 8
typedef struct
{
    int i, j; //方块的位置
    int pre   //本路径中上一方块在队列中的下标
} Box;        //方块类型
typedef struct
{
    Box data[MaxSize];
    int front, rear; //队头指针和队尾指针
} QuType;            //定义顺序队类型
int mg[M + 2][N + 2] =
    {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
     {1, 0, 0, 1, 0, 0, 0, 1, 0, 1},
     {1, 0, 0, 1, 0, 0, 0, 1, 0, 1},
     {1, 0, 0, 0, 0, 1, 1, 0, 0, 1},
     {1, 0, 1, 1, 1, 0, 0, 0, 0, 1},
     {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
     {1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
     {1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
     {1, 1, 0, 0, 0, 0, 0, 0, 0, 1},
     {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

void print(QuType p)
{
    int t = p.front;
    while (p.data[t].pre != -1)
    {
        printf("(%d,%d) ", p.data[t].i, p.data[t].j);
        t = p.data[t].pre;
    }
    printf("(1,1)");
}
bool MgPath(int xi, int yi, int xe, int ye)
{
    int i, j, find = 0, di;
    QuType q;
    q.front = q.rear = -1;
    q.rear++;
    q.data[q.rear].i = xi;
    q.data[q.rear].j = yi; //(xi,yi)进队
    q.data[q.rear].pre = -1;
    mg[xi][yi] = -1;                   //将其值赋值为-1，以避免回过来重复搜索
    while (q.front != q.rear && !find) //队列不为空循环
    {
        q.front++;
        i = q.data[q.front].i;
        j = q.data[q.front].j;
        if (i == xe && j == ye)
        {
            find = 1;
            print(q);
            return true;
        }
        for (di = 0; di < 4; di++)
        {
            switch (di)
            {
            case 0:
                i = q.data[q.front].i - 1;
                j = q.data[q.front].j;
                break;
            case 1:
                i = q.data[q.front].i;
                j = q.data[q.front].j + 1;
                break;
            case 2:
                i = q.data[q.front].i + 1;
                j = q.data[q.front].j;
                break;
            case 3:
                i = q.data[q.front].i;
                j = q.data[q.front].j - 1;
                break;
            }
            if (mg[i][j] == 0)
            {
                q.rear++; //将该相邻的方块插入
                q.data[q.rear].i = i;
                q.data[q.rear].j = j;
                q.data[q.rear].pre = q.front;
                mg[i][j] = -1;
            }
        }
    }
    return false;
}
int main()
{
    if (!MgPath(1, 1, 8, 8))
        printf("无解");
}