#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    string a, b;
    cin >> a >> b;
    vector<int> a1;
    vector<int> b1;
    vector<int> c1;
    for (int i = a.size() - 1; i >= 0; i--)
        a1.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i--)
        b1.push_back(b[i] - '0');
    int t = 0;
    for (int i = 0; i < max(a1.size(), b1.size()); i++)
    {
        if (i < a1.size())
        {
            t += a1[i];
        }
        if (i < b1.size())
        {
            t += b1[i];
        }
        c1.push_back(t % 10);
        t /= 10;
    }
    for(int i=c1.size()-1;i>=0;i--)
    cout<<c1[i];
}