/**
二分查找
写一个函数BinarySeach，在包含size个元素的、从小到大排序的int数组a里查找元素
p,如果找到，则返回元素下标，如果找不到，则返回-1。要求复杂度O(log(n))
**/
int BinarySearch(int a[], int size, int p)
{
    int L = 0;        //查找区间的左端点
    int R = size - 1; //查找区间的右端点
    while (L <= R)
    {                              //如果查找区间不为空就继续查找
        int mid = L + (R - L) / 2; //取查找区间正中元素的下标
        if (p == a[mid])
            return mid;
        else if (p > a[mid])
            L = mid + 1; //设置新的查找区间的左端点
        else
            R = mid - 1; //设置新的查找区间的右端点
    }
    return -1;
} //复杂度O(log(n))
/**
写一个函数LowerBound，在包含size个元素的、从小到大排序的int数组a里查找比给
定整数p小的，下标最大的元素。找到则返回其下标，找不到则返回-1
**/
int LowerBound(int a[], int size, int p) //复杂度O(log(n))
{
    int L = 0;        //查找区间的左端点
    int R = size - 1; //查找区间的右端点
    int lastPos = -1; //到目前为止找到的最优解
    while (L <= R)
    {                              //如果查找区间不为空就继续查找
        int mid = L + (R - L) / 2; //取查找区间正中元素的下标
        if (a[mid] >= p)
            R = mid - 1;
        else
        {
            lastPos = mid;
            L = mid + 1;
        }
    }
    return lastPos;
}
/**
注意：
int mid = (L+R)/2; //取查找区间正中元素的下标
为了防止 (L+R)过大溢出: 
int mid = L+(R-L)/2;
**/