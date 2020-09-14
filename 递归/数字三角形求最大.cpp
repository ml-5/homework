/**

7
3 8
8 1 0
2 7 4 4
4 5 2 6 5

在上面的数字三角形中寻找一条从顶部到底边的路径，使得
路径上所经过的数字之和最大。路径上的每一步都只能往左下或
右下走。只需要求出这个最大和即可，不必给出具体路径。
三角形的行数大于1小于等于100，数字为 0 - 99

输入格式：
5 //三角形行数。下面是三角形
7
3 8
8 1 0
2 7 4 4 
4 5 2 6 5 
要求输出最大和

思路:
用二维数组存放数字三角形。
D( r, j) : 第r行第 j 个数字(r,j从1开始算)
MaxSum(r, j) : 从D(r,j)到底边的各条路径中，
最佳路径的数字之和。
问题：求 MaxSum(1,1)
典型的递归问题。
D(r, j)出发，下一步只能走D(r+1,j)或者D(r+1, j+1)。故对于N行的三角形：
if ( r == N) 
MaxSum(r,j) = D(r,j)
else 
MaxSum( r, j) = Max{ MaxSum(r＋1,j), MaxSum(r+1,j+1) } 
+ D(r,j)
**/
#include <iostream>
#include <algorithm>
#define MAX 101
using namespace std;
int D[MAX][MAX]; //输入三角形值
int n;
int MaxSum(int i, int j)
{
    if (i == n) //当i到第n行结束
        return D[i][j];
    int x = MaxSum(i + 1, j);
    int y = MaxSum(i + 1, j + 1);
    return max(x, y) + D[i][j]; //找寻下一行的最大值
}
int main()
{
    int i, j;
    cin >> n;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= i; j++)
            cin >> D[i][j];
    cout << MaxSum(1, 1) << endl;
}
//注意此算法会超时 递归深度遍历时多次计算
//改进如果每算出一个MaxSum(r,j)就保存起来，下次用到其值的时候直接取用，则可免去重复计算。那么可以用O(n2)时间完成计算。因为三角形的数字总数是 n(n+1)/2
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 101
int D[MAX][MAX];
int n;
int maxSum[MAX][MAX];
int MaxSum(int i, int j)
{
    if (maxSum[i][j] != -1)
        return maxSum[i][j];
    if (i == n)
        maxSum[i][j] = D[i][j];
    else
    {
        int x = MaxSum(i + 1, j);
        int y = MaxSum(i + 1, j + 1);
        maxSum[i][j] = max(x, y) +D[i][j];
    }
    return maxSum[i][j];
}
int main()
{
    int i, j;
    cin >> n;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= i; j++)
        {
            cin >> D[i][j];
            maxSum[i][j] = -1;
        }
    cout << MaxSum(1, 1) << endl;
}