/*
序列a中每个元素能否顺次映射到b
从前往后扫描数组b，每次扫描时，查看数组b中当前数与数组a中当前数是否一样
如果一样，此时a[i]与b[j]匹配，i++
总之就是在数组b中一个一个找与a[i]相匹配的元素，匹配成功就i++
*/
#include <iostream>

using namespace std;

const int N = 100010;

int n, m;
int a[N], b[N];

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];

    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (a[i] == b[j])
            i++;
        j++;
    }

    if (i == n)
        puts("Yes");
    else
        puts("No");

    return 0;
}