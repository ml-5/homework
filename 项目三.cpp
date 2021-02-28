#include<iostream>
#include<cstring> 
using namespace std;
const int maxn=1000.;
const int alpha=26;
typedef struct {
    int weight;//Ȩ��
    int parent,lchild,rchild;//���ڵ� ���� �Һ���
}HufNode;//HuffmanTree�Ļ�������
typedef struct {
    int weight;//Ȩ�� 
    char data;//������
    char code[maxn];//��Ҫ����������Ϣ
}HufCode;
void Init(HufCode h[])//��ʼ����������
{
    FILE *f1=fopen("DataFile.data","r");
    for(int i=0;i<alpha;++i)
        fscanf(f1,"%c%d ",&h[i].data,&h[i].weight);

    fclose(f1);
}
//����ϲ���ʱ����ѭ����С���Һ���
void select(HufNode *h,int k,int &s1,int &s2)//ѡ��������С��ֵ
{
    int i;
    for(i=0; i<k && h[i].parent != 0; ++i);//ѡ��һ�����ڵ�Ϊ0�ĸ��ڵ�
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
void HuffmanTree(HufCode *h2,HufNode *h1,int n)//������������
{
    char str[maxn];
    int m=2*n-1;//����n���ڵ�Ĺ������������ϲ�n-1�� �������2*n-1���ڵ�
     /* ��ʼ����Ź����������� HuffNode[] �еĽ�� */
    for(int i=0;i<m;++i){
        if(i<n)//ǰn��ȫ����Ҷ�ӽڵ㣬
            h1[i].weight=h2[i].weight;
        else//������ǻ�û���ɵ���
            h1[i].weight==0;
        h1[i].lchild=h1[i].parent=h1[i].rchild=0;//�Խڵ㸸�ڵ������Һ��ӳ�ʼ��Ϊ0��ʾΪ��
    }
    //
    int s1,s2;
    //ִ��n-1�κϲ�ÿ���ҵ���С�ĸ��ڵ�Ϊ�������ڵ�
    for(int i=n;i<m;++i){
        select(h1,i,s1,s2);
        h1[s1].parent=i;//����������
        h1[s2].parent=i;
        h1[i].lchild=s1;
        h1[i].rchild=s2;
        h1[i].weight=h1[s1].weight+h1[s2].weight;
    }
    str[n]='\0';
    int l;
    for(int i=0;i<n;++i){//��ÿ��Ҷ�ӽڵ㿪ʼ�������
        l=n-1;//����ֵ�ַ���
        for(int k=i,p=h1[k].parent;p;k=p,p=h1[k].parent){//����Ҷ�ӻ��ݵ����ڵ�
            if(k==h1[p].lchild)
                str[l]='0';
            else
                str[l]='1';
            l--;
        }
        strcpy(h2[i].code,str+l+1);
    }
}
void EnCodeing(HufCode hc[])//����
{
    FILE *f1=fopen("ToBeTran.data","r");
    FILE *f2=fopen("Code.txt","w");
    char str[maxn];
    while(fscanf(f1,"%s",str)!=EOF)
    {
        int len=strlen(str);
        for(int i=0;i<len;++i){//����ÿ���ַ��������
            int x=str[i]-'a';//����һ��
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
void DeCodeing(HufCode hc[])//����
{
    FILE *f1=fopen("CodeFile.data","r");
    FILE *f2=fopen("Textfile.txt","w");
    char str[maxn];
    while(fscanf(f1,"%s",str)!=EOF)
    {
        char a[maxn];
        memset(a,'\0',sizeof(a));//�������ʼ��
        int len=strlen(str),k=0;
        for(int i=0;i<len;++i){//��ÿ����������
            a[k]=str[i];
            a[k+1]='\0';
            int ans=Search(hc,a);//���ұ����Ӧ�ַ��ҵ������ַ����±�û�ͷ���-1
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
void OutPut()//��ʾ����
{
    FILE *infile=fopen("DataFile.data","r");
    FILE *outfile=fopen("Code.txt","r");
    int w;
    char c;
    printf("������ĸ����Ȩֵ\n");
    for(int i=0;i<alpha;++i){
        fscanf(infile,"%c %d ",&c,&w);
        printf("%c %d ",c,w);
    }

    infile=fopen("ToBeTran.data","r");
    printf("\n\n����������ݣ�\n");
    char str[maxn];
    while(fscanf(infile,"%s",str)!=EOF)
        printf("%s ",str);

    printf("\n���������\n");
    while(fscanf(outfile,"%s",str)!=EOF)
        printf("%s ",str);

    printf("\n\n���������ݣ�\n");
    infile=fopen("CodeFile.data","r");
    while(fscanf(infile,"%s",str)!=EOF)
        printf("%s ",str);

    printf("\n��������\n");
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
    Init(hc);//��ʼ��
    HuffmanTree(hc,tree,alpha);//���� 
    printf("ÿ����ĸ��Ӧ�Ĺ�������������:\n");
    for(int i=0;i<alpha;i++)
    printf("%c  %s\n",hc[i].data,hc[i].code);
    EnCodeing(hc);//����
    DeCodeing(hc);//����
    OutPut();//������
    return 0;
}



