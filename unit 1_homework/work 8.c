/**
已知在一堆数组A[M+N]中依次存放两个线性表(a1,a2,...am)和(b1,b2....bn)
试编写一个函数，将数组中两个顺序表的位置互换，即将(b1,b2...bn)放在(a1,a2...am)
**/
//算法数组A[m+n]的全部元素逆置，然后在前n个元素，对后m个元素分别逆置
typedef int DataType;
void Reverse(DataType A[], int left, int rigth, int arraySize)
{
    //逆转
    if (left >= rigth || rigth >= arraySize) //检验合理性
        return;
    int mid = (left + right) / 2;
    for (int i = 0; i < mid - left; i++)
    {
        DataType temp = A[left + i];
        A[left + i] = A[right - i];
        A[right - i] = temp;
    }
}
void Exchange(DataType A[], int m, int n, int arraySize)
{
    /*数组A[m+n]中，从0到m-1存放a1~am,从m到m+n-1存放顺序表b1~bn*/
    Reverse(A, 0, m + n - 1, arraySize);
    Reverse(A, 0, n - 1, arraySize);
    Reverse(A, n, n + m - 1, arraySize);
}