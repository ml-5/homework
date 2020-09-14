
#include <stdio.h>
#define MAXSIZE 10
typedef int ELemType;
typedef struct //线性表中共有length个元素，是data[0]-data[length-1]
{
    int data[MAXSIZE];
    int length;
} SqList;
int inList(SqList *L);                              /**初始化操作，建立一个空的线性表**/
int printList(SqList L);                            /**打印线性表中的每一个元素**/
int getlength(SqList L);                            /**返回线性表的元素个数**/
int creatList(SqList *L, int length);               /**创建一个线性表长度为length的表**/
int insertList(SqList *L, int pos, ELemType elem);  /**在线性表的第pos个位置插入一个新的1元素elem**/
int getELem(SqList L, int pos, ELemType *e);        /**将线性表中第pos个位置元素返回，保存在*e中**/
int locateELem(SqList L, int pos, ELemType e);      /**在线性表中查找与给定元素e相等,如果有相等则返回1，否则返回0**/
int deleteList(SqList *L, int pos, ELemType *elem); /**从线性表中删除pos位置的元素，并将其存放在elem中**/
int clearList(SqList L, SqList *pl);                /**删除线性表**/
int inList(SqList *L)
{
    L->length = 0;
    return 1;
}
int printList(SqList L)
{
    if (L.length == 0)
    {
        printf("线性表为空\n");
        return 0;
    }
    int i;
    for (i = 0; i < L.length; i++)
        printf("data[%d]=%d\n", i, L.data[i]);
    printf("\n");
    return 1;
}
int getlength(SqList L)
{
    return L.length;
}
int creatList(SqList *L, int length)
{
    srand(time(0));
    int i;
    for (i = 0; i < length; i++)
    {
        L->data[i] = rand() % 100;
        L->length++;
    }
    return 1;
}
int insertList(SqList *L, int pos, ELemType elem)
{
    int i;
    if (pos < 1 || pos > L->length)
    {
        printf("插入的位置有误，无法插入数据\n");
        return 0;
    }
    for (i = L->length - 1; i > pos - 1; i--)
    {
        L->data[i + 1] = L->data[i];
    }
    L->data[pos - 1] = elem;
    L->length++;
    return 1;
}
int getELem(SqList L, int pos, ELemType *e)
{
    if (pos < 1 || pos > L.length)
    {
        printf("查找位置有错误，无法获取指定位置的数据\n");
        *e = 99999999;
        return 0;
    }
    *e = L.data[pos - 1];
    return 1;
}

int locateELem(SqList L, ELemType e)
{
    int i;
    for (i = 0; i < L.length; i++)
    {
        if (L.data[i] == e)
        {
            printf("在pos[%d]位置处查找到了元素elem:%d\n", i + 1, e);
            return 1;
        }
    }
    return 0;
}
int deleteList(SqList *L, int pos, ELemType *elem)
{
    int i;
    if (pos < 1 || pos > L->length)
    {
        printf("删除的位置有误，无法从该位置删除数据\n");
        *elem = 999999;
        return 0;
    }
    *elem = L->data[pos - 1];
    for (i = pos; i <= L->length; i++)
    {
        L->data[i - 1] = L->data[i];
    }
    L->length--;
    return 1;
}

int clearList(SqList *pL)
{
    pL->length = 0;
    return 1;
}