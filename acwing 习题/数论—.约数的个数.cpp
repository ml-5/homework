/*
如果 N = p1^c1 * p2^c2 * ... *pk^ck
约数个数： (c1 + 1) * (c2 + 1) * ... * (ck + 1)
约数之和： (p1^0 + p1^1 + ... + p1^c1) * ... * (pk^0 + pk^1 + ... + pk^ck)
*/
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long LL;

const int N = 110, mod = 1e9 + 7;

int main()
{
    int n;
    cin >> n;

    unordered_map<int, int> primes;

    while (n--)
    {
        int x;
        cin >> x;

        for (int i = 2; i <= x / i; i++)
            while (x % i == 0)
            {
                x /= i;
                primes[i]++;
            }

        if (x > 1)
            primes[x]++;
    }

    LL res = 1;
    for (auto p : primes)
        res = res * (p.second + 1) % mod; //(c1 + 1)

    cout << res << endl;

    return 0;
}