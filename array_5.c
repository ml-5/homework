/**

题目描述
输入一个整数数组，实现一个函数来调整该数组中数字的顺序。

使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分。

样例
输入：[1,2,3,4,5]

输出: [1,3,5,2,4]
**/
//方法:用两个指针分别从首尾开始，往中间扫描，扫描是保证第一个指针前面的数都是奇数，第二个指针后面都是偶数
//1.第一个指针一直往后走，直到遇到第一个偶数为止
//2.第二个指针一直往前走，直到遇到第一个奇数为止
//3.交换两个指针位置上的数，进入下一次迭代
void reOrderArray(int *array, int length)
{
    int i=0, j = length - 1,t;
    while (i < j)
    {
        while (i < j && array[i] % 2 == 1)//头指针
            i++;
        while (i < j && array[j] % 2 == 0)//尾指针
            j--;
            t=array[i];
            array[i]=array[j];
            array[j]=t;
    }
}