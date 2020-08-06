/**
已知长度为n的线性表A采用顺序存储结构。设计
一个时间复杂度为O(n)、空间复杂度为O(1)的算法，该算法删除
线性表中所有值为x的数据元素。
以下两种方法都不满足要求：
如果每删除一个值为x的元素都进行移动，其时间复杂度为O(n2)，
空间复杂度为O(1)。
如果借助一个新的顺序表，存放将A中所有不为x的元素，其时间复
杂度为O(n)，空间复杂度为O(n)。
**/
/**
解法1：设删除A中所有值等于x元素后的顺序表为A1，显 然A1包含在A中，为此A1重用A的空间。
解法2：用k记录顺序表A中等于x的元素个数，一边扫描A一 边统计k值。
**/
void delondel(SqList**A,ElemType x)
{
    int k,i;  //k值记录不等于x的元素个数
    for(i=0;i<A->length;i++)
    if(A->data[i]!=x)//若当前元素不等于x,将其插入A中
    {
        A->data[k]=A->data[i];
        k++;                 //不等于x的元素加1
    }
    A->length=k;
}
//将不为x的元素前移k个位置，最后修改A的长度。
void delnode(SqList**A,ElemType x)
{
    int k=0,i=0;
    while(i<A->length)
    {
        if(A->data[i]==x)
        k++;
        else
        A->data[i-k]=A->data[i];
        i++;
    }
    A->length-=k;
}