#include <bits/stdc++.h>
#define MAXSIZE 10001
using namespace std;
int a[MAXSIZE];
int BinarySearch(int a[], int n, int k)
{
    int L = 0;
    int R = n - 1;
    int flag = 0;
    while (L <= R)
    {
        int mid = L + (R - L) / 2;
        if (a[mid] == k)
        {
            flag = 1;
            break;
        }
        else if (a[mid] > k)
        {
            R = mid - 1;
        }
        else
            L = mid + 1;
    }
    return flag;
}
int main()
{
    int n, m, flag = 0, i;
    cout << "请输入要查找的数字m及数组长度n：";
    cin >> m >> n;
    cout << "请输入数组元素:";
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n); //排序库函数
                    // I）sort函数包含在头文件为#include<algorithm>的c++标准库中
                    //II）sort函数有三个参数：
                    //形式：sort(first_pointer,first_pointer+n,cmp)
                    //bool cmp（int a，int b）
                    //{
                    //	return a>b;//降序
                    //  return a<b;//升序
                    //}
                    //（1）第一个是要排序的数组的起始地址。
                    //（2）第二个是结束的地址（最后一位要排序的元素地址+1即n）
                    //（3）第三个参数是排序的方法，可以是从大到小也可是从小到大，还可以不写第三个参数，此时默认的排序方法是从小到大排序。
    for (i = 0; i < n; ++i)
    {
        int k = m - a[i];
        if (BinarySearch(a, n, k))
        {
            flag = 1;
            if (a[i] == k && a[i] == a[i + 1]) //注意两个数相等，并且和刚好为m的情况，此时只需要输出一组数据即可
            {
                cout << a[i] << " " << k << endl;
                break; //两个数相等，并且和为m，则这个数后面的数字和如果要等于m，肯定比m大的，直接跳出循环
            }
            if (a[i] >= m / 2)
                break; //判断是否全找完，当a[i]>=m/2时，表示往后的元素的和要等于m，则必为与前面元素重复，
            //也就么有继续遍历数组的必要了
            cout << a[i] << " " << k << endl;
        }
    }
    if (!flag)
        cout << "Can't Found！" << endl;
    return 0;
}

//还可以这样做
//利用排序好的数组，每个元素只对应了一个元素与它和为m
//因此可以从两边同时遍历数组向中间逼近，最后找到和为m的元素直接输出
#include<bits/stdc++.h>
#define MAXSIZE 10001
using namespace std;
int a[MAXSIZE];
int main()
{
	int n,m;
	cout<<"请输入要查找的数字m及数组长度n：";
	cin>>m>>n;
	cout<<"请输入数组元素:"; 
	for(int i=0;i<n;i++){
		cin>>a[i];
		}
	sort(a,a+n);//同上 
	int i=0;
	int j=n-1;
	int flag = 0;
	while(i<j)//不能加等号，否则会出现输出m/2的情况
	{
		int k=a[i]+a[j];
		if(k==m)
		{
			cout<<a[i++]<<" "<<a[j--]<<endl;//相等时i和j要更新否则会一直循环 
			flag=1;
		 } 
		else if(k>m)//说明a[j]太大了 
			j--;
		else 
			i++; 
	}	
	if(!flag){ 
		cout<<"Can't Found！"<<endl;
		} 
		return 0;
