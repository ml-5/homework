/**
将一个一个带头结点的单链表A分解为为两个带头结点的A和B，
使得A表中含有原表序号为奇数的元素,而B表含有原表中序号为偶数的元素,
而保持其相对顺序不变
**/
//思路设置一个循环变量，没访问一个节点序号自动加一，然后根据奇偶性节点插入
LinkList DisCrat_1(LinkList &A)
{
    //将表A中结点按照序号的奇偶性分解到表A和表B中
    i = 0;                                           //i记录表A中结点的序号
    LinkList *B = (LinkList *)malloc(sizeof(LNode)); //创建B的表头
    B->next = NULL;                                  //B表初始化
    LNode *ra = A, *rb = B;                          //采用尾插法创建A表和B表
    p = A->next;
    A->next = NULL;
    while (p != NULL)
    {
        i++;
        if (i % 2 == 0)
        {
            rb->next = p;
            rb = p;
        }
        else
        {
            ra->next = p;
            ra = p;
        }
        p = p->next;
    }
    ra->next = NULL;
    rb->next = NULL;
    return B;
}