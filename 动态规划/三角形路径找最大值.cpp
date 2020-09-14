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
将递归转化成递推
**/
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 101
int D[MAX][MAX];
int n;
int maxSum[MAX][MAX];
int main()
{
    int i, j;
    cin >> n;
    for (i = 1; i <= n; i++) //输入三角形的值
        for (j = 1; j <= i; j++)
            cin >> D[i][j];
    for (int i = 1; i <= n; ++i)
        maxSum[n][i] = D[n][i];      //最底层的直接初始化
    for (int i = n - 1; i >= 1; --i) //对n-1层执行相同的策略即计算出当前路径最大值保存在maxSum中
        for (int j = 1; j <= i; ++j)
            maxSum[i][j] = max(maxSum[i + 1][j], maxSum[i + 1][j + 1]) + D[i][j];
    cout << maxSum[1][1] << endl;
}
//空间优化没必要用二维maxSum数组存储每一个MaxSum(r,j),只要从底层一行行向上
//递推，那么只要一维数组maxSum[100]即可,即只要存储一行的MaxSum值就
//可以。
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 101
int D[MAX][MAX];
int n;
int *maxSum;
int main()
{
    int i, j;
    cin >> n;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= i; j++)
            cin >> D[i][j];
    maxSum = D[n]; //maxSum指向第n行
    for (int i = n - 1; i >= 1; --i)
        for (int j = 1; j <= i; ++j)
            maxSum[j] = max(maxSum[j], maxSum[j + 1]) + D[i][j];
    cout << maxSum[1] << endl;
}