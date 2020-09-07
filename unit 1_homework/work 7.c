/**将两个有序的有序表合成一个新的有序顺序表,并由函数返回结果顺序表**/
//首先,按顺序不断取下两个顺序表
bool Merge(SqList A, SqList B, SqList *C)
{
    //合并有序顺序表A与B成为一个有序顺序表C
    if (A.length + B.length > C.maxsize) //大于顺序表的最大长度
        return false;
    int i = 0, j = 0, k = 0;
    while (i < A.length && j < B.length)
    { //循环，两两比较，小的存入结果表
        if (A.data[i] <= B.data[j])
            C.data[k++] = A.data[i++];
        else
            C.data[k++] = B.data[j++];
    }
    while (i < A.length)
        C.data[k++] = A.data[i++];
    while (j < B.length)
        C.data[k++] = B.data[j++];
    C.length = k + 1;
    return true;
}
