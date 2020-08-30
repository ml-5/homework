/**
 数组排序任务可以如下完成：
1）设k=a[0], 将k挪到适当位置，使得比k小的元素都
在k左边,比k大的元素都在k右边，和k相等的，不关心
在k左右出现均可 （O（n)时间完成）
2) 把k左边的部分快速排序
3) 把k右边的部分快速排序
**/
#include <iostream>
using namesapce std;
void swap(int &a, int &b) //交换变量a,b
{
    int tmp = a;
    a = b;
    b = tmp;
}
void QuickSort(int a[], int s, int e)
{
    if (s >= e)
        return;
    int k = a[s];
    while (i != j)
    {
        while (j > i && a[j] >= k)
            --j;
        swap(a[i], a[j]);
        while (i < j && a[i] <= k)
            ++i;
        swap(a[i], a[j]);
    } //处理完后a[i]=k;
    QuickSort(a, s, i - 1);
    QuickSort(a, i + 1, e);
}
int a[] = {93, 27, 30, 2, 8, 12, 2, 8, 30, 89};
int main()
{
    int size = sizeof(a) / sizeof(int);
    QuickSort(a, 0, size - 1);
    for (int i = 0; i < size; ++i)
        cout << a[i] << ",";
    cout << endl;
    return 0;
}
//再写一遍
int AdjustArray(int s[], int l, int r) //返回后调整位置
{
    int i = l, j = r;
    int x = s[l]; //s[l]即s[i]就是第一个坑
    while (i < j)
    {
        //从右边向左找小于x的数来填s[i]
        while (i < j && s[j] >= x)
            j--;
        if (i < j)
        {
            s[i] = s[j];
            i++;
        }
        while (i < j && s[i] < x) //从左向右找大于或等于x的数来填s[j]
            i++;
        if (i < j)
        {
            s[j] = s[i]; //将s[i]填到s[j]中，s[i]就形成了一个新的坑
            j--;
        }
    }
    s[i] = x;

    return i
}
void quick_sort1(int s[], int l, int r)
{
    if (l < r)
    {
        int i = AdjustArray(s, l, r); //先成挖坑填数法调整s[]
        quick_sort1(s, l, i - 1);     // 递归调用
        quick_sort1(s, i + 1, r);
    }
}
//快速排序简化版
void Quick_Sort(int s[], int l, int r)
{
    if (l < r)
    {
        //Swap(s[l],s[(l+r)/2])//将中间的这个数和第一个数交换
        int i = l, j = r, x = s[l];
        while (i < j)
        {
            while (i < j && s[j] >= x) //从有向左找第一个数
                j--;
            if (i < j)
                s[i++] = s[j];
            while (i < j && s[i] < x)
                i++;
            if (i < j)
                s[j--] = s[i];
        }
        s[i] = x;
        quick_sort(s, l, i - 1);
        quick_sort(s, i + 1, r);
    }
}