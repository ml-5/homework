/**
设计一个算法用于判断带头结点的的循环双链表是否对称
**/
//算法思想:让p从左到有扫描，直到它们指向同一个节点（p==q),当循环双链表中的节点
//个数为奇数时或相邻为止，若它们所指的节点值相同，则继续进行下去，否则返回0
int Symmetry(DlinkList L)
{
    DNode *p = L->next, *q = L->prior; //两头工作指针
    while (p != q && q->next != p)
    {
        if (p->data == q->data)
        {
            p = p->next;
            q = q->prior;
        }
        else
        {
            return 0;
        }
    }
    return 1;
}