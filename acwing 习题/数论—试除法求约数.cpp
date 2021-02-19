#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> get_divisors(int x)
{
    vector<int> res;
    for (int i = 1; i <= x / i; i++)
        //约数成对出现，枚举较小约数即可
        if (x % i == 0)
        {
            res.push_back(i);
            if (i != x / i)
                res.push_back(x / i);
        }
    sort(res.begin(), res.end());
    return res;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        auto res = get_divisors(x);

        for (auto x : res)
            cout << x << ' ';
        cout << endl;
    }

    return 0;
}