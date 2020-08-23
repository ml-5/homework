/**
字符串的全排列
给定一组互不相同的字符，求这组字符的全排列
输出该字符串的全排列，排列的先后顺序不影响结果
输入：ABC
输出：ABC ACB BAC BCA CAB CBA

思路:当输入为的字符长度超 过1时，只需从字符串中选一个字符作为输出字
符串首字符，对其余的字符进行递归处理（全排列）即可
**/
void Permutations(string str, int i, int n)
{
    if (i == n - 1)
    {
        cout << str << endl;
        return;
    }
    //递归处理长度大于1的字符串
    for (int j = i; j < n; j++)
    {                         //交换当前第一个字符与其它位置字符
        swap(str[i], str[j]); //STL函数
        //递归处理子串str[i+1,n-1]
        Permutations(str, i + 1, n);
        swap(str[i], str[j]);
    }
}