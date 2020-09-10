/**线性表(a1,a2.....an)中元素递增有序且按照顺序存储，设计一算法用最短时间完成数值为x的元素下标*/
//算法：折半查找
void SearchExchangeInsert(int A[], int x)
{
    int low = 0, high = n - 1, mid; //low表示下届 high指向顺序表上限
    while (low <= high)
    {
        mid = (low + high) / 2; //找出中间位置
        if (A[mid] == x)
            break; //找到x,退出while循环
        else if (A[mid] < x)
            low = mid + 1; //到中点的右半部去查
        else
            high = mid - 1; //到中点mid的左半部去查
    }
    if (A[mid] == x && mid != n - 1) //若最后一个元素与x1相等，则不用交换
    {
        t = A[mid];
        A[mid] = A[mid + 1];
        A[mid + 1] = t;
    }
    if (low > high)                    //查找失败，插入元素x
        for (i = n - 1; i > high; i--) //后移元素
            A[i + 1] = A[i];
    A[i + 1] = x; //插入元素
}