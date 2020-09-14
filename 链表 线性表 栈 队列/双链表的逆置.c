/**
eg:有一个带头结点的双链表 L, 设计一个算法将其所有元素逆置，即第 个元
素变为最后 个元素，第 1个元素变为倒数第1个元素 …… 最后一个元素变为第1个元素
**/
void reverse(DLinkNode **L)
{
    DLinkNode *p = L->next, *q; //p指向首结点
    L->next = NULL;             //构造只有头结点的双链表L
    while (p != NULL)           //扫描L的所有数据节点
    {
        q = p->next;         //会修改p节点的next的域,q临时保存其后继节点
        p->next = L->next;   //采用头插法将p结点插入到双链表
        if (L->next != NULL) //若L中存在数据节点
            L->next->prior = p;
        L->next = p; //将新节点作为首结点
        p->prior = L;
        p = q; //让p重新指向后向节点
    }
}