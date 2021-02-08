/**
设A和B是两个单链表(带头结点),其中元素递增有序，设计一个算法从A和
B中公共元素产生单链表C,要求不破坏A,B的节点

思路：表A和表B都有序，可以从第一个元素开始比较A,B的元素，若元素不等
则小的指针往后移动，若相等，则创建一个值等于两节点的新节点，使用尾插法
插入到新表中
**/
void Get_Common(LinkList A, LinkList B)
{
    //本算法产生单链表A和B的公共元素的单链表C
    LNode *p = A->next, *q = B->next, *r, *s;
    LinkList C = (LinkList)malloc(sizeof(LNode)); //建立表c
    r = C;
    while (p != NULL && q != NULL)
    {
        if (p->data < q->data)
            p = p->next;
        else if (p->data > q->data)
            q = q->next;
        else
        {
            s = (LNode *)malloc(sizeof(LNode));
            s->data = p->data;
            r->next = s;
            r = s;
            p = p->next;
            q = q->next;
        }
    }
    r->next = NULL;
}