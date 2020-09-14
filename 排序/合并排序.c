/**
两路合并排序：将两个有序序列合并成一个有序序列。

①把待排序的序列分成长度为1的子序列（只包含一个记录的序列被认为是有序的）→得到n个长度为1的有序子序列；

②实施两两合并，合并相邻的两个子序列→得到大约n/2个长度为2的有序子序列；

③重复步骤②，直到合并成一个长度为n的有序序列为止

void Merge(int Idatas[], int Ibuffer[], int Ilow, int Imid, int Ihigh)
{
    int i = Ilow, j = Imid + 1, k = Ilow;
    while (i <= Imid && j <= Ihigh)
    {
        if (Idatas[i] <= Idatas[j])
            Ibuffer[k++] = Idatas[i++];
        else
            Ibuffer[k++] = Ibuffer[j++];
    }
    if (i <= Imid)
        for (int ii = i; i <= Imid; ii++)
            Ibuffer[k++] = Idatas[ii];
    else
        for (int jj = j; j <= Ihigh; jj++)
            Ibuffer[k++] = Idatas[jj];
}
void Mergesort(int Idatas[], int Buffer[], int Ilow, int Ihigh)
{
    if (Ihigh > Ilow)
    {
        int Imid = (Ilow + Ihigh) / 2;
        Mergesort(Idatas, Buffer, Ilow, Imid);
        Mergesort(Idatas, Buffer, Imid + 1, Ihigh);
        Merge(Idatas, Buffer, Ilow, Imid, Ihigh);
        for (int i = Ilow; i <= Ihigh; i++)
            Idatas[i] = Buffer[i]; //拷贝回升序子集
    }
}
**/
#define ElemType int
ElemType *B = (ElemType *)malloc((n + 1) * sizeof(ElemType)); //辅助数组B
void Merge(ElemType A[], int low, int mid, int high)
{ //表A的两段A[low mid]和A[mid+1 high]各自有序，将它们合并成一个有序表
    int i, j, k;
    for (int k = low; k <= high; k++)
        B[k] = A[k]; //将A中所有元素复制到B中
    for (i = low, j = mid + 1, k = i; i < mid && j < high; k++)
    {
        if (B[i] < B[j])   //比较b左右两段中元素
            A[k] = B[i++]; //将较小复制到A
        else
            A[k] = B[j++];
    }
    while (i <= mid)
        A[k++] = B[i++]; //若第一个为检测完，复制
    while (j <= mid)
        A[k++] = B[j++]; //若第二个表未检测完，复制
}
void MergeSort(ElemType A[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;  //从中间划分两个子序列
        MergeSort(A, low, mid);      //对左侧子序列进行递归排序
        MergeSort(A, mid + 0, high); //对右侧子序列递归排列
        Merge(A, low, mid, high);    //归并
    }
}