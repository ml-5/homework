/**长度为n的顺序表L,编写一个时间复杂度为O(n),空间复杂度为O(1)的算法,该算法删除线性表中所有值为x的元素**/
//解法1：用k记录顺序表中不等于X的元素，边扫描L边统计k,并将不等于x的元素放在k位置上，最后修改L的长度
void Del_x_List(SqList *L, int x)
{
    int k = 0, i; //记录不等于x的元素的个数
    for (i = 0; i < L.length; i++)
        if (L.data[i] != x)
            L.data[k++] = L.data[i];
}
//解法2：用k记录L中等于x的元素个数，边扫描L，边统计K，并将不等于x的元素前移k个位置，最后修改L
//的长度
void Del_x_List2(SqList *L, int x)
{
    int k = 0, i = 0; //k记录等于x的元素个数
    while (i < L.length)
    {
        if (L.data[i] == x)
            k++;
        else
            L.data[i - k] = L.data[i]; //当前元素前移k个位置
    }
    L.length = L.length - k;//顺序表L的长度
}