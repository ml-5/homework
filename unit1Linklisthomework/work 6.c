/**有一个带头结点的单链表L，设计一个算法使其元素递增有序**/
void Sort(LinkList *L)
{  //本算法实现将单链表L的节点重排,使其递增有序
    LNode *p=L->next,*pre;
    LNode  *r=p->next;//r保持*p后继节点指针，以保证不断链
    p->next=NULL;//构造一个数据节点的有序表
    p=r;
    while(p!=NULL)
    {
        r=p->next;//保存*p的后继节点指针
        pre=L;
        while(pre->next!=NULL&&pre->next->data<p->data)
          pre=pre->next;
          p->next=pre->next;
          pre->next=p;
          p=r;
    }
}