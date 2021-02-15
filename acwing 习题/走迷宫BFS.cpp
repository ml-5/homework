/*
优势:搜索到最短路(只有当前所有边的权值为1的前提下，才能用bfs求最短路),一层一层去搜索常用的框架
：
初始状态放入queue中
while(queue不空)
{
    t<-对头元素 拿出对头元素
    扩展队列
}
*/
#include<iostream>
#include<cstring>
using namespace std;
const int N=110;
int n,m;
int g[N][N],d[N][N];
typedef pair<int,int> PII;
PII q[N*N],pre[N*N];//前者是自己实现的队列，队列中每一个元素的坐标都是pair，后者是多记录路径
int bfs()
{
    int hh=0,tt=0;
    q[0]={0,0};
    memset(d,-1,sizeof d);//将每个点到起点的距离都设置为-1，表示这个点没有探索过
    d[0][0]=0;
    int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
    while(hh<=tt)
    {
        auto t=q[hh++];
        for(int i=0;i<4;i++)
        {
            //对于当前的节点t ,依次探索4个方向是否都可行
            int x=t.first+dx[i],y=t.second+dy[i];
            if(x>=0&&x<n&&y>=0&&y<m&&g[x][y]==0&&d[x][y]==-1)
            {
                d[x][y]=d[t.first][t.second]+1;
                pre[x][y]=t;
                q[++tt]={x,y};
            }
        }
    }
    int x=n-1,y=m-1;
    while(x||y)
    {
        cout<<"x+1"<<' '<<y+1<<endl;
        auto t=pre[x][y];
        x=t.first,y=t.second;
    }
    cout<<1<<' '<<endl;
    return d[n-1][m-1];
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cin>>g[i][j];
    }
    
    cout<<bfs()<<endl;
    return 0;
}
