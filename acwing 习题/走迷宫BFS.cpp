/*
����:���������·(ֻ�е�ǰ���бߵ�ȨֵΪ1��ǰ���£�������bfs�����·),һ��һ��ȥ�������õĿ��
��
��ʼ״̬����queue��
while(queue����)
{
    t<-��ͷԪ�� �ó���ͷԪ��
    ��չ����
}
*/
#include<iostream>
#include<cstring>
using namespace std;
const int N=110;
int n,m;
int g[N][N],d[N][N];
typedef pair<int,int> PII;
PII q[N*N],pre[N*N];//ǰ�����Լ�ʵ�ֵĶ��У�������ÿһ��Ԫ�ص����궼��pair�������Ƕ��¼·��
int bfs()
{
    int hh=0,tt=0;
    q[0]={0,0};
    memset(d,-1,sizeof d);//��ÿ���㵽���ľ��붼����Ϊ-1����ʾ�����û��̽����
    d[0][0]=0;
    int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
    while(hh<=tt)
    {
        auto t=q[hh++];
        for(int i=0;i<4;i++)
        {
            //���ڵ�ǰ�Ľڵ�t ,����̽��4�������Ƿ񶼿���
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
