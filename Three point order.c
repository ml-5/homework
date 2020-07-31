//三点顺序
//方法:题目给出三点坐标（x1,y1）(x2,y2),(x3,y3)
//给出的是二维坐标系上的坐标，可以将其看成三维空间坐标系中xOy平面上的三角形
//坐标就是（x1,y1,0）(x2,y2,0),(x3,y3,0)
//可以得到向量AB 和向量AC
//AB=（x2-x1,y2-y1,0） AC=(x3-x1,y3-y1,0)
#include <stdio.h>
int main()
{
    int x1, y1, x2, y2, x3, y3;
    scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);
    int A = x2 - x1;
    int B = y2 - y1;
    int C = x3 - x1;
    int D = y3 - y1;
    if (A * D - B * C > 0)
        printf("0"); //逆时针
    else
        printf("1"); //顺时针
    return 0;
}
