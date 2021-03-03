/*
’“”≤±“Œ Ã‚

*/
#include <iostream>
using namespace std;
const int V[6] = {1, 5, 10, 50, 100, 500};
int C[6];
int A;
void slove()
{
    int ans = 0;
    for (int i = 5; i > 0; i--)
    {
        int t = min(A / V[i], C[i]);
        A -= t * V[i];
        ans += t;
    }
    cout << ans << endl;
}
