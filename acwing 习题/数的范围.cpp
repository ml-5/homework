#include <iostream>
using namespace std;
const int N = 10010;
int n, m;
int q[N];
int main(void)
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &q[i]);
    while (m--)
    {
        int x;
        scanf("%d", &x);
        int l = 0, r = n - 1;
        while (l < r) //下界
        {
            int mid = l + r >> 1;
            if (q[mid] >= x)
                r = mid;
            else
                l = mid + 1;
        }
        if (q[l] != x)
            cout << "-1 -1" << endl;
        else //上界
        {
            cout << l << " ";
            l = 0, r = n - 1;
            while (l < r)
            {
                int mid = l + r + 1 >> 1;
                if (q[mid] >= x)
                    r = mid - 1;
                else
                    l = mid;
            }
            cout << l << endl;
        }
    }
    return 0;
}
