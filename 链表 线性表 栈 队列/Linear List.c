/*
顺序储存线性表的基本操作
1.查找 2.插入 3.删除 4.顺序表合并用法 
*/
#include <stdio.h>
#define maxsize 10
typedef struct
{
    int elem[maxsize];
    int last;
} SeqList;
int GETData(SeqList L, int i) /*按序号查找*/
{
    printf("你查找的第%d个元素结果如下\n", i);
    printf("%d\n", L.elem[i]);
    return 1;
}
int Locate(SeqList L, int e) /*按照内容查找*/
{
    int i = 0;
    while (i < L.last && L.elem[i] != e)
        i++; /*顺序扫描表，直到找到值为e的元素，如果扫描到表尾表示没找到*/
    if (i < L.last)
        return i; /*若找到则返回下标*/
    else
        return -1; /*如果没有则返回空序号-1*/
}
int InsList(SeqList *L, int i, int e) /*插入运算的实现*/
{
    int k;
    if (i < 1 || i > L->last + 2) /*首先判断插入的位置合法不*/
    {
        printf("插入的位置i不合法");
        return 0;
    }
    if (L->last >= maxsize - 1)
    {
        printf("表已满无法插入");
        return 0;
    }
    for (k = L->last; k >= i - 1; k--) /*为插入元素而移动位置*/
        L->elem[k + 1] = L->elem[k];
    L->elem[i - 1] = e; /*第i个元素的下标为i-1;*/
    L->last++;
    return 1;
}
/*上述算法for循环执行的次数为n-i+1
若 i=1;需要移动全部的n个节点最坏(O(n));
若i=n+1(在表尾插入)，无需移动节点，直接插入即可；最好(O(n));
顺序表的插入算法平均需要移动一半的节点*/
int DelList(SeqList *L, int i, int *e) /*删除第i个元素，并用指针返回其值*/

{

    int k;
    if (i < 1 || i > L->last + 1)
    {
        printf("删除的位置不合法！");
        return 0;
    }
    *e = L->elem[i - 1];
    for (k = i; k <= L->last; k++)
        L->elem[k - 1] = L->elem[k]; /*将后面的元素依次前移*/
    L->last--;
    return 1;
}
/*删除算法分析上述for循环的执行次数为n-i
若i=1,需要移动全部n个节点(最坏O(n));
若i=n,无需移动节点，直接删除(最好O(n));
顺序表的删除算法平均需要移动一半的节点*/

/*算法思想 ：设表LC是一个空表，为使LC也是非递减有序排
列，可设两个指针i、j分别指向表LA和LB中的元素，若
LA.elem[i]>LB.elem[j]，则当前先将LB.elem[j]插入到表LC中
，若LA.elem[i]≤LB.elem[j] ，当前先将LA.elem[i]插入到表
LC中，如此进行下去，直到其中一个表被扫描完毕，然后再
将未扫描完的表中剩余的所有元素放到表LC中*/
void Merge(SeqList *LA, SeqList *LB, SeqList *LC)
{
    int i, j, k;
    i = j = k = 0;
    while (i < LA->last && j <= LB->last)
    {
        if (LA->elem[i] <= LB->elem[j])
        {
            LC->elem[k] = LA->elem[i];
            i++;
            k++;
        }
        else
        {
            LC->elem[k] = LB->elem[j];
            j++;
            k++;
        }
    }
    while (i <= LA->last) /*若LA长则将表LA余下的元素赋给LC*/
    {
        LC->elem[k] = LA->elem[i];
        i++;
        k++;
    }
    while (j <= LB->last) /*若LB长泽将表LB余下的元素赋给LC*/
    {
        LC->elem[k] = LB->elem[j];
        j++;
        k++;
    }
    LC->last = LA->last + LB->last;
}
/*
• 优点
–无需为表示结点间的逻辑关系而增加额外的存储空间； –可方便地随机存取表中的任一元素。
• 缺点
–插入或删除运算不方便，除表尾的位置外，在表的其它位置上进行
插入或删除操作都必须移动大量的结点，效率较低； –由于顺序表要求占用连续的存储空间，存储分配只能预先进行静态
分配。因此当表长变化较大时，难以确定合适的存储规模。
*/
