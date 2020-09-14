/**
采用一个不带头节点只有一个尾节点指针rear的循环
单链表存储队列，设计队列的初始化、进队和出队等算法
链队的4要素：
队空条件：rear=NULL
队满条件：不考虑
进队e操作：将包含e的节点插入到单链表表尾
出队操作：删除单链表首节点
**/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define ElemType int
typedef struct node
{
    int data;
    struct node *next;
} LinkList;
void InitQueue(LinkList **rear) //初始化
{
    (*rear) = (LinkList *)malloc(sizeof(LinkList));
    *rear = NULL;
}
bool QueueEmpty(LinkList *rear) //判断空运算算法
{
    return (rear == NULL);
}
void EnQueue(LinkList *rear, ElemType x)
{
    LinkList *p;
    p = (LinkList *)malloc(sizeof(LinkList));
    p->data = x;
    if (rear == NULL)
    {
        p->next = p;
        rear = p;
    }
    else
    {
        p->next = rear->next;
        rear->next = p;
        rear = p;
    }
}
bool DeQueue(LinkList *rear, ElemType *x) //出队运算
{
    LinkList *q;
    if (rear == NULL)
        return false;            //队空
    else if (rear->next == rear) //原队中只有一个节点
    {
        x = rear->data;
        free(rear);
    }
    else
    {
        q = rear->next;
        x = q->data;
        rear->next = q->next;
        free(q);
    }
    return true;
}