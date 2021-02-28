#include<iostream>
#include<cstring> 
using namespace std;
const int maxn=1000.;
const int alpha=26;
typedef struct {
    int weight;//权重
    int parent,lchild,rchild;//父节点 左孩子 右孩子
}HufNode;//HuffmanTree的基本定义
typedef struct {
    int weight;//权重 
    char data;//数据域
    char code[maxn];//需要被建树的信息
}HufCode;
void Init(HufCode h[])//初始化输入数据
{
    FILE *f1=fopen("DataFile.data","r");
    for(int i=0;i<alpha;++i)
        fscanf(f1,"%c%d ",&h[i].data,&h[i].weight);

    fclose(f1);
}
//这里合并的时候遵循左孩子小于右孩子
void select(HufNode *h,int k,int &s1,int &s2)//选择两个最小的值
{
    int i;
    for(i=0; i<k && h[i].parent != 0; ++i);//选择一个父节点为0的根节点
            s1 = i;
    for(i=0; i<k; ++i){
        if(h[i].parent==0 && h[i].weight<h[s1].weight)
              s1 = i;
    }
    for(i=0; i<k; ++i){
        if(h[i].parent==0 && i!=s1)
            break;
    }
    s2 = i;
    for(i=0; i<k; ++i){
        if(h[i].parent==0 && i!=s1 && h[i].weight<h[s2].weight)
            s2 = i;
    }
}
void HuffmanTree(HufCode *h2,HufNode *h1,int n)//建立哈夫曼树
{
    char str[maxn];
    int m=2*n-1;//对于n个节点的哈夫曼树两两合并n-1次 树最后有2*n-1个节点
     /* 初始化存放哈夫曼树数组 HuffNode[] 中的结点 */
    for(int i=0;i<m;++i){
        if(i<n)//前n个全部是叶子节点，
            h1[i].weight=h2[i].weight;
        else//后面的是还没建成的树
            h1[i].weight==0;
        h1[i].lchild=h1[i].parent=h1[i].rchild=0;//对节点父节点左孩子右孩子初始化为0表示为空
    }
    //
    int s1,s2;
    //执行n-1次合并每次找到最小的父节点为空两个节点
    for(int i=n;i<m;++i){
        select(h1,i,s1,s2);
        h1[s1].parent=i;//建立二叉树
        h1[s2].parent=i;
        h1[i].lchild=s1;
        h1[i].rchild=s2;
        h1[i].weight=h1[s1].weight+h1[s2].weight;
    }
    str[n]='\0';
    int l;
    for(int i=0;i<n;++i){//从每个叶子节点开始倒序遍历
        l=n-1;//倒序赋值字符串
        for(int k=i,p=h1[k].parent;p;k=p,p=h1[k].parent){//沿着叶子回溯到根节点
            if(k==h1[p].lchild)
                str[l]='0';
            else
                str[l]='1';
            l--;
        }
        strcpy(h2[i].code,str+l+1);
    }
}
void EnCodeing(HufCode hc[])//编码
{
    FILE *f1=fopen("ToBeTran.data","r");
    FILE *f2=fopen("Code.txt","w");
    char str[maxn];
    while(fscanf(f1,"%s",str)!=EOF)
    {
        int len=strlen(str);
        for(int i=0;i<len;++i){//遍历每个字符对其编码
            int x=str[i]-'a';//处理一下
            fprintf(f2,"%s",hc[x].code);
        }
        fprintf(f2," ");
    }
    fclose(f1);
    fclose(f2);
}
int Search(HufCode hc[],char *str)
{
    for(int i=0;i<alpha;++i)
        if(strcmp(hc[i].code,str)==0)
            return  i;
    return -1;
}
void DeCodeing(HufCode hc[])//解码
{
    FILE *f1=fopen("CodeFile.data","r");
    FILE *f2=fopen("Textfile.txt","w");
    char str[maxn];
    while(fscanf(f1,"%s",str)!=EOF)
    {
        char a[maxn];
        memset(a,'\0',sizeof(a));//将数组初始化
        int len=strlen(str),k=0;
        for(int i=0;i<len;++i){//对每个进行译码
            a[k]=str[i];
            a[k+1]='\0';
            int ans=Search(hc,a);//查找编码对应字符找到返回字符的下标没就返回-1
            if(ans!=-1){
                fprintf(f2,"%c",ans+'a');
                k=0;
                continue;
            }
            k++;
        }
        fprintf(f2," ");
    }

    fclose(f1);
    fclose(f2);
}
void OutPut()//显示函数
{
    FILE *infile=fopen("DataFile.data","r");
    FILE *outfile=fopen("Code.txt","r");
    int w;
    char c;
    printf("各个字母及其权值\n");
    for(int i=0;i<alpha;++i){
        fscanf(infile,"%c %d ",&c,&w);
        printf("%c %d ",c,w);
    }

    infile=fopen("ToBeTran.data","r");
    printf("\n\n待编码的内容：\n");
    char str[maxn];
    while(fscanf(infile,"%s",str)!=EOF)
        printf("%s ",str);

    printf("\n编码后结果：\n");
    while(fscanf(outfile,"%s",str)!=EOF)
        printf("%s ",str);

    printf("\n\n待解码内容：\n");
    infile=fopen("CodeFile.data","r");
    while(fscanf(infile,"%s",str)!=EOF)
        printf("%s ",str);

    printf("\n解码结果：\n");
    outfile=fopen("Textfile.txt","r");
    while(fscanf(outfile,"%s",str)!=EOF)
        printf("%s ",str);
    printf("\n");

    fclose(infile);
    fclose(outfile);
}
int main()
{
    HufCode hc[maxn];
    HufNode tree[maxn];
    Init(hc);//初始化
    HuffmanTree(hc,tree,alpha);//建树 
    printf("每个字母对应的哈夫曼编码如下:\n");
    for(int i=0;i<alpha;i++)
    printf("%c  %s\n",hc[i].data,hc[i].code);
    EnCodeing(hc);//编码
    DeCodeing(hc);//解码
    OutPut();//输出结果
    return 0;
}



