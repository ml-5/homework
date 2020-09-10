/**设计一个高效的算法实现线性表的逆置**/
//算法思想:扫描顺序表的前半部分，对于L.data[i],将后半部分的对应元素进行交换L.data[L.length-1-i]
void Reverse(SqList *L)
{
    int temp; //辅助变量
    for (i = 0; i < L.length / 2; i++)
    {
        temp = L.data[i];//交换元素
        L.data[i] = L.data[L.length - 1 - i];
        L.data[L.length - i - 1] = temp;
    }
}