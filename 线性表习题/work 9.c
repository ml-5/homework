/**
给定一个带头节点的单链表,设head为头指针节点结构为(data,next),
data为整型元素,next为指针,试写出算法:
按照递增次序输出单链表中各节点的数据元素,并释放节点所占的储存空间

算法思想：对链表进行遍历,在链表中查找出整个链表的最小值，输出并释放节点所占空间，在次查找最小元素
输出并释放空间，直至链表为空，最后释放头结点所占储存空间
**/
void Min_Delete(LinkList &head)
{                              //head 是带头结点的单链表的头指针
    while (head->next != NULL) //循环到仅剩头结点
    {
        pre = head;    //pre为元素最小节点的前驱的指针
        p = pre->next; //p为工作指针
        while (p->next != NULL)
        {
            if (p->next->data < pre->next->data)
                pre = p; //记住当前最小节点的前驱
            p = p->next;
        }
        print(pre->next->data); //输出元素的最小值结点数据
        u = pre->next;
        pre->next = u->next;
        free(u);
        free(head);
    }
}
