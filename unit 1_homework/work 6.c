/**从有序表中删除所有其值重复的元素，让表中的所有元素的值都不同**/
//比较相邻的元素
bool Delete_Same(SqList *L)
{
    if (L.length == 0)
        return false;
    int i, j; //i储存第一个不相同的元素,j工作指针
    for (i = 0, j = 1; j < L.length; j++)
        if (L.data[i] != L.data[j]) //查找下一个与上一个元素值不同的元素
            L.data[++i] = L.data[j];//找到后则将元素前移
    L.legth = i + 1;//i是数组的下标，从0开始,要返回数组的长度加1，下标的长度相差1
    return true;
}