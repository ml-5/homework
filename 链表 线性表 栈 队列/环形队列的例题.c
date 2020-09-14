/**
对于环形队列来说，如果知道队头指针和队列
中元素个数，则可以计算出队尾指针。也就是说，可以用队列
中元素个数代替队尾指针。
设计出这种环形队列的初始化、入队、出队和判空算法。
思路:
已知front、rear，求队中元素个数count：
count=(rear-front+MaxSize)%MaxSize

已知front、count，求rear：
rear=(front+count)%MaxSize

已知rear、count，求front：
front=(rear-count+MaxSize)%MaxSize

环形队列的4要素
队空条件：count＝0 
队满条件：count＝MaxSize
进队e操作：rear=(rear+1)%MaxSize; 将e放在rear处 
出队操作：front=(front+1)%MaxSize; 取出front处元素e
**/
#include <stdio.h>
#include <stdbool.h>
#include <stdio.h>
#define MaxSize 10
#define ElemType int
typedef struct
{
    ElemType data[MaxSize];
    int front, count; //队头指针，队列的元素个数
} QuType;
void InitQueue(QuType **q);          //初始化队列运算
bool EnQueue(QuType *q, ElemType x); //进队运算
bool DeQueue(QuType *q, ElemType x); //出队运算
bool QueueEmpty(QuType *q);          //判断空队列
int main()
{
}
void InitQueue(QuType **q)
{
    *q = (QuType *)malloc(sizeof(QuType));
    (*q)->front = 0;
    (*q)->count = 0;
}
bool EnQueue(QuType *q, ElemType x)
{
    int rear;                //临时的队尾指针
    if (q->count == MaxSize) //队满上溢出
        return false;
    else
    {
        rear = (q->front + q->count) % MaxSize; //求队列队尾位置
        rear = (rear + 1) % MaxSize;            //队尾循环加1
        q->data[rear] = x;
        q->count++; //元素个数加1
        return true;
    }
}
bool DeQueue(QuType *q, ElemType x)
{
    if (q->count == 0)
        return false;
    else
    {
        q->front = (q->front + 1) % MaxSize;
        x = q->data[q->front];
        q->count--;
        return true;
    }
}
bool QueueEmpty(QuType *q)
{
    return (q->count == 0);
}
/**
注意
显然环形队列比非环形队列更有效的利用空间，不会出现假溢出
但如果算法中使用所有进队的元素一步步求解，此时可以使用非环形的队列

**/