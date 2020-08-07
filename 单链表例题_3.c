/**
以建表算法为基础的算法设计
单链表有尾插法和头插法两种建表算法。
题目:
假设有一个带头节点的单链表L={a1,a2,…,an}。
设 计一个算法将所有节点逆置，即：L={an，an-1，…，a1}
**/
//思路采用头插法建表
void Reverse(LinkList **L)
{
    LinkList *p=L->next，*q;
    L->next=NULL;
    while(p!=NULL)
    {
        q=p->next;
        p->next=L->next;
        L->next=p;
        p=q;
    }
}