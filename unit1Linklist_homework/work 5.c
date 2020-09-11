/**试编写算法将单链表就地逆置,所谓就地逆置是指空间复杂度为O(1)**/
//思路1:将头结点摘下,对后续节点进行头插法
void Inversion(LinkList *L)
{ //L是带头结点的单链表,本算法将L就地逆置
    LNode *p, *r;
    p = L->next;
    L->next = NULL;
    while (p != NULL)
    {
        r = p->next;       //保存p的后继
        p->next = L->next; //头插法
        L->next = p;
        p = r;
    }
    return L;
}
//思路2:pre p和r指向相邻的节点，如下图示。假设经过若干操作，pre之前的节点将指针翻转
LinkList Reverse(LinkList L)
{
    //依次遍历线性表L,并将节点指针翻转
    LNode *pre, *p = L->next, *r = p->next;
    p->next = NULL; //处理第一个节点
    while (r != NULL)
    {
        pre = p;
        p = r;
        r = r->next;
        p->next = pre; //指针翻转
    }
    L->next = p; //处理最后一个节点
    return L;
}
