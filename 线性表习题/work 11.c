/**
设计一个算法 将c={a1，b1，a2，b2...}拆分为两个线性表
使得A表是a的元素，B表是b的元素
**/
LinkList DisCreat_2(LinkList &A)
{
    LinkList B = (LinkList)malloc(sizeof(LNode)); //创建B的表头
    B->next = NULL;          //B表的初始化
    LNode *p = A->next, *q; 
    LNode *ra = A;          //尾插法建立
    while (p)
    {
        ra->next = p;
        ra = p;
        q = p->next;
        p->next = B->next;
        B->next = p;
        p = q;
    }
    ra->next = NULL;
    return B;
}