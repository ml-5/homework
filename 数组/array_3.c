/**
题目:
在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。

请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

样例
输入数组：

[
  [1,2,8,9]，
  [2,4,9,12]，
  [4,7,10,13]，
  [6,8,11,15]
]

如果输入查找数值为7，则返回true，

如果输入查找数值为5，则返回false。

思路:
发现这个二维数组的规律:每行中最右边的最大，每列中最下侧数最大
从最右上方开始扫描
若当前的值正好等于target，返回true
否则当前值小于target，则说明当前位置左侧的数都小于target，行号i++
否则当前值大于target，则说明当前正下方的数都大于target，列号j--;
直到遍历左下方仍没有找到target，则返回false
**/
bool searchArray(int **array, int arrayRowSize, int arrayColSize, int target)
{
  int i = 0;
  int j = arrayColSize - 1;
  while (i < arrayRowSize && j >= 0)
  {
    if (array[i][j] == target)
      return true;
    else if (array[i][j] < target)
      i++;
    else
      j--;
  }
  return false;
}
