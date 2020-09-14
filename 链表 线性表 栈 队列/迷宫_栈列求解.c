/**
栈和队列都是存放多个数据的容器。通常用于存放临时数
据：
如果先放入的数据先处理，则使用队列。
如果后放入的数据先处理，则使用栈。

用栈求解
给定一个M×N的迷宫图、入口与出口、行走规则。求一条
从指定入口到出口的路径。
所求路径必须是简单路径，即路径不重复。
用阴影表示障碍物。为了算法方便，一般在迷宫外围加上了一条围墙。
思路:
行走规则：上 0、下 2、左3、右 1相邻方块行走。其中（i，j）表
示一个方块
设置一个迷宫数组mg，其中每个元素表示一个方块的状态，
为0时表示对应方块是通道，为1时表示对应方块不可走。

从方位0开始，顺时针方向试探 0 1 2 3，初始时候入口(i,j)作为当前方块
将入口进栈，如果一个当前方块找到一个相邻可走方块继续从(x,y)走下去
如果当前方块(i,j)没有找到任何相邻可走的方块，则表示无路可走，将其推栈

求解迷宫的过程：
前一方块---->当前方块(所有方块不能走)回溯
找到其它可能的相邻方块
        
**/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define M 8
#define N 8
#define MaxSize 50
typedef struct
{
    int i, j, di; //当前行号，列号，di表示下一方块方位
} Box;
typedef struct
{
    Box data[MaxSize];
    int top; //栈顶指针
} StType;    //定义顺序栈类型

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
bool MgPath(int xi, int yi, int xe, int ye)
{
    int i, j, k, di, find;
    StType st;   //定义栈st初始化
    st.top = -1; //初始化
    st.top++;
    st.data[st.top].i = xi;
    st.data[st.top].j = yi;
    st.data[st.top].di = -1;
    mg[xi][yi] = -1;    //为了避免重复，当前方块进，将迷宫改为-1
    while (st.top > -1) //栈不为空
    {
        i = st.data[st.top].i;
        j = st.data[st.top].j;
        di = st.data[st.top].di; //取栈定方块
        if (i == xe && j == ye)  //找到了出口 ，输出路径
        {
            printf("迷宫路径如下:\n");
            for (k = 0; k <= st.top; k++)
            {
                printf("\t(%d,%d)", st.data[k].i, st.data[k].j);
                if ((k + 1) % 5 == 0) //每输出每5个方块后换一行
                    printf("\n");
            }
            printf("\n");
            return true; //找到一条路径后返回true
        }
        find = 0;
     
        while (di < 4 && find == 0) //找到下一个可走方块
        {
            di++;
            switch (di)
            {
            case 0:
                i = st.data[st.top].i - 1;
                j = st.data[st.top].j;
                break;
            case 1:
                i = st.data[st.top].i;
                j = st.data[st.top].j + 1;
                break;
            case 2:
                i = st.data[st.top].i + 1;
                j = st.data[st.top].j;
                break;
            case 3:
                i = st.data[st.top].i;
                j = st.data[st.top].j - 1;
                break;
            }
            if (mg[i][j] == 0)
                find = 1; //找到一个相邻可走方块
        }
        if (find == 1) //找到下一个可走方块
        {
            st.data[st.top].di = di; //修改原栈顶元素的di值
            st.top++;
            st.data[st.top].i=i;
            st.data[st.top].j = j;
            st.data[st.top].di = -1;
            mg[i][j] = -1; //避免重复走到方块
        }
        else //没有路径可走,则退栈
        {
            mg[st.data[st.top].i][st.data[st.top].j] = 0;
            //让该位置变为其他路径可走方块
            st.top--; //将该方块退栈
        }
    }
    return false; //表示没有路可走路径,返回false
}
int main()
{
    if (!MgPath(1, 1, M, N))
        printf("该迷宫没有解!");
    return 0;
}