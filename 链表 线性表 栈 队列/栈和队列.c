/*
栈
栈是一种只能在一端进行插入或删除操作的线性表。
栈只能选取同一个端点进行插入和删除操作
栈的几个概念
允许进行插入、删除操作的一端称为栈顶。 
表的另一端称为栈底。 
当栈中没有数据元素时，称为空栈。 
栈的插入操作通常称为进栈或入栈。 
栈的删除操作通常称为退栈或出栈。
栈的主要特点是“后进先出”，即后进栈的元素先出栈。栈也称为后进先出表。
eg：设一个栈的输入序列为a,b,c,d，则借助一个栈所得
到的输出序列不可能是 
A. c,d,b,a  B.d,c,b,a  C.a,c,d,b  D. d,a,b,c
1.下一步不可能出栈a
【例3-2】一个栈的入栈序列为1,2,3,…,n ，其出栈序列是p1,p2,p3, … , pn。若p1=3，则p2可能取值的个数是 。
A.n-3 B.n-2 C.n-1 D. 无法确定
约定top总是指向栈顶元素，初始值为-1 
当top=MaxSize-1时不能再进栈－栈满
进栈时top增1，出栈时top减1
栈空条件：top=-1
栈满条件：top=MaxSize-1
进栈e操作：top++; 将e放在top处
退栈操作：从top处取出元素e; top--;
*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MaxSize 10
#define ElemType int
typedef struct
{
    ElemType data[MaxSize];
    int top; //栈顶指针
} SqStack;
InitStack(SqStack **s) //初始化栈
{
    (*s) = (SqStack *)malloc(sizeof(SqStack));
    (*s)->top = -1;
}
void DestroyStack(SqStack *s) //销毁栈
{
    free(s);
}
bool StackEmpty(SqStack *s) //判断栈是否为空
{
    return (s->top == -1);
}
bool Push(SqStack *s, int e) //进栈
{
    if (s->top == MaxSize - 1) //栈满的情况，即栈上溢出
        return false;
    s->top++;            //栈顶指针加1
    s->data[s->top] = e; //元素e放在栈顶指针处
    return true;
}
bool Pop(SqStack *s, int e) //出栈
{
    if (s->top == -1)
        return false;
    e = s->data[s->top]; //取栈定指针元素
    s->top--;
    return true;
}
bool GetTop(SqStack *s, int *e) //取栈顶元素
{
    if (s->top == -1) //栈为空的情况，栈下溢出
        return false;
    *e = s->data[s->top]; // 取栈顶指针元素的元素
    return true;
}
