两者都可以遍历整个空间搜索
两者对比：
数据结构：DFS（栈） BFS（队列）
/*使用空间：
DFS只需要记录这条搜索路径上所有点即可，与树的高度成正比O(h)，使用空间较少
BFS会把每一层的所有节点存下来，使用空间对于高度而言是指数级别O(2^h)，使用空间较大
最短路:
在每条边权值为1的前提下，BFS搜索到的点具有最短路性质，DFS则不具有，一般题目问最短距离，
最少步数，最少操作几次，基本上都是BFS

DFS俗称暴力搜索，最重要的是按照怎样的顺序遍历，以及回溯时注意恢复现场
回溯与剪枝

给定一个数字n，把1-n的所有全排列按照字典序输出，依次判断每一位可以放哪些元素去搜索
*/
#include <iostream>
    using namespace std;
const int N = 10;
int n;
int path[N];
bool st[N];
void dfs(int u)
{
    if (u == n)
    {
        for (int i = 0; i < n; i++)
            cout << path[i] << " ";
            cout<<endl;
            return;
    }
    for(int i=1;i<=n;i++)
    {
        if(!st[i])
        {
            path[u]=i;
            st[i]=true;
            dfs(u+1);//递归下一层
            //恢复现场
            st[i]=false;
        }
    }
}
int main(void)
{
    cin>>n;
    dfs(0);
    return 0;
}