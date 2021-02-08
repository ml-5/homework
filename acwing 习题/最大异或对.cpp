/*
二进制XOR运算是两者相同为0，不同为1
暴力
for(int i=0;i<n;i++){
    for(int j=0;j<i;j++){//因为A^B=B^A，所以第二层循环只遍历i之前的元素便于减少重复
        res=max(res,a[i]^a[j]);
    }
}
优化
优化
利用trie优化内层循环:在固定a[i]后，寻找a[i]前面与a[i]异或最大的元素
每一个数都可以看作31位的二进制串，在a[i]前面的那些数对应的二进制串中
从最高位开始探索，当某一位的二进制数与a[i]的相同位不同时，只继续探索这一些不同的数，
尽量找不同，可以用trie树存储这些数，查询时从根节点开始，
每一次尽量往与当前这一位不同的那一些位上走
之前内层循环时间复杂度是0(n) 现在最多从根节点走到叶节点，
内层循环时间复杂由十万级别的n变为31
*/
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100010, M = 31 * N;

int n;
int a[N];
int son[M][2], idx;
//trie树中每一条分支代表一个数，每条分支有31个节点，所以最多有310万个节点
void insert(int x)
{
    int p = 0; //从根节点开始探索
    for (int i = 30; i >= 0; i--)
    {                       //从最高位开始探索
        int u = x >> i & 1; //得到x的第i位二进制
        if (!son[p][u])
            son[p][u] = ++idx;
        p = son[p][u];
    }
    //不用像字符串一样记录每个节点结尾的单词有多少个
    //是因为每一个数都有31位，不会存在覆盖的情况
}
int query(int x)
{
    int p = 0, res = 0;
    for (int i = 30; i >= 0; i--)
    {
        int u = x >> i & 1;
        if (son[p][!u])
            p = son[p][!u], res = res * 2 + !u; //尽量往与当前这一位不同的方向走
        else
            p = son[p][u], res = res * 2 + u;
    }
    return res;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        //外层循环，依次枚举每个数
        insert(a[i]);
        int t = query(a[i]); //先插入再查询便于处理边界问题
        res = max(res, a[i] ^ t);
    }
    cout << res << endl;
    return 0;
}
