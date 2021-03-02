#include <iostream>
using namespace std;
const int N = 100010;
int n, m;
int q[N];
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> q[i];
    while (m--)
    {
        int x;
        cin >> x;
        //二分找到满足>=x这个性质的第一个元素
        int l = 0, r = n - 1;
        while (l < r)
        {
            int mid = (l + r) >> 1;
            if (q[mid] >= x)
                r = mid;
            else
                l = mid + 1;
        }
        //注意可能找不到>=x的第一个元素，全部都比它小
        if (q[l] != x)
            cout << "-1 -1" << endl;
        else
        {
            cout << l << " ";
            int l = 0, r = n - 1;
            while (l < r)
            {
                int mid = (l + r+1) >> 1;
                if (q[mid] <= x)
                    l = mid;
                else
                    r = mid - 1;
            }
            cout << l << endl;
        }
    }
    return  0;
}