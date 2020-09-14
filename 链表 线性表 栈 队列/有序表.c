/**
 * 1、什么是有序表
所谓有序表，是指这样的线性表，其中所有元素以递增或递 减方式有序排列。
有序表 属于 线性表
为了简单，假设有序表元素是以递增方式排列。
从中看到，有序表和线性表中元素之间的逻辑关系相同，其
区别是运算实现的不同。
既然有序表中元素逻辑关系与线性表的相同，有序表可以采
用与线性表相同的存储结构。
若以顺序表存储有序表，会发现基本运算算法中只有ListInsert()
算法与前面的顺序表对应的运算有所差异，其余都是相同的。有序顺
序表的ListInsert()算法如下：
**/
//线性表
void LinkInsert(SqList **L,int e)
{
    int i=0,j;
    while(i<L->length&&L->data[i]<e)
    i++;  //查找位置
    for(j=ListLength(L);j>i;i--)
    {
        L->data[j]=L->data[j-1];
    }
    L->data[i]=e;
    L->length++;           //有序表长度加1
}
//单链表
void ListInsert(LinkList **L,int e)
{
    LinkList *pre=L,*p;
    while (pre->next!=NULL&&pre->next->data<e)
    {
        pre=pre->next;//查找插入的前驱节点
    }
    p=(LinkList *)malloc(sizeof(LinkList));
    p->data=e;
    p->next=pre->next;//在pre节点后插入p节点
    pre->next=p;
}