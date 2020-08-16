/**
队列的定义:
队列简称队，它也是一种运算受限的线性表。
队列只能选取一个端点进行插入操作，另一个端点进行删除操作
概念
把进行插入的一端称做队尾（rear）。
进行删除的一端称做队首或队头（front）。
向队列中插入新元素称为进队或入队，新元素进队后就成为新
的队尾元素。
从队列中删除元素称为出队或离队，元素出队后，其后继元素
就成为队首元素。
队列的主要特点是先进先出，所以又把队列称为先进先出表。

约定rear总是指向队尾元素
元素进队，rear增1
约定front指向当前队中队头元素的前一位置
元素出队，front增1 当rear=MaxSize-1时不能再进队

队空条件：front = rear
队满条件：rear = MaxSize－1
元素e进队：rear++; data[rear]=e;
元素e出队：front++; e=data[front];
**/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ElemType int
#define MaxSize 20
typedef struct node
{
    ElemType data[MaxSize];
    int front, rear; //队首指针和队尾指针
} SqQueue;
void InitQueue(SqQueue **q);           //初始化队列
void DestoryQueue(SqQueue *q);         //销毁队列
bool QueueEmpty(SqQueue *q);           //判断队列是否为空
bool EnQueue(SqQueue *q, ElemType e);  //进队列
bool DeQueue(SqQueue *q, ElemType *e); //队空下溢出
int main()
{
    SqQueue *q;
    int i, e;
    InitQueue(&q);
    if (QueueEmpty(q))
        for (i = 0; i < 10; i++)
        {
            if (EnQueue(q, i))
            {
                printf("进队元素:%d\n", i);
            }
        }
    for (i = 0; i < 10; i++)
    {
        if (DeQueue(q, &e))
        {
            printf("出队元素:%d\n", e);
        }
    }
    DestoryQueue(q);
}
void InitQueue(SqQueue **q)
{
    *q = (SqQueue *)malloc(sizeof(SqQueue));
    (*q)->front = (*q)->rear = -1;
}
void DestoryQueue(SqQueue *q)
{
    free(q);
}
bool QueueEmpty(SqQueue *q)
{
    return (q->front == q->rear);
}
bool EnQueue(SqQueue *q, ElemType e)
{
    if (q->rear == MaxSize - 1) //队列上溢出
        return false;
    q->rear++;
    q->data[q->rear] = e;
    return true;
}
bool DeQueue(SqQueue *q, ElemType *e)
{
    if (q->front == q->rear)
        return false;
    q->front++;
    *e = q->data[q->front];
    return true;
}