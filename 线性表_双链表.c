#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
typedef struct DNode
{
    int data;
    struct DNode *prior; //指向前驱节点
    struct DNode *next;  //指向后继节点
} DLinkList, *Link;
void CreatListF(Link *L, int n);             //头插法
void CreatListR(Link *L, int n);             //尾插法
bool ListInsert(DLinkList *L, int i, int e); //插入
bool ListDelete(Link *L, int i, int *e);     //删除
void CreatListF(Link *L, int n)
{
    DLinkList *s;
    int i;
    *L = (DLinkList *)malloc(sizeof(DLinkList)); //创建头节点
    (*L)->prior = (*L)->next = NULL;             //前后指针域置为NULL
    for (i = 0; i < n; i++)
    {
        s = (DLinkList *)malloc(sizeof(DLinkList));
        s->data = i;
        s->next = (*L)->next;
        if ((*L)->next != NULL) //若L存在数据节点，修改前项指针
            (*L)->next->prior = s;
        (*L)->next = s;
        s->prior = (*L);
    }
}
void CreatListR(Link *L, int n)
{
    DLinkList *s, *r;
    int i;
    L = (DLinkList *)malloc(sizeof(DLinkList)); //创建头结点
    r = L;                                      //r始终指向尾结点,开始指向头结点
    for (i = 0; i < n; i++)
    {
        s = (DLinkList *)malloc(sizeof(DLinkList));
        s->data = i;
        r->next = s;  //将s插入r
        s->prior = r; //r指向尾结点
        r = s;
    }
    r->next = NULL;
}
bool ListInsert(Link *L, int i, int e)
{
    int j = 0;
    DLinkList *p = *L, *s;         //p指向头结点,j设置为0
    while (j < i - 1 && p != NULL) //查找i-1的节点
    {
        j++;
        p = p->next;
    }
    if (p == NULL) //未找到第i-1个节点，返回false
        return false;
    else
    {
        s = (DLinkList *)malloc(sizeof(DLinkList));
        s->data = e;         //创建新节点s
        s->next = p->next;   //在p之后插入s节点
        if (p->next != NULL) //若存在后继节点,修改其前驱节点的指向
            p->next->prior = s;
        s->prior = p;
        p->next = s;
        return true;
    }
}
bool ListDelete(Link *L, int i, int *e)
{
    int j = 0;
    DLinkList *p = (*L), *q;       //p指向头结点
    while (j < i - 1 && p != NULL) //查找第i-1个节点
    {
        j++;
        p = p->next;
    }
    if (p == NULL) //未找到第i-1个节点
        return false;
    else
    {
        q = p->next; //q指向第i个节点
        if (q == NULL)
            return false; //当不存在第i个节点时返回false
        *e = q->data;
        p->next = q->next;   //从双链表中删除q节点
        if (p->next != NULL) //修改其前驱指针
            p->next->prior = p;
        free(q); //释放q节点
        return true;
    }
}