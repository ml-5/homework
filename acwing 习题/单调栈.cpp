/*1.视野总和
2.柱状图中最大的矩形



给定一个长度为N的整数数列，输出每个数左边第一个比它小的数，如果不存在则输出-1
暴力做法 时间复杂度O(n^2)
int main(){
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    cout<<-1<<' ';//数组第一个元素对应的输出一定是-1
    for(int i=1;i<n;i++)//从数组中下标为1，第二个元素开始遍历
        for(int j=i-1;j>=0;j--)//内层循环遍历外层遍历的数之前的所有数
            if(a[j]<a[i]){
                cout<<a[j]<<' '; 
                break;
            }
            else if(j==0){
                cout<<-1<<' '; 
            }
    return 0;
}
优化 如果i<j且a[i]>=a[j]则a[i]一定不会作为j后面的元素的答案输出
单调栈：遍历每个元素，入栈并保证栈的单调递减/增的性质
常见模型：找出每个数左边第一个比它大/小的数
int tt = 0;
for (int i = 1; i <= n; i ++ )//可变
{
    while (tt && check(stk[tt], i)) tt -- ;
    stk[ ++ tt] = i;
}
时间复杂度 O(n)，因为每个元素一定会入栈一次，可能会出栈一次，总体来看是n级别
*/

#include <iostream>
using namespace std;

const int N = 100010;
int stk[N], tt;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        /*
找每个数左边第一个比它小的元素，所以是单调递增栈
如果求左边第一个比它大的元素，stk[tt]>=x改成<,仅此
每个元素入栈时必须保证它是栈中最大的元素，栈中不能有元素比它更大
所以删除之前单调栈栈顶元素的循环条件是栈非空并且栈顶元素大于等于它
*/
        while (tt && stk[tt] >= x)
            tt--;
        if (!tt)
            cout << -1 << ' ';
        else
            cout << stk[tt] << ' ';
        //因为当前元素对应的输出一定是之前的某个数，所以一定要先输出栈顶元素再入栈
        stk[++tt] = x;
    }

    return 0;
}