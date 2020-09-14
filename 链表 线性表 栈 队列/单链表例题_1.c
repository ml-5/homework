/**
设计一个算法，删除一个单链表L中元素值最大的
节点（假设最大值节点是唯一的）
**/
//思路设计一对指针遍历查找
void Delmaxnode(LinkList **L)
{
    LinkList *p=L->nexr,*pre=L,*maxp=p,*maxpre=pre;
    while(p!=NULL)
    {
        if(maxp->data<p->data)/若找到一个更大的节点
        {
             maxp=p;//更改maxp
             maxpre=pre;//更改maxpre
        }
        pre=p;
        p=p->next;
    }
    maxpre->next=maxp->next;//删除maxp节点
    free(maxp);             //释放maxp节点
}
//算法的时间复杂度为O(n)