/**
题目:有一个带头节点的双链表L，设计一个算法将其所
有元素逆置，即第1个元素变为最后一个元素，第2个元素变为倒数
第2个元素，…，最后一个元素变为第1个元素
**/
//思路:头插法
void Reverse(DLinkList **L)
{
    DLinkList *p=(*L)->next,*q;//p指向开始节点
    L->next=NULL;
    while(p!=NULL)//扫描L的数据节点
    {
        q=p->next; //用q保存其后继节点
        p->next=(*L)->next;//采用头插法p节点插入
        if((*L)->next!=NULL)
        (*L)->next->prior=p;
        (*L)->next=p;
        p->prior=L;
        p=q;   //让p重新指向后继节点
    }
}