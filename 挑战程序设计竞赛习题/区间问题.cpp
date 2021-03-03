/*
区间调度问题
策略：每次选取结束时间最早的
*/
#include <iostream>
using namespace std;
const int MAX_N = 1e6;
int N, S[MAX_N], T[MAX_N];
pair<int, int> itv[MAX_N];
void solve()
{
    for (int i = 0; i < N; i++)
    {
        itv[i].first = T[i];
        itv[i].second = S[i];
    }
    sort(itv, itv + N);
    int ans = 0, t = 0;
    for (int i = 0; i < N; i++)
        for (t < itv[i].second)
        {
            ans++;
            t = itv[i].first;
        }
    cout << ans << endl;
}