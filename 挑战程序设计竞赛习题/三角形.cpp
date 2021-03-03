/*
��Ŀ�ܼ򵥣���������һ����n����ʾ����������һ����n��Ԫ�ص����У���ΪһЩ��ĳ��ȣ�Ȼ����ѡ���еİ�����ܳ���������Σ�����������ܳ���
input
5
2 3 4 5 10
 
output

#include <iostream>
using namespace std;
const int MAX_N = 101;
int n, a[MAX_N];
void solve()
{
    int ans = 0; //��
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            for (int k = j + 1; k < n; k++)
            {
                int len = a[i] + a[j] + a[k];
                int ma = max(a[i], max(a[j], a[k]));
                int rest = len - ma;
                if (ma < rest)
                {
                    ans = max(ans, len);
                }
            }
    printf("%d\n", ans);
}
*/
#include <iostream>
#include <algorithm>
#include <cstdlib>
const int N = 105;
using namespace std;
int a[N];
int main(void)
{
    int n, i = 0, n1, ans = 0;
    cin >> n;
    n1 = n;
    while (n1--)
        cin >> a[i++];
    sort(a, a + n);
    for (int j = n - 1; j >= 0; j++)
    {
        if (a[j] < a[j - 1] + a[j - 2])
        {
            ans = a[j] + a[j - 1] + a[j - 2];
            break;
        }
    }
    cout << ans;
}