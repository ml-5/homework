/**
设计一个带表头的单链表中所有元素数据值无序，
试编写一个函数，删除表中介于给定的两个值之间的元素
**/
void RangeDelete(LinkList &L, int min, int max)
{
    LNode *pr = L, *p = L - next; //p是检测指针,pr是其前驱
    while (p != NULL)
    {
        if (p->data > min && p->data < max) //寻找被删除节点
        {
            pr - next = p->next;
            free(p);
            p = pr->next;
        }
        else//否则继续寻找被删除节点
        {
            pr = p;
            p = p->next;
        }
    }
}