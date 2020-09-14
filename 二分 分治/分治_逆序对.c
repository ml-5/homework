/**
问题描述：设𝐴[1, ⋯ , 𝑛]是一个包含𝑛个不同非负整数的数组。如果在𝑖 < 𝑗的情况下， 有𝐴 𝑖 > 𝐴[𝑗]，
则（𝐴 𝑖 ，𝐴[𝑗]）就称为A中的一个逆序对。例如，数组（3，1，4， 5，2）的“逆序对”有<3,1>、<3,2>、<4,2>、<5,2>共4个。
输入：每个测试用例包括两行，第一行输入整数的个数n，𝑛 ≤ 10000，第二行输入
𝑛个整数，数与数之间用空格隔开。最后一行输入-1，表示输入结束。
输出：每组测试数据的结果输出占一行，输出该数组中逆序对的个数。
样例输入：
53 1 4 5 2 -1
样例输出：
4
**/
/*
1） 如果𝐴1 𝑖 > 𝐴2 𝑗 ，则有：
𝐴1 𝑖 + 1 > 𝐴2 𝑗 ；
……
𝐴1 (𝑙 + 𝑟)/2 > 𝐴2 𝑗 ；
一次比较可以推导出多个逆序对
2）如果𝐴1 𝑖 ≤ 𝐴2 𝑗 ，则有：
𝐴1 𝑖 ≤ 𝐴2 𝑗 + 1 ；
……
𝐴1 𝑖 ≤ 𝐴2 𝑟 ；
97 13 40 76 A2
一次比较可以省略多次比较
38 > 13 {49, 65, 97} > 13 增加4个逆序对
38 < 40 38 < {76} 38不会再与A2中元素产生逆序对
49 > 40 {65, 97} > 40 增加3个逆序对
49 < 76 49不会再与A2中元素产生逆序对
65 < 76 65不会再与A2中元素产生逆序对
97 > 76 增加1个逆序对
*/
long MergeReverse(int Datas[], int Buffer[], int Low, int Mid, int High)
{
    int i = Low, j = Mid + 1, k = Mid;
    long c;
    while (i <= Mid && j <= High)
    {
        if (Datas[i] <= Datas[j])
            Buffer[k++] = Datas[i++];
        else
        {
            c += Mid - i + 1;
            Buffer[k++] = Datas[j++];
        }
    }
    if (i <= Mid)
        for (int ii = i; i <= Mid; ii++)
            Buffer[k++] = Datas[ii];
    else
        for (int jj = j; jj <= High; jj++)
            Buffer[k++] = Datas[jj];
    return c;
}

long ReveseOrder(int Datas[], int Buffer[], int Low, int High)
{
    if (Low = High)
        return 0;
    int Mid = (Low + High) / 2;
    long c1, c2, c3;
    c1 = ReveseOrder(Datas, Buffer, Low, Mid);
    c2 = ReveseOrder(Datas, Buffer, Mid + 1, High);
    c3 = MergeReverse(Datas, Buffer, Low, Mid, High);
    for (int i = Low; i <= High; i++)
        Datas[i] = Buffer[i];
    return c1 + c2 + c3;
}