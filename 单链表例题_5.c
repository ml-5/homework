/**
题目:
荷兰国旗问题：设有一个条块序列，每个条块为红
（0）、白（1）、兰（2）三种颜色中的一种。假设该序列
采用顺序表存储，设计一个时间复杂度为O(n)的算法，使得
这些条块按红、白、兰的顺序排好，即排成荷兰国旗图案
eg:1 0 2 1 0 0 1 2 2 1 0 2
   0 0 0 0 1 1 1 1 2 2 2 2
**/
/**
思路:
用p指针扫描节点，根据p->data值将该节点插
入到3个单链表L、L1和L2（L1和L2不带头节点的）中。
最后将它们链接起来。
**/
void move(LinkList **L)
{
    LinkList *L1, L2, *r, *r1, *r2, *p;
    L1 = NULL;
    L2 = NULL;
    p = L->next;
    r = L;
    while (p != NULL)
    {
        if (p->data == 0) //建立L带头结点的单链表
        {
            r->next = p;
            r = p;
        }
        else if //建立L1不带头结点的单链表
        {
            if (L1 == NULL)
            {
                L1 = p, r1 = p;
            }
            else
            {
                r1->next = p;
                r1 = p;
            }
        }
        else
        {
            if (L2 == NULL)
            {
                L2 = p;
                r2 = p;
            }
            else
            {
                r2->next = p;
                r2 = p;
            }
        }
        p = p->next;
        r->next = r1->next = r2->next = NULL;
        r->next = L1;  //L的尾节点和L1的首节点链接起来
        r1->next = L2; //L1的尾节点和L2的首节点链接起来
    }
}
