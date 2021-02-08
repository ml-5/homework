/**
设有一个带有头结点的循环单链表，其节点值均为正值。设计一个算法，反复找出单链表
中节点的最小值并输出，然后将该节点删除，直到单链表为空为止，在删除表头节点

思路:对于循环单链表L,在不为空时循环，每次循环一次查找一个最小值的节点并删除它，最后释放头结点

**/
void Del_All(LinkList &L)
{
    LNode *p, *pre, *minp, *minpre;
    while (L->next != NULL)
    {
        p = L->next, pre = L; //p为工作指针,pre指向其前驱
        minp = p;
        minpre = pre; //minp指向最小的节点
        while (p != L)
        {
            if (p->data < minp->data)
            {
                minp = p;
                minpre = pre;
            }
            pre = p; //查找下一个节点
            p = p->next;
        }
        printf("%d", minp->data);  //输出最小节点的元素值
        minpre->next = minp->next; //最小值从中断开
        free(minp);
    }
    free(L);
}
