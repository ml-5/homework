/*#include <iostream>
using namespace std;
const int MAX_N = 50;
int main()
{
    int n, m, k[MAX_N];
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> k[i];
    bool f = false;
    for (int a = 0; a < n; a++)
        for (int b = 0; b < n; b++)
            for (int c = 0; c < n; c++)
                for (int d = 0; d < n; d++)
                {
                    if (k[a] + k[b] + k[c] + k[d] == m)
                        f = true;
                    break;
                }
    if (f)
        puts("Yes");
    else
        puts("No");
}


ka+kb+kc+kd=m;
kd=m-ka-kb-kc;

#include <iostream>
using namespace std;
int n, m, k[MAX_N];
bool binary_search(int x)
{
    int l = 0, r = n - 1;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (k[i] == x)
            return true;
        else if (k[i] < x)
            l = mid + 1;
        else
            r = mid;
    }
}

void solve()
{
    sort(k, k + n);
    bool f = false;
    for (int a = 0; a < n; a++)
        for (int b = 0; b < n; b++)
            for (int c = 0; c < n; c++)
            {
                if (binary_search(m - k[a] - k[b] - k[c]))
                {
                    f = true;
                }
            }
    if (f)
        puts("Yes");
    else
        puts("No");
}

O(n^2logn)

int n,m,k[MAX_N];
int kk[MAX_N*MAX_N];
bool binary_search(int x)
{

}
void solve()
{
    for(int c=0;c<n;c++)
    {
        for(int d=0;d<n;d++)
        {
            kk[n*c+d]=k[c]+k[d];
        }
    }
     for (int a = 0; a < n; a++)
        for (int b = 0; b < n; b++)
        if(binary_search(m-k[a]-k[b]))
        f=true;
}

*/

