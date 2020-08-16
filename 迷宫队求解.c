#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MaxSize 30
typedef struct
{ int i,j; //方块的位置
int pre //本路径中上一方块在队列中的下标
} Box; //方块类型
typedef struct
{ Box data[MaxSize];
int front,rear; //队头指针和队尾指针
} QuType; //定义顺序队类型
