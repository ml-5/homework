/**
两个单链表归并为一个按照元素递减的次序排列
**/
//思路：采用头插法的思路加二路归并
void MergeList(LinkList &LA, LinkList &LB)
{
    //合并两个有序单链表带头结点，并使用合并后的链表递减排列
    LNode *r, *pa = La->next, *pb = L->next; //分别是A和B的工作指针
    LA->next = NULL;
    while (pa && pb)
    {
        if (pa->data <= pb->data)
        {
            r = pa->next; //r暂存pa的后继节点指针
            pa->next = LA->next;
            LA->next = pa;
            pa = r;
        }
        else
        {
            r = pb->next;
            pb->next = La->next;
            La->next = p;
            pb = r;
        }
    }
    if (pa)
        pb = pa;
    while (pb)
    {
        r = pb->next;
        pb->next = LA->next;
        LA->next = pb;
        pb = r;
    }
    free(LB);
}