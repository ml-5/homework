/*单链表牺牲空间效率*/
/*单链表的基本操作
  建立 插入 删除 查找*/
#include <stdio.h>
typedef int ElemType;
typedef struct Node /*节点类型定义*/
{
    ElemType data;
    struct Node *next;

} Node, *Linklist;       /*  *Linklist为结构指针类型*/
Linklist CreatFromHead() /*头插法建立*/
{
    Linklist L;
    Node *s;
    int flag = 1;
    char c;
    L = (Linklist)malloc(sizeof(Node));
    L->next = NULL;
    while (flag)
    {
        c = getchar();
        if (c != 'n')
        {
            s = (Node *)malloc(sizeof(Node));
            s->data = c;
            s->next = L->next;
            L->next = s;
        }
        else
        {
            flag = 0;
        }
    }
    return L;
}
Linklist CreatFromTail() /*将新加的节点插在尾部*/
{
    Linklist L;
    Node *r, *s;
    int flag = 1;
    char c;
    L = (Node *)malloc(sizeof(Node));
    L->next = NULL;
    r = L;
    while (flag)
    {
        c = getchar();
        if (c != 'n')
        {
            s = (Node *)malloc(sizeof(Node));
            s->data = c;
            r->next = s;
            r = s;
        }
        else
        {
            flag = 0;
            r->next = NULL;
        }
    }
    return L;
}
void InsList(Linklist L, int i, ElemType e)
{
    /*在头结点的单链表L中的第i个节点之前插入值为e的新节点*/
    Node *pre, *s;
    pre = L;
    int k = 0;
    while (pre != NULL && k < i - 1)
    {
        /*先找到第i-1个数据元素的存储位置,使指针Pre指向它*/
        pre = pre->next;
        k = k + 1;
    }
    if (k != i - 1)
    {
        printf("插入的位置不合理！");
        return;
    }
    s = (Node *)malloc(sizeof(Node));
    s->data = e;
    s->next = pre->next;
    pre->next = s;
}
void DellList(Linklist L, int i, ElemType *e)
{ /*在带头结点的单链表L中删除第i个元素，并保存其值到变量*e中*/
    Node *p, *r;
    p = L;
    int k = 0;
    while (p->next != NULL && k < i - 1) /*寻找被删除结点i的前驱结点*/
    {
        p = p->next;
        k = k + 1;
    }
    if (k != i - 1)
    /* 即while循环是因为p->next=NULL而跳出的*/
    {
        printf("删除结点的位置i不合理！");
        return -1;
    }
    r = p->next;
    p->next = p->next->next; /*释放被删除的结点所占的内存空间*/
    free(r);
}
int ListLength(Linklist L) /*L为带头结点的单链表*/
{
    Node *p;
    p = L->next;
    int j = 0; /*用来存放单链表的长度*/
    while (p != NULL)
    {
        p = p->next;
        j++;
    }
    return j;
}
Node *Get(Linklist L, int i)
{
    Node *p;
    p = L;
    int j = 0;
    /*从头结点开始扫描 */
    while ((p->next != NULL) && (j < i))
    {
        p = p->next;
        j++;
        /*扫描下一结点*/
    }
    /*已扫描结点计数器 */
    if (i == j)
        return p;
    /*找到了第i个结点*/
    else
        return NULL;
    /*找不到，i≤0或i >n*/
}
Node *Locate(Linklist L, ElemType key)
{
    Node *p;
    p = L->next;
    /*从表中第一个结点比较*/
    while (p != NULL)
        if (p->data != key)
            p = p->next;
        else
            break;
    /*找到结点key，退出循环 */
    return p;
}
/*已知：以单链表表示集合，假设集合A用单链表LA表示，集合B用
单链表LB表示，设计算法求两个集合的差，即A-B。 • 算法思想：由集合运算的规则可知，集合的差A-B中包含所有属于
集合A而不属于集合B的元素。具体做法是，对于集合A中的每个元
素e，在集合B的链表LB中进行查找，若存在与e相同的元素，则从
LA中将其删除*/
void Difference(Linklist LA, Linklist LB) /*此算法求两个集合的差集*/
{
    Node *pre, *p, *r, *q;
    pre = LA;
    p = LA->next; /*p向表中的某一结点，pre始终指向p的前驱*/
    while (p != NULL)
    {
        q = LB->next; /*扫描LB中的结点，寻找与LA中*P结点相同的结点*/
        while (q != NULL && q->data != p->data)
            q = q->next;
        if (q != NULL)
        {
            r = p;
            pre->next = p->next;
            p = p->next;
            free(r);
        }
        else
        {
            pre = p;
            p = p->next;
        }
    }
}