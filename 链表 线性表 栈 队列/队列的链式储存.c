/**
队列的链式存储结构及其基本运算的实现
采用链表存储的队列称为链队，这里采用不带头节点的单链表实现。
通常将队头和队尾两个指针合起来
链队组成: 
（1）存储队列元素的单链表节点
（2）指向队头和队尾指针的链队头节点
采用循环单链表
链队的4要素：
队空的条件:front=rear=NULL
队满条件:不考虑
进队e操作:将包含e的节点插入到单链表表尾
出队操作:删除单链表的首数据节点
**/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define ElemType int
typedef struct Qnode //数据节点
{
    ElemType data; //数据元素
    struct Qnode *next;

} QNode;
typedef struct
{
    QNode *front; //指向头节点
    QNode *rear;  //指向尾节点
} LiQueue;

void InitQueue(LiQueue **q);           //初始化队列
void DestroyQueue(LiQueue *q);         //销毁队列
bool QueueEmpty(LiQueue *q);           //判断队列是否为空
void EnQueue(LiQueue **q, ElemType e); //进队
bool DeQueue(LiQueue *q, ElemType *e); //出队
int main()
{
}
void InitQueue(LiQueue **q)
{
    (*q) = (LiQueue *)malloc(sizeof(LiQueue));
    (*q)->front = (*q)->rear = NULL;
}
void DestroyQueue(LiQueue *q)
{
    QNode *p = q->front, *r; //p指向队头的数据节点
    if (p != NULL)
    {
        r = p->next;
        while (r != NULL)
        {
            free(p);
            p = r;
            r = p->next;
        }
    }
    free(p);
    free(q); //释放链队节点占用的空间
}
bool QueueEmpty(LiQueue *q)
{
    return (q->rear == NULL);
}
void EnQueue(LiQueue *q, ElemType e)
{
    QNode *p;
    p = (QNode *)malloc(sizeof(QNode));
    p->data = e;
    p->next = NULL;
    if (q->rear == NULL) //若链队为空,新节点是队首节点又是队尾节点
        q->front = q->rear = p;
    else
    {
        q->rear->next = p; //将*p节点链到队尾,并将rear指向它
        q->rear = p;
    }
}
bool DeQueue(LiQueue *q, ElemType *e)
{
    QNode *t;
    if (q->rear == NULL)
        return false;        //队列为空
    t = q->front;            //t指向第一个数据节点
    if (q->front == q->rear) //队列中只有一个节点时
        q->front = q->rear = NULL;
    else //队列中有多个节点时
        q->front = q->front->next;
    *e = t->data;
    free(t);
    return true;
}