#include <iostream>
using namespace std;
long long count = 0;
void dfs(int a, int b, int k)
{
    if (a == 16 && b == 16 && k == 32)
    {
        count++;
        return;
    }
    if (a <= 16 && b <= 16 && a >= b && k < 32)
    {
        dfs(a + 1, b, k + 1);
        dfs(a, b + 1, k + 1);
    }
    return;
}
int main()
{
    dfs(1, 0, 1);
    cout << count;
    return 0;
}