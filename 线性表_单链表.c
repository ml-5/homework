/**
 一：线性表顺序存储结构是地址空间是连续的，链式结构不一定连续

二：顺序结构可以实现随机存取，但是删除插入不方便，需要移动大量元素，链式结构无法随机存取（必须从头开始找），但是删除、插入比较方便

三：顺序结构存储密度高，链式存储密度低
**/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
typedef struct LNode //定义单链表节点类型
{
    int data;
    struct LNode *next;
} LinkList;
void HCreatList(LinkList **L, int n);         //头插法建表
void ECreatList(LinkList **L, int n);         //尾插法建表
void InitList(LinkList **L);                  //初始化一个空链表，建立一个头结点
void DestroyList(LinkList **L);               //销毁链表
bool ListEmpty(LinkList **L);                 //判断表是否为空
int ListLength(LinkList **L);                 //返回节点的个数
void DispList(LinkList **L);                  //输出链表
bool GetElem(LinkList **L, int i, int *e);    //L中位置i的数据元素
int LocateElem(LinkList **L, int e);          //按元素查找位置
bool ListInsert(LinkList **L, int i, int e);  //插入数据元素
bool LiseDelete(LinkList **L, int i, int *e); //删除元素
int main()
{
    LinkList *head;
    int e;
    HCreatList(&head,6);
    printf("链表为空:%d   链表元素个数:%d\n",ListEmpty(&head),ListLength(&head));
    printf("输出:\n");
    DispList(&head);
    GetElem(&head,3,&e);
    printf("第3个位置的元素:%d  元素2的位置:%d",e,LocateElem(&head,2));
    ListInsert(&head,4,10);
    DispList(&head);
    LiseDelete(&head,4,&e);
    printf("%d",e);
    DispList(&head);
    DestroyList(&head);
}
void HCreatList(LinkList **L, int n)
{
    LinkList *s;
    int i;
    *L = (LinkList *)malloc(sizeof(LinkList));
    (*L)->next = NULL;
    for (i = 0; i < n; i++) //循环建立数据节点
    {
        s = (LinkList *)malloc(sizeof(LinkList));
        s->data = i;
        s->next = (*L)->next;
        (*L)->next = s;
    }
}
void ECreatList(LinkList **L, int n)
{
    LinkList *s, *r;
    int i;
    (*L) = (LinkList *)malloc(sizeof(LinkList)); //创建头结点
    r = (*L);
    for (i = 0; i < n; i++) //循环建立数据节点
    {
        s = (LinkList *)malloc(sizeof(LinkList));
        r->next = s;
        r = s;
    }
    r->next = NULL; //尾节点next域置为NULL
}
void InitList(LinkList **L)
{
    (*L) = (LinkList *)malloc(sizeof(LinkList)); //创建头结点
    (*L)->next = NULL;
}
void DestroyList(LinkList **L)
{
    LinkList *pre = *L, *p = (*L)->next; //pre指向p的前驱节点
    while (p != NULL)                    //扫描单链表
    {
        free(pre); //释放*pre
        pre = p;   //pre,p同步后移一个点
        p = pre->next;
    }
    free(pre); //循环结束，p为NULL，pre指向尾结点,释放它
}
bool ListEmpty(LinkList **L)
{   if((*L)->next==NULL)
    return 1;
    else
    return 0;
}
int ListLength(LinkList **L)
{
    int n = 0;
    LinkList *p = (*L); //p指向头节点,n置为0;
    while (p->next != NULL)
    {
        n++;
        p = p->next;
    }
    return n;
}
void DispList(LinkList **L)
{
    LinkList *p = (*L)->next; //p指向开始节点
    while (p != NULL)
    {
        printf("%d \t", p->data);
        p = p->next;
    }
    printf("\n");
}
bool GetElem(LinkList **L, int i, int *e)
{
    int j = 0;
    LinkList *p = (*L); //p指向头结点，j为0
    while (j < i && p != NULL)
    {
        j++;
        p = p->next;
    }
    if (p == NULL) //不存在第i个节点，返回false
        return false;
    else //存在第i个数据节点，返回true
    {
        *e = p->data;
        return true;
    }
}
int LocateElem(LinkList **L, int e)
{
    int i = 1;
    LinkList *p = (*L)->next; //p指向开始节点，i置为1
    while (p != NULL && p->data != e)
    {
        p = p->next;
        i++; //查找data值为e的节点,其序号为i
    }
    if (p == NULL)
        return 0;
    else
        return i;
}
bool ListInsert(LinkList **L, int i, int e)
{
    int j = 0;
    LinkList *p = (*L), *s; //p指向头结点，j置为0
    while (j < i - 1 && p != NULL)
    {
        j++;
        p = p->next;
    }
    if (p == NULL) //未找到第i-1个节点返回 false
        return false;
    else
    {
        s = (LinkList *)malloc(sizeof(LinkList));
        s->data = e;
        s->next = p->next; //将*s插入到*p之后
        p->next = s;
        return true;
    }
}
bool LiseDelete(LinkList **L, int i, int *e)
{
    int j = 0;
    LinkList *p = (*L), *q;        //p指向头结点
    while (j < i - 1 && p != NULL) //查找第i-1个节点
    {
        j++;
        p = p->next;
    }
    if (p == NULL) //未找到第i-1个节点返回 false
        return false;
    else
    {
        q=p->next;//q指向第i个节点
        if(q==NULL) //若不存在第i个节点返回false
        return false;
        *e=q->data;
        p->next=q->next;//从单链表中删除*q节点
        free(q);
        return true;//返回true表示成功删除第i个节点
    }
}
