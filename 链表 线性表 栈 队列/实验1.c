#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MaxSize 20
typedef int ElemType;
typedef struct
{
    ElemType data[MaxSize];
    int length;
} SqList;
void CreatList(SqList **L, int n);                  //创建
void InitList(SqList *L);                           //初始化
void DestroyList(SqList *L);                        //销毁
int ListEmpty(SqList *L);                           //判断是否空表
int ListLength(SqList *L);                          //求长度
void DispList(SqList *L);                           //打印
bool GetElem(SqList *L, int i, ElemType *e);        //返回第i个位置的元素
int LocateElem(SqList *L, ElemType e);              //判断e值的元素位置
bool ListInsert(SqList *L, int i, ElemType e);      //插入元素
bool ListDelete(SqList *L, int i, ElemType *e);     //删除元素
void (SqList *L1, SqList *L2);                 //LAuLB
void UnionList(SqList *LA, SqList *LB, SqList *LC); //二路归并
int main()
{
    int e;
    SqList *LA, *LB, *LC = (SqList *)malloc(sizeof(SqList));
    CreatList(&LA, 12); //建立LA表
    GetElem(LA, LocateElem(LA, 5), &e);
    printf("第5个是:%d\n", e);
    printf("5在表中的位置i\n", LocateElem(LA, 5));
    printf("遍历LA\n");
    DispList(LA);
    CreatList(&LB, 5); //建立LB表
    printf("遍历LB\n");
    DispList(LB);          //遍历LB
    ListDelete(LB, 2, &e); //删除LB的第二个元素
    printf("删除LB的第二个元素是:%d\n", e);
    printf("遍历LB\n");
    DispList(LB);          //遍历LB
    UnionList(LA, LB, LC); //二路归并
    printf("遍历LC\n");
    DispList(LC);    //遍历LC
    DestroyList(LA); //销毁LA,LB,LC
    DestroyList(LB);
    DestroyList(LC);
}
void CreatList(SqList **L, int n)
{
    int i;
    *L = (SqList *)malloc(sizeof(SqList));
    for (i = 0; i < n; i++)
        scanf("%d", &(*L)->data[i]);
    (*L)->length = n;
}
void InitList(SqList *L)
{
    L->length = 0;
}
void DestroyList(SqList *L)
{
    free(L);
}
int ListEmpty(SqList *L)
{
    if (L->length == 0)
        return 1;
    else
        return 0;
    //return (L->length == 0);
}
int ListLength(SqList *L)
{
    return (L->length);
}
void DispList(SqList *L)
{
    int i;
    if (ListEmpty(L))
        return;
    for (i = 0; i < L->length; i++)
        printf("%d", L->data[i]);
    printf("\n");
}
bool GetElem(SqList *L, int i, ElemType *e)
{
    if (i < 1 || i > L->length)
        return false;
    *e = L->data[i - 1];
    return true;
}
int LocateElem(SqList *L, ElemType e)
{
    int i = 0;
    while (i < L->length && L->data[i] != e)
        i++;
    if (i >= L->length)
        return 0;
    else
        return i + 1;
}
bool ListInsert(SqList *L, int i, ElemType e)
{
    int j;
    if (i < 1 || i > L->length + 1)
        return false;
    for (j = L->length; j >= i - 1; j--)
        L->data[j + 1] = L->data[j];
    L->data[i - 1] = e;
    L->length++;
    return true;
}
bool ListDelete(SqList *L, int i, ElemType *e)
{
    int j;
    if (i < 1 || i > L->length)
    {
        return false;
    }
    *e = L->data[i - 1];
    for (j = i - 1; j < L->length - 1; j++)
    {
        L->data[j] = L->data[j + 1];
    }
    L->length--;
}

void UnionList(SqList *LA, SqList *LB, SqList *LC)
{
    int i = 0, j = 0, k = 0; //i、j分别为LA、LB的下标,k为LC中元素个数
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