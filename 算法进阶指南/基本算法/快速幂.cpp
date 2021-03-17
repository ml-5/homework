/*32Î»¿ìËÙÃİ
*/
#include <iostream>
using namespace std;
typedef  long long ll;
ll qmi(int a, int b, int p)
{
    // long long ans = 1;
    // for (; b; b >>= 1)
    // {
    //     if (b & 1)
    //         ans = ans * a % p;
    //     a = a * a % p;
    // }
    // return ans;
    ll ans=1;
    while(b)
    {   if(b&1)
        ans=ans*a%p;
        b>>=1;
        a=a*a%p;
    }
    return ans;
}
int main()
{
    cout<<qmi(11,12345,12345);
}