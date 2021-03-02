#include <iostream>
using namespace std;
double x;
int main()
{
    cin >> x;
    doubel l = 0, r;
    if (x > 1)
        r = x;
    else
        r = 1;
    while (r - l > 1e-8)
    {
        double mid = (l + r) >> 1;
        if (mid * mid >= x)
            r = mid;
        else
            l = mid;
    }
    printf("%.6f %.6f", l, l);
    return 0;
}