/*语言自带快排函数
qsort(*arr, n, sizeof(arr[0]), cmp);
第一个参数是排序数组开始的地址； 
第二个参数是排序数组元素的个数； 
第三个参数是每个数组元素的大小； 
第四个是函数指针，用于指定从小到大排序还是从大到小排序
eg：
cmp函数指针通常是固定的，写法如下：
int cmp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b; //由小到大排序
    //return *(int *)b - *(int *)a; 由大到小排序
}*/
#include <stdio.h>
int a[101], n; //定义全局变量
void quickesort(int left, int right)
{
    int i, j, t, temp;
    if (left > right)
        return;
    temp = a[left]; //temp存放的是基准数
    i = left;
    j = right;
    while (i != j)
    {
        //顺序很重要，要先从右往左找
        while (a[j] >= temp && i < j)
            j--;
        //在从左往右找
        while (a[i] <= temp && i < j)
            i++;
        //交换两个数在数组中的位置
        if (i < j)
        {
            t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }
    //最终将基准数归位
    a[left] = a[i];
    a[i] = temp;
    quickesort(left, i - 1);  //继续处理左边的这是一个递归过程
    quickesort(i + 1, right); //继续处理右边，递归
}
int main()
{
    int i, j, t;
    //读入数据
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    quickesort(1, n); //快速排序的调用
    for (i = 1; i <= n; i++)
        printf("%d ", a[i]);
    return 0;
}