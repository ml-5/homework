/**试编写算法在带头结点的单链表中删除一个最小节点的高效算法**/
LinkList Delete_Min(Linklist *L)
{
    //本算法删除其最小节点
    LNode *pre = L, *p = pre->next; //p为工作的指针，pre指向其前驱
    LNode *minpre = pre, *min = p;  //保存最小节点及其前驱
    while (p != NULL)
    {
        if (p - data < min->data) //找到最小的节点更改
        {
            min = p;
            minpre = pre;
        }
        pre = p; //继续扫描下一个节点
        p = p->next;
    }
    minpre->next = min->next; //删除最小节点
    free(min);
    return L;
}