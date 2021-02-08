/**
采用递归算法求解迷宫问题，并输出从入口到出口的所有迷宫路径。
思路:从入口找到出口这个大问题分解为入口走一步，加上一个小问题
递归模型如下
mgpath(xi,yi,xe,ye,path)  将(xi,yi)添加到path中;若(xi,yi)=(xe,ye)，输出path中的迷宫路径; 

mgpath(xi,yi,xe,ye,path)  对于(xi,yi)四周的每一个相邻方块(i,j)：
                          1.将(xi,yi)添加到path中;
                          2.置mg[xi][yi]=-1;
                          3.mgpath(i,j,xe,ye,path);
                          4.path回退一步mg[xi][yi]=0;
**/
#include <stdio.h>
#include <stdlib.h>
#define MaxSize 100
#define M 4
#define N 4
int mg[M + 2][N + 2] =
    {{1, 1, 1, 1, 1, 1},
     {1, 0, 0, 0, 1, 1},
     {1, 0, 1, 0, 0, 1},
     {1, 0, 0, 0, 1, 1},
     {1, 1, 0, 0, 0, 1},
     {1, 1, 1, 1, 1, 1}};
typedef struct
{
    int i, j; //行号列号

} Box;
typedef struct
{
    Box data[MaxSize];
    int length; //路径的长度
} PathType;     //定义路径类型
void mgpath(int xi, int yi, int xe, int ye, PathType path)
//求解路径为:(xi,yi) ——> (xe,ye)
{
    int di, k, i, j, count = 0;
    if (xi == xe && yi == ye)
    {
        path.data[path.length].i = xi;
        path.data[path.length].j = yi;
        path.length++;
        printf("迷宫路径%d如下:\n", ++count);
        for (k = 0; k < path.length; k++)
        {
            printf("\t(%d,%d)", path.data[k].i, path.data[k].j);
            if ((k + 1) % 5 == 0) //每输出每5个方块后换一行
                printf("\n");
        }
        printf("\n");
    }    //找到了出口，输出一条路径（递归出口）
    else //(xi,yi)不是出口
    {
        if (mg[xi][yi] == 0) //(xi,yi)是一个可走方块
        {
            di = 0;
            while (di < 4) //对于(xi,yi)四周的每一个相邻方位di
            {
                switch (di) //找方位di对应的方块(i,j)
                {
                case 0:
                    i = xi+1;
                    j = yi;
                    break;
                case 1:
                    i = xi-1;
                    j = yi;
                    break;
                case 2:
                    i = xi;
                    j = yi-1;
                    break;
                case 3:
                    i = xi;
                    j = yi+1;
                    break;
                }
                path.data[path.length].i = xi;
                path.data[path.length].j = yi;
                path.length++;   //路径长度增1
                mg[xi][yi] = -1; //避免来回重复找路径
                mgpath(i, j, xe, ye, path);
                path.length--;
                mg[xi][yi] = 0; //恢复(xi,yi)为可走
                di++;
            }
        }
    }
}
int main()
{
    PathType path;
    path.length = 0;
    mgpath(1, 1, 4, 4, path);
    return 0;
}