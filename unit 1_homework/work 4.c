/**从有序顺序表中删除其值在给定值s与t之间的所有元素，如果s或t不合理，或顺序表为空退出**/
//本题与第三题有类似可以采取同样的做法，但又因为有序，故直接前移s-t的长度
bool Del_s_t(SqList *L, int s, int t)
{
    //删除有序顺序表中值在s~t之间的所有元素
    int i, j;
    if (s >= t || L.length == 0)
        return false;
    for (i = 0; i < L.length && L.data[i] < s; i++)
        ; //寻找第一个大于等于s的元素
    if (i >= L.length)
        return false;
    for (j = i; j < L.length && L.data[j] <= t; j++)
        ; //寻找大于t的第一个元素
    for (; j < L.lenth; i++, j++)
        L.data[i] = L.data[j];
    L.length = i + 1;
    return true;
}