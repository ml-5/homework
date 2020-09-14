
/**
 例如，LA=（1，3，5），LB＝（2，4，6，8）
采用顺序表存放有序表时，二路归并算法如下：
**/
void UnionList(SqList *LA, SqList *LB, SqList *&LC)
{
    int i = 0, j = 0, k = 0;               //i、j分别为LA、LB的下标,k为LC中元素个数
    LC = (SqList *)malloc(sizeof(SqList)); //建立有序顺序表LC
    while (i < LA->length && j < LB->length)
    {
        if (LA->data[i] < LB->data[j])
        {
            LC->data[k] = LA->data[i];
            i++;
            k++;
        }
        else //LA->data[i]>LB->data[j]
        {
            LC->data[k] = LB->data[j];
            j++;
            k++;
        }
    }
    // 两个有序表均没有遍历完
    while (i < LA->length) //LA尚未扫描完,将其余元素插入LC中
    {
        LC->data[k] = LA->data[i];
        i++;
        k++;
    }
    while (j < LB->length) //LB尚未扫描完,将其余元素插入LC中
    {
        LC->data[k] = LB->data[j];
        j++;
        k++;
    }
    LC->length = k;
}
//本算法的时间复杂度为O(m+n)，空间复杂度为O(m+n)
采用单链表存放有序表时，二路归并算法如下：
void UnionList1(LinkList *LA, LinkList *LB, LinkList *&LC)
{
    LinkList *pa = LA->next, *pb = LB->next, *r, *s;
    LC = (LinkList *)malloc(sizeof(LinkList)); //创建LC的头节点
    r = LC;                                    //r始终指向LC的尾节点
    while (pa != NULL && pb != NULL)
    {
        if (pa->data < pb->data)
        {
            s = (LinkList *)malloc(sizeof(LinkList)); //复制节点
            s->data = pa->data;
            r->next = s;
            r = s; //采用尾插法将*s插入到LC中
            pa = pa->next;
        }
        else
        {
            s = (LinkList *)malloc(sizeof(LinkList)); //复制节点
            s->data = pb->data;
            r->next = s;
            r = s; //采用尾插法将*s插入到LC中
            pb = pb->next;
        }
    }
    while (pa != NULL)
    {
        s = (LinkList *)malloc(sizeof(LinkList)); //复制节点
        s->data = pa->data;
        r->next = s;
        r = s; //采用尾插法将*s插入到LC中
        pa = pa->next;
    }
    while (pb != NULL)
    {
        s = (LinkList *)malloc(sizeof(LinkList)); //复制节点
        s->data = pb->data;
        r->next = s;
        r = s; //采用尾插法将*s插入到LC中
        pb = pb->next;
    }
    r->next = NULL //尾节点的next域置空
} //本算法的时间复杂度为O(m+n)，空间复杂度为O(m+n)。