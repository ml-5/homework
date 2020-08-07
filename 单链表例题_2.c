/**
有一个带头节点的单链表L（至少有一个数据节
点），设计一个算法使其元素递增有序排列。
**/
//思路:将链表分割成两部分,循环遍历在比较插入
void sort(LinkList **L)
{
    LinkList *p,*pre,*q;
    p=L->next->next; //p指向L的第二个数据节点
    L->next->next=NULL;//构造只含有一个数据节点的有序表
    while(p!=NULL)
    {
        q=p->next;//保存p后面的节点指针
        pre=L;     //从有序表的开头进行比较,pre指向插入节点的前驱节点
        while(pre->next!=NULL&&pre->next->data<p->data)
        {
            pre=pre->next;//查找插入的前驱节点
        }
        p->next=pre->next;
        pre->next=p;
        p=q;     //扫描单链表余下的节点
    }
}
//该算法的复杂度为O(n2)