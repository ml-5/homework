

/*1.读入输入。将每次读入的 x c push_back()到add中，将每次读入位置的x push_back() alls中，将每次读入的 l r push_back()到query中
2.排序去重
3.通过遍历 add，完成在离散化数组映射到a数组中进行加上c的操作
4.初始化 s数组
5.通过遍历 query 完成区间求和 l，r */

#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
typedef pair<int, int> PII;
const int N = 300010;
int n,m;
int a[N], s[N];
vector<int> alls;
vector<PII> add, query;
int find(int x)
{
    int l = 0, r = alls.size() - 1;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (alls[mid] >= x)
            r = mid;
        else
            l = mid + 1;
    }
    return r + 1;
}
int main(void)
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int x, c;
        cin >> x >> c;
        add.push_back({x, c});
        alls.push_back(x);
    }
    for (int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;
        query.push_back({l, r});
        alls.push_back(l);
        alls.push_back(r);
    }
    //去重
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());
    //预处理插入
    for (auto item : add)
    {
        int x = find(item.first);
        a[x] += item.second;
    }
    //预处理前缀和
    for (int i = 1; i < alls.size(); i++)
        s[i] = s[i - 1] + a[i];
    for (auto item : query)
    {
        int l = find(item.first), r = find(item.second);
        cout << s[r] - s[l - 1] << endl;
    }
    return 0;
}