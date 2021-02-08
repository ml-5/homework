#include <iostream>
#include <stdio.h>
#include <algorithm>
#define INF 0X7fffffff
#define maxn 100100
using namespace std;
int a[maxn];
int n, c;
int judeg(int m)
{
    int last = 0;
    for (int i = 1; i < c; i++)
    {
        int cur = last + 1;
        while (cur < n && a[cur] - a[last] < m)
            cur++;
        if (cur == n)
            return 0;
        last = cur;
    }
    return 1;
}
int main()
{
    while (scanf("%d %d", &n, &c) != EOF)
    {
        for (int i = 0; i < n; i++)
            scanf("%d %d", &a[i]);
        sort(a, a + n);
        int l = 0, r = INF, m;
        for (int i = 0; i < 100; i++)
        {
            m = l + (r - l) / 2;
            if (judeg(m))
                l = m;
            else
                r = m;
        }
        printf("%d\n", l);
    }
    return 0;
}
//
#include<stdio.h>  
#include<stdlib.h>
#include<algorithm> 
using namespace std; 
int a[100005],n,c;  
int judge(int mid)  
{  
    int i,count=1,t=a[0]; //count��ָ���˼�ͷţ����1��ʼ��t������ʾ��ǰ�ķ����
    for(i=1;i<n;i++)
	{
		if(a[i]-t>=mid)//�ж���������֮��ľ��� 
		{  
			count++;
			t=a[i];//�޸�t��ֵ�����޸ĵ�ǰ����ţ�����ԭ��t=1,a[2]=4,��a[2]-t>=mid���ϣ���ôt=4,Ȼ����a[3]����a[4]��t֮��ľ��롣  
			if(count>=c)//���Է���Cͷţ  
				return 1;  
		}
	}  
    return 0;
}  
int binary()//��������������������С��������ֵ  
{  
    int low=0,high=a[n-1]-a[0],mid;  
    while(low<=high)  
    {  
        mid=(low+high)/2;//mid��Ϊ��С���������󷿼��֮��ľ���  
        if(judge(mid))  
            low=mid+1; //�������>=mid�����Լ���������̽ 
        else  
            high=mid-1;//�������<mid�����Ա����С����̽  
    }  
    return low-1; //������֮ǰ����+1�����Դ�ʱ-1 
}   
int main()  
{  
    while(~scanf("%d%d",&n,&c))  
    {  
        int i;  
        for(i=0;i<n;i++)  
            scanf("%d",&a[i]);  
        sort(a,a+n);  
        printf("%d\n",binary());  
    }  
    return 0;  
} 
