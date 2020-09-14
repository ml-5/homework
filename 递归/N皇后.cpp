/**
输入一个正整数N，则程序输出N皇后问题的全部摆法。
输出结果里的每一行都代表一种摆法。行里的第i个数字如
果是n，就代表第i行的皇后应该放在第n列。
皇后的行、列编号都是从1开始算。
**/
#include <iostream>
#include <cmath>
using namespace std;
int N;
int queenPos[100];
void NQueen(int k);
int main()
{
    cin >> N;
    NQueen(0); //从第0行开始摆皇后
    return 0;
}
void NQueen(int k) //在0~k-1行皇后摆好的情况下，摆k行及其以后的
{
    int i;
    if (k == N)
    { //N个皇后已经摆好
        for (i = 0; i < N; i++)
            cout << queenPos[i] + 1 << "";
        cout << endl;
        return;
    }
    for (i = 0; i < N; i++) //尝试第K个皇后的列数
    {
        int j;
        for (j = 0; j < k; j++)
        {
            //和已经摆好的k个皇后位置进行比较看是否冲突
            if (queenPos[j] == i || abs(queenPos[j] - i) == abs(k - j)) //判断是否同列或者斜
                break;
        }
        if (j == k)
        {
            //当选的位置i布冲突
            queenPos[k] = i; //将第k个皇后摆放在位置i
            NQueen(k + 1);
        }
    }
}