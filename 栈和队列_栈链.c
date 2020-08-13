/**
3.1.3 栈的链式存储结构及其基本运算的实现
采用链表存储的栈称为链栈，这里采用带头节点的单链表实现。
链栈的4要素：
栈空条件：s->next=NULL
栈满条件：不考虑
进栈e操作：将包含e的节点插入到头节点之后
退栈操作：取出头节点之后节点的元素并删除之
**/
#include <stdio.h>
#include <stdbool.h>
typedef struct linknode
{
    ElemType data;         //数据域
    struct linknode *next; //数据域
} LiStack;
void InitStack(LiStack **s) //初始化栈
{
    *s = (LiStack *)malloc(sizeof(LiStack));
    (*s)->next = NULL;
}
void DestoryStack(LiStack **s)
{
    LiStack *p = s, *q = (*s)->next;
    while (q != NULL)
    {
        free(p);
        p = q;
        q = q->next;
    }
    free(p); //此时p指向尾节点
}
bool StackEmpty(LiStack *s)
{ //栈S为空的条件是s->next==NULL，即单链表中没有数据节点。
    return (s->next == NULL);
}
void Push(LiStack **s, ElemType e)
{
    LiStack *p;
    p = (LiStack *)malloc(sizeof(LiStack));
    p->data = e;
    p->next = (*s)->next; //插入p节点作为开始节点
    (*s)->next = p;
}
bool Pop(LiStack **s, ElemType *e)
{
    LiStack *p; //栈空情况
    if ((*s)->next == NULL)
        return false;
    p = (*s)->next; //p指向开始的节点
    *e = p->data;
    (*s)->next = p->next; //删除p节点
    free(p);              //释放p节点
    return true;
}
bool GetTop(LiStack *s, ElemType *e)
{
    if (s->next == NULL)
        return false;
    e = s->next->data;
    return true;
}