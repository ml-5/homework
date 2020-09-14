/**
设顺序表L有10个整数。设计一个算法，以第一个元
素为分界线（基准），将所有小于等于它的元素移到该元素的前面，
将所有大于它的元素移到该元素的后面。
**/
/**
解法1:pivot=L->data[0]（基准）
j从后向前找≤pivot的元素
i从前向后找>pivot的元素
交换两者
**/
void move1(SqList **L)
{
    int i, j = L->length - 1;
    ElemType tmp;
    ElemType pivot = L->data[0]; //以data[0]为基准
    while (i < j)
    {
        while (i < j && L->data[j] > pivot)
            j--; //从后向前扫描，找到小于基准的元素
        while (i < j && L - data[i] >= pivot)
            i++; //从前向后扫描找到大于等于基准的元素
        if (i < j)
        {
            tmp = L->data[i];
            L->data[i] = L->data[j];
            L->data[j] = tmp;
        }
    }
    tmp = L->data[0];
    L->data[0] = L->data[j];
    L->data[j] = tmp;
}
/**
解法2:pivot=L->data[0]（基准）
j从后向前找小于等于pivot的元素：前移
i从前向后找大于pivot的元素：后移
**/
void move2(SqList *&L)
{
    int i = 0, j = L->length - 1;
    ElemType pivot = L->data[0]; //以data[0]为基准
    while (i < j)
    {
        while (j > i && L->data[j] > pivot)
            j--;                 //从右向左扫描,找一个≤pivot的data[j]
        L->data[i] = L->data[j]; //将其放入data[i]处
        while (i < j && L->data[i] <= pivot)
            i++;                 //从左向右扫描,找一个>pivot的记录data[i]
        L->data[j] = L->data[i]; //将其放入data[j]处
    }
    L->data[i] = pivot; //放置基准
}