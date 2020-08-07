/**
假设有一个带头节点的单链表L={a1，b1，a2， b2，…，an，bn}。设计一个算法将其拆分成两个带头节点的单链表
L1和L2：L1={a1，a2，…，an}，L2={bn，bn-1，…，b1}
要求L1使用L的头节点
**/
/**
思路:：利用原单链表L中的所有节点通过改变指针域重组成单链
表L1和L2。
由于L1中节点的相对顺序与L中的相同，所以采用尾插法建立单
链表L1；
由于L2中节点的相对顺序与L中的相反，所以采用头插法建立单
链表L2。
**/
void split(LinkList **L, LinkList **L1, LinkList **L2)
{

    LinkList *p = L->next， * q, *r;           //p指向第一个数据节点
    L1 = L;                                    //L1利用原来的L的头结点
    r1 = L1;                                   //r1指向L1的尾结点
    L2 = (LinkList *)malloc(sizeof(LinkList)); //创建L2的头结点
    L2->next = NULL;                           //将L2的指针域置为NULL
    while (p != NULL)
    {
        r1->next = p; //采用尾插法将p插入L1中
        r1 = p;
        p = p->next; //p移动下一个节点 bi
        q = p->next; //用q保存p的后继节点
        p->next = L2->next;
        L2->next = p;
        p = q; //p重新指向ai+1的节点
    }
    r1->next = NULL; //尾节点的next置为空
}
/**
将一个单链表拆分为3个单链表
假设有一个带头节点的单链表L，每个节点值由单个数字、小写字母和大写字母构成。设计一个算法将其拆分成3个带头节点的单链表L1、L2和L3，L1包含L中的所有数字节点，L2包含L中的所有小写字母节点，L3包含L中的所有大写字母节点。
**/
void split(LinkList *&L, LinkList *&L1, LinkList *&L2, LinkList *&L3)
{
    LinkList *p = L->next, *r1, *r2， * r3;
    L1 = (LinkList *)malloc(sizeof(LinkList));
    L2 = (LinkList *)malloc(sizeof(LinkList));
    L3 = (LinkList *)malloc(sizeof(LinkList));
    r1 = L1;
    r2 = L2;
    r3 = L3;
    while (p != NULL)
    {
        if (p->str >= 'a' && p->str <= 'z')
        {
            r2->next = p;
            r2 = p;
        }
        else if (p->str >= 'A' && p->str <= 'Z')
        {
            r3->next = p;
            r3 = p;
        }
        else
        {
            r1->next = p;
            r1 = p;
        }
        p = p->next;
    }
    r1->next = NULL;
    r2->next = NULL;
    r3->next = NULL;
}
