/*动态数组的搭建*/
//动态增长，策略将存放内存放到堆上  capacity
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct DYNAMICARRY
{
    int *PAddr;   //存放数据的地址
    int size;     //当前元素
    int capacity; //容量
} Dynamic_Array;
//初始化

Dynamic_Array *Init_Arry();
int At_Array(Dynamic_Array *arr, int pos);
int Size_Array(Dynamic_Array *arr);
int Capacity_Array(Dynamic_Array *arr);
void Clear_Array(Dynamic_Array *arr);
void FreeSpace_Array(Dynamic_Array *arr);
void Print_Array(Dynamic_Array *arr);
int Find_Array(Dynamic_Array *arr, int value);
void RemoveByvalue_Array(Dynamic_Array *arr, int value);
void PushBack_Array(Dynamic_Array *arr, int value);
void RemoveByPos_Array(Dynamic_Array *arr, int pos);
Dynamic_Array *Init_Arry();
int main()
{
    //初始化动态数组
    Dynamic_Array *myArray = Init_Arry();
    //打印容量
    printf("数组的容量:%d\n", Capacity_Array(myArray));
    printf("数组的大小:%d\n", Size_Array(myArray));
    //插入元素
    for (int i = 0; i < 30; i++)
    {
        PushBack_Array(myArray, i);
    }
    printf("数组的容量:%d\n", Capacity_Array(myArray));
    printf("数组的大小:%d\n", Size_Array(myArray));
    //打印
    Print_Array(myArray);
    //删除
    RemoveByPos_Array(myArray, 0);
    RemoveByvalue_Array(myArray, 27);
    //打印
    Print_Array(myArray);
    //查找
    int pos = Find_Array(myArray, 5);
    printf("位置5查到:%d %d\n ", pos, At_Array(myArray, pos));
    //销毁
    FreeSpace_Array(myArray);
}
Dynamic_Array *Init_Arry()
{
    Dynamic_Array *myArray = (Dynamic_Array *)malloc(sizeof(Dynamic_Array));
    myArray->size = 0;
    myArray->capacity = 20;
    myArray->PAddr = (int *)malloc(sizeof(int) * myArray->capacity);
    return myArray;
}
//插入
void PushBack_Array(Dynamic_Array *arr, int value)
{
    if (arr == NULL)
        return;
    //判断空间是否足够
    if (arr->size == arr->capacity)
    {
        //申请一块更大的内存空间 新空间默认是旧空间2倍
        int *newSpace = (int *)malloc(sizeof(int) * arr->capacity * 2);
        //第二部拷贝数据到新空间
        memcpy(newSpace, arr->PAddr, arr->capacity * sizeof(int));
        //释放旧空间的内存
        free(arr->PAddr);
        //更新容量
        arr->capacity = arr->capacity * 2;
        arr->PAddr = newSpace;
    }
    //插入新元素
    arr->PAddr[arr->size] = value;
    arr->size++;
}
//根据位置删除
void RemoveByPos_Array(Dynamic_Array *arr, int pos)
{
    if (arr == NULL)
        return;
    //判断位置是否有效
    if (pos < 0 || pos >= arr->size)
        return;
    //删除元素
    for (int i = pos; i < arr->size - 1; i++)
        arr->PAddr[i] = arr->PAddr[i + 1];
    arr->size--;
}
//根据值删除
void RemoveByvalue_Array(Dynamic_Array *arr, int value)
{
    if (arr == NULL)
        return;
    //找到值的位置

    int pos = Find_Array(arr, value);

    RemoveByPos_Array(arr, pos);
}
//查找
int Find_Array(Dynamic_Array *arr, int value)
{
    if (arr == NULL)
        return -1;
    //查找
    //找到值的位置
    int pos = -1;
    for (int i = 0; i < arr->size; i++)
    {
        if (arr->PAddr[i] == value)
        {
            pos = i;
            break;
        }
    }
    return pos;
}
//打印
void Print_Array(Dynamic_Array *arr)
{
    if (arr == NULL)
        return;
    for (int i = 0; i < arr->size; i++)
        printf("%d ", arr->PAddr[i]);
    printf("\n");
}
//释放动态数组的内存
void FreeSpace_Array(Dynamic_Array *arr)
{
    if (arr == NULL)
        return;
    if (arr->PAddr != NULL)
        free(arr->PAddr);
    free(arr);
}
//清空数组
void Clear_Array(Dynamic_Array *arr)
{
    if (arr == NULL)
        return;
    //pAddr->空间
    arr->size = 0;
}
//获得动态数组容量
int Capacity_Array(Dynamic_Array *arr)
{
    if (arr == NULL)
        return -1;
    return arr->capacity;
}
//获得动态数组的当前元素的个数
int Size_Array(Dynamic_Array *arr)
{
    if (arr == NULL)
        return -1;
    return arr->size;
}
//根据位置获得某个元素
int At_Array(Dynamic_Array *arr, int pos)
{
    return arr->PAddr[pos];
}