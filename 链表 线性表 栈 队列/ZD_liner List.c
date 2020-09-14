#include <stdio.h>
#include <Windows.h>
#include <stdbool.h>
#define MAXSIZE 10
#define int ElementType
typedef int Position;
typedef struct LNode* List;
struct LNode
{
    ElementType Data[MAXSIZE];
    Position Last;
};

/* 初始化 */
List MakeEmpty()
{
    List L;

    L = (List)malloc(sizeof(struct LNode));
    L->Last = -1;

    return L;
}

/* 查找 */
#define ERROR -1

Position Find(List L, ElementType X)
{
    Position i = 0;

    while (i <= L->Last && L->Data[i] != X)
        i++;
    if (i > L->Last)
        return ERROR; /* 如果没找到，返回错误信息 */
    else
        return i; /* 找到后返回的是存储位置 */
}

/* 插入 */
/*注意:在插入位置参数P上与课程视频有所不同，课程视频中i是序列位序（从1开始），这里P是存储下标位置（从0开始），两者差1*/
bool Insert(List L, ElementType X, Position P)
{ /* 在L的指定位置P前插入一个新元素X */
    Position i;

    if (L->Last == MAXSIZE - 1)
    {
        /* 表空间已满，不能插入 */
        printf("表满");
        return false;
    }
    if (P < 0 || P > L->Last + 1)
    { /* 检查插入位置的合法性 */
        printf("位置不合法");
        return false;
    }
    for (i = L->Last; i >= P; i--)
        L->Data[i + 1] = L->Data[i]; /* 将位置P及以后的元素顺序向后移动 */
    L->Data[P] = X;                  /* 新元素插入 */
    L->Last++;                       /* Last仍指向最后元素 */
    return true;
}

/* 删除 */
/*注意:在删除位置参数P上与课程视频有所不同，课程视频中i是序列位序（从1开始），这里P是存储下标位置（从0开始），两者差1*/
bool Delete(List L, Position P)
{ /* 从L中删除指定位置P的元素 */
    Position i;

    if (P < 0 || P > L->Last)
    { /* 检查空表及删除位置的合法性 */
        printf("位置%d不存在元素", P);
        return false;
    }
    for (i = P + 1; i <= L->Last; i++)
        L->Data[i - 1] = L->Data[i]; /* 将位置P+1及以后的元素顺序向前移动 */
    L->Last--;                       /* Last仍指向最后元素 */
    return true;
}

/* 链表*/
typedef struct LNode *PtrToLNode;
struct LNode
{
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

/* 查找 */
#define ERROR NULL

Position Find(List L, ElementType X)
{
    Position p = L; /* p指向L的第1个结点 */

    while (p && p->Data != X)
        p = p->Next;

    /* 下列语句可以用 return p; 替换 */
    if (p)
        return p;
    else
        return ERROR;
}

/* 带头结点的插入 */
/*注意:在插入位置参数P上与课程视频有所不同，课程视频中i是序列位序（从1开始），这里P是链表结点指针，在P之前插入新结点 */
bool Insert(List L, ElementType X, Position P)
{ /* 这里默认L有头结点 */
    Position tmp, pre;

    /* 查找P的前一个结点 */
    for (pre = L; pre && pre->Next != P; pre = pre->Next)
        ;
    if (pre == NULL)
    { /* P所指的结点不在L中 */
        printf("插入位置参数错误\n");
        return false;
    }
    else
    { /* 找到了P的前一个结点pre */
        /* 在P前插入新结点 */
        tmp = (Position)malloc(sizeof(struct LNode)); /* 申请、填装结点 */
        tmp->Data = X;
        tmp->Next = P;
        pre->Next = tmp;
        return true;
    }
}

/* 带头结点的删除 */
/*注意:在删除位置参数P上与课程视频有所不同，课程视频中i是序列位序（从1开始），这里P是拟删除结点指针 */
bool Delete(List L, Position P)
{ /* 这里默认L有头结点 */
    Position tmp, pre;

    /* 查找P的前一个结点 */
    for (pre = L; pre && pre->Next != P; pre = pre->Next)
        ;
    if (pre == NULL || P == NULL)
    { /* P所指的结点不在L中 */
        printf("删除位置参数错误\n");
        return false;
    }
    else
    { /* 找到了P的前一个结点pre */
        /* 将P位置的结点删除 */
        pre->Next = P->Next;
        free(P);
        return true;
    }
}