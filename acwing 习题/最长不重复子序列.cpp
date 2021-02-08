#include <iostream>
using namespace std;
const int N = 100010;
int a[N], b[N];
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        int res = 0;
    for (int i = 0, j = 0; j < n; j++)
    {
        s[a[i]]++;
        while(s[a[i]>1)
        {
            s[a[j]]--;
            j++;
        }
        res = max(res, i - j + 1);
    }
    cout << res << endl;
}
