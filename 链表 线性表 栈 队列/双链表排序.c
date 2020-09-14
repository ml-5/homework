void sort(DLinKNode *L)
{
    DLinkNode *p, *pre, *q;
    p = L->next->next;    //p指向第2数据节点
    L->next->next = NULL; //构造只含一个数据结点
    while (p != NULL)
    {
        q = p->next;
        pre = L;
        while (pre->next != NULL && pre->next->data < p->data)
            pre = pre->next;
        p->next = pre->next;
        if (pre->next != NULL)
            pre->next->prior = p;
        pre->next = p;
        p->prior = pre;
        p = q; //扫描双链表余下的结点
    }
}