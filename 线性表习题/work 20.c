/**
已经知道有带有头结点的单链表,该节点的结构为 data link
假设该链表只给出了头指针list，在不改变链表的前提下，请设计一个尽可能高效的
算法查找链表中倒数的k个位置的节点，若查找成功输出改节点的值，并返回1，否则返回0


算法的基本思路是:
定义两个变量 p和q ,初始时均指向头结点的下一个节点(链表里的第一个节点),p
指针沿着链表移动,当p移动到第k个节点时，q指针开始与p指针同时移动;当p指针移动
到最后一个节点时,q指针指向倒数第k个节点

**/
int Search_k(LinkList list, int k)
{                                           //查找链表list倒数第k节点,并输出节点data的值
    LNode *p = list->link, *q = list->link; //p q指示第一个节点
    int count = 0;
    while (p != NULL)
    {
        if (count < k)
            count++;
        else
            q = q->link; //计数count<k移动q
        p = p->link;   //之后让p q一起移动
    }
    if(count<k)
    {
        return 0;
    }
    else
    {
        printf("%d",q->data);
        return 1;
    }

}
