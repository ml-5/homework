#include <iostream>
#include <algorithm>
using namespace std;
// (a,b)==(b,a mod b)==(b,a - (a/b)*b)
// d能整除a，能整除b，则d也能整除a-c*b
// d能整除b，能整除a-c*b，则d也能整除能整除a-c*b+c*b==a
int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        cout << gcd(a, b) << endl;
    }

    return 0;
}