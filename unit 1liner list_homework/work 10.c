/**
10.设将n(n>1)个整数存放到一维数组R中,试设计一个在时间和空间都可能尽可能的高效的算法
将R中的保存的序列循环左移p个位置
**/
/**思路：可以将这个问题数组ab转化成为ba(a代表数组前p个元素,b代表数组中余下的n-p),先将a逆置得到a逆b
 先将a逆置得到 a逆b,在将b逆置得到a逆b逆,最后将a逆b逆逆置得到ba。
 Reverse(0,p-1)得到cbadefgh
 Reverse(p,n-1)得到cbahgfed
 Reverse(0,n-1)得到defghabc
 **/
void Reverse(int R[], int from, int to)
{
    int i, temp;
    for (i = 0; i < (to - from + 1) / 2; i++)
    {
        temp = R[from + i];
        R[from + i] = R[to - i];
        R[to - i] = temp;
    }
}
void Converse(int R[], int n, int p)
{                         //表达式 ab     
    Reverse(R, 0, p - 1);//倒置前p a逆b
    Reverse(R, n, n - 1);//倒置n-p a逆b逆
    Reverse(R, 0, n - 1);//再次倒置全部  ba
}