/**
从顺序表中删除具有最小值的元素(假设唯一)并由函数返回删除的值。
空出的位置又最后一个元素填补，若顺序表为空则显示出错信息并退出运行
**/
//算法思想：查找最小值的元素并记住其位置，搜索结束后用最后一个元素填补原来最小元素的值
bool Del_Min(sqList &L, int &value)
{
    if (L.length == 0)
        return false; //如果表空结束操作
    value = L.data[0];
    int pos = 0; //假定0号元素最小
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] < value)
        {
            value = L.data[i];
            pos = i;
        }
    }
    L.data[pos] = L.data[L.length - 1]; //空出的位置由最后一个元素填补
    L.length--;
    return true;
}