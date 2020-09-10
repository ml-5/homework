/**从顺序表中删除其值在给定值s与t之间的所有元素，如果s或t不合理，或顺序表为空退出**/
bool Del_s_t(SqList *L, int s, int t)
{
    //删除顺序表中值在s与t之间的所有元素
    if (L.length == 0 || s >= t)
        return false; //线性表为空或s t不合法，返回
    for (i = 0; i < L.length; i++)
    {
        if (L.data[i] >= s && L.data[i] <= t)
            k++;
        else
            L.data[i - k] = L.data[i]; //当元素前移k个位置
    }
    L.length -= k; //长度减小
    return true；
}