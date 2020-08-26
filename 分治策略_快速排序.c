int partition(int Datas[], int Left, int Right)
{
    int i = Left + 1, j = Right;
    int iAnchor = Datas[Left]; //基准元素
    while (i <= j)
    {
        while (Datas[i] <= iAnchor && i <= Right)
            i++;
        while (Datas[j] > iAnchor)
            j--;
        if (i < j)
        {
            swap(Datas[i], Datas[j]); //小于iAnchor,大于iAnchor后移
            i++;
            j--;
        }
    }
    swap(Datas[Left], Datas[j]);
    return j;
}
void swap(int *Valuel, int *Value2)
{
    int Temp = Valuel;
    Valuel = Value2;
    Value2 = Temp;
}
void quickSort(int Datas[], int Left, int Right)
{
    if (Right > Left)
    {
        int k = partition(Datas, Left, Right);
        quickSort(Datas, Left, k - 1);
        quickSort(Datas, k + 1, Right);
    }
}