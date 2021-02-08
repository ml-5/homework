/**
已知两个单链表带头结点，其中的元素递增排列编制函数,求A与B的交集
,并存放于A链表中

算法思路:采用归并的思想，设置两个工作指针pa和pb，对于两个单链表进行归并扫描
，只有同时出现在两个集合中的元素才保留一个，其他的节点全部是释放。当一个链表
遍历完毕后，释放另一个表中剩下的全部节点
**/
LinkList Union(LinkList &LA, LinkList &LB)
{
    pa = LA->next;
    pb = LB->next;
    pc = LA; //结果表中当前合并节点的前驱指针
    while (pa && pb)
    {
        if (pa->data == pb->data)
        {
            //交集并入到结果表中
            pc->next = pa;
            pc = pa;
            pa = pa->next;
            u = pb; //B节点释放
            pb->pb->next;
            free(u);
        }
        else if (pa->data < pb->data)
        {
            //若A中当前的节点小于B中当前的节点值

            u = pa;
            pa = pa->next; //指针后移
            free(u);       //释放A中的当前节点
        }
        else
        {
            u = pb;
            pb = pb->next;
            free(u);
        }
    }
    while (pa) //B表遍历完A未完
    {
        u = pa;
        pa = pa->next;
        free(u);
    }
    while (pb)
    {
        u = pb;
        pb = pb->next;
        free(u);
    }
    pc->next = NULL;
    free(LB);
    return LA;
}