/** 在带头结点的单链表L中，删除所有值为x的节点，并释放其空间，假设值为x的节点不唯一**/
//思路：解法1:用p从头到尾扫描单链表，pre指向p的前驱节点,若p所指节点值为x,则删除,并让p移项下一个节点,否则pre，p同步后移
void Del_x(Linklist *L, int x)
{
    //L为带头结点单链表,本算法删除L中所有值为x节点
    LNode *p = L->next, *pre = L, *q; //置p和pre的初始值
    while (p != NULL)
    {
        if (p->data == x)
        {
            q = p;
            p = p->next;
            pre->next = p; //删除*q的节点
            free(q);
        }
        else //否则pre p同步后移
        {
            pre = p;
            p = p->next;
        }
    }
}
//解放2:采用尾插法建立.用p指针扫描L的所有节点，当值不为x时将其链接到L之后
void Del_x2(Linklist *L, int x)
{
    //L为带头结点单链表,本算法删除L中所有值为x节点
    LNode *p = L->next, *r = L, *q; //r指向尾结点
    while (p != NULL)
    {
        if (p->data != x)
        {
            r->next = p;
            r = p;
            p = p->next;
        }
        else
        {
            q = p;
            p = p->next; //继续扫描
            free(q);     //释放空间
        }
    }
    r->next = NULL;
}