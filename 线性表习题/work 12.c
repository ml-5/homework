/**
在一个递增有序的线性表中，有数值相同的元素，若储存方式为单链表，设计算法去掉相同数值的元素
使其表中不在有重复的元素。eg(7,10,10,21,30,42,42,42,51,70) 
**/
//算法思想：由于是有序表，所有相同值域的节点都是相邻的，用p扫描单链表L,若*p的节点值域等于后面的节点值域则删除后者
void Del_Same(LinkList &L)
{
    //L递增有序的单链表，本算法删除表中数值相同的元素
    LNode *p = L->next, *q;
    if (p == NULL)
        return;
    while (p->next != NULL)
    {
        q = p->next; //q指向p的后继节点
        if (p->data == q->data)
        {
            p->next = q->next; //删除q节点
            free(q);           //释放空间
        }
        else
        {
            p = p->next;
        }
    }
}