#include <iostream>
using namespace std;
const int MAX = 1e3 + 10;
int N, R;
int x[MAX];
void solve()
{
    sort(x, x + N);
    int i = 0, ans = 0;
    while (i < n)
    {
        int s = x[i++];
        //һֱ����ǰ��ֱ����s����r�ĵ�
        while (i < N && x[i] <= s + R)
            i++;
        //p���¼��ϱ�ǵĵ��λ��
        int p = x[i - 1];
        while (i < N && x[i] <= p + R)
            i++;
        ans++;
    }
    cout << ans;
}
int main()
{
    cin >> N >> R;
    for (int i = 0; i < N; i++)
        cin >> x[i];
    slove();
    return 0;
}