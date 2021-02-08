/**
有两个循环单链表,链表的头指针分别为h1和h2，编写用函数将链表好
链接到链表h1之后，要求链接后的单链表仍保持循环单链表的形式
 **/
//算法思想:先找到两个链表的尾巴指针，将第一个链表的尾指针与第二个单链表
//头结点链接起来
LinkList Link(LinkList L1, LinkList L2)
{
    //将循环链表L2接到L1后面之后，使之保持循环单链表的形式
    LNode *p, *q;
    p = L1;
    while (p->next != L1)
    {
        p = p->next;
    }
    q = L2;
    while (q->next != L2)
    {
        q = q->next;
    }

    p->next = L2;
    q->next = L1;
    return L1;
}