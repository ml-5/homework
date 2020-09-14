#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MaxSize 10
typedef int ElemType;
typedef struct
{
    ElemType data[MaxSize];
    int length;
} SqList;
void CreatList(SqList **L, int n);
void InitList(SqList *L);
void DestroyList(SqList *L);
int ListEmpty(SqList *L);
int ListLength(SqList *L);
void DispList(SqList *L);
bool GetElem(SqList *L, int i, ElemType *e);
int LocateElem(SqList *L, ElemType e);
bool ListInsert(SqList *L, int i, ElemType e);
bool ListDelete(SqList *L, int i, ElemType *e);
int main()
{
    int e;
    SqList *L;
    CreatList(&L, 5);
    DispList(L);
    InitList(L);
    DispList(L);
    CreatList(&L, 6);
    DispList(L);
    printf("%d\n", ListLength(L));
    printf("%d %d\n", GetElem(L, 2, &e), e);
    printf("%d\n", LocateElem(L, 1));
    ListInsert(L, 7, 6);
    DispList(L);
    ListDelete(L, 7, &e);
    printf("删除的元素:%d\n", e);
    DispList(L);
    DestroyList(L);
}
void CreatList(SqList **L, int n)
{
    int i;
    *L=(SqList *)malloc(sizeof(SqList));
    for (i = 0; i < n; i++)
        (*L)->data[i] = i;
    (*L)->length = n;
}
void InitList(SqList *L)
{
    L->length = 0;
}
void DestroyList(SqList *L)
{
    free(L);
    printf("yes");
}
int ListEmpty(SqList *L)
{
    if(L->length==0)
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