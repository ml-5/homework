/**
两个整数序列A=a1,a2,a3,...,am和B=b1,b2,b3存入两个单链表中
，设计一个算法，判断序列B是否是序列A的连续子序列

算法思想:因为两个整数序列已存入两个链表中，操作从两个链表的第一个节点开始，若对应的
数据相等,则指针后移;若对应的数据不相等，则A链表从上次开始比较的节点后继开始，B仍从第一个
节点开始比较，直到B链表到尾表示匹配成功。A链表到尾而B链表没有到尾巴表示失败
。操作中应该记住A链表每次开始的节点，以便下趟匹配好从其后继开始
**/
int Pattern(LinkList A, LinkList B)//BF算法思路
{
    //A和B分别是数据域为正数的单链表，本算法判断A是否是B的子序列
    LNode *p = A, LNode *pre = p;
    LNode *q = B;
    while (p && q)
    {
        if (p->data == q->data)
        {
            p = p->next;
            q = q->next;
        }
        else
        {
            pre = pre->next;
            p = pre; //A链表从新开始比较节点
            q = B;   //B从头开始
        }
    }
    if (q == NULL)
        return 1;
    else
        return 0;
}