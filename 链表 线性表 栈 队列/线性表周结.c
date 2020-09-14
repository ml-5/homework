/**
知识点：
双链表  每个节点都有前后指针域 通常，存储密度低于单链表

循环链表  
单链表可以循环查找构成一个环  
双链表可以循环查找可以通过头节点快速找到尾节点删除尾节点、在尾节点前后插入一个节点的时间均为O(1)。
特点：已知某个节点的地址，删除它的时间为O(1)。在某个节点的前、后插入一个节点的时间为O(1)。

有序表
有序特性可以提高算法的效率

eg:假设一个有序表采用顺序表存储。设计一个高效算法删除重复的元素。
例如：L=(1，1，1，2，2，3) 
答案：
L=(1，2，3)
**/
void deldupnode1(SqList **L)
{
    int k = 1, i; //k记录保留的元素个数
    for (i = 1; i < L->length; i++)
        if (L->data[i] != L->data[i - 1])
        {
            L->data[k] = L->data[i];
            k++; //保留的元素增1
        }
    L->length = k; //顺序表L的长度等于k
}
/**
二路归并的思路提高效率
假设两个递增有序表采用单链表ha和hc存储（假设同一个单链表
中不存在重复的元素）。设计一个高效算法求它们的公共元素，
将结果存放在单链表hc中。
ha=(1，2，3)，hb=(2，3，4) 
hc=(2，3)
**/
//思路:二路归并加尾插法
void InterSect(LinkList *ha，LinkList *hb，LinkList *&hc)
{
    LinkList *pa = ha->next， *pb = pb->next， * s， * r;
    hc = (LinkNode *)malloc(sizeof(LinkNode));
    r = hc; //r指向尾节点
    while (pa != NULL && pb != NULL)
    {
        if (pa->data < pb->data)
            pa = pa->next;
        if (pa->data > pb->data)
            pb = pb->next;
        if (pa->data == pb->data) //相同元素
        {
            s = (LinkNode *)malloc(sizeof(LinkNode)); //复制节点
            s->data = pa->data;
            r->next = s;
            r = s;
            pa = pa->next;
            pb = pb->next;
        }
    }
    r->next = NULL;
}