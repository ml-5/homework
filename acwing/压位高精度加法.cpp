/*
压9位的意思是:将高精度转化为数组，数组中的每个数存储9位
这样的数组的长度会缩小到原来的1/9，数组里每一个存0-9
*/
#include <iostream>
#include<vector>
using namespace std;
const int base = 1e9;
vector<int> add(vector<int> &A, vector<int> &B)
{
    if (A.size() < B.size())
        return add(B, A);
    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size(); i++)
    {
        t += A[i];
        if (i < B.size())
            t += B[i];
        C.push_back(t % base);
        t /= base;
    }
    if (t)
        C.push_back(t);
    return C;
}
int main()
{
    string a, b;
    vector<int> A, B;
    cin >> a >> b;
    for (int i = a.size() - 1, s = 0, j = 0, t = 1; i >= 0; i--)
    { //数组中每个数存储9位
        s += (a[i] - '0') * t;
        j++, t *= 10;
        if (j == 9 || i == 0)
        {
            A.push_back(s);
            s = j = 0;
            t = 1;
        }
    }
    for (int i = b.size() - 1, s = 0, j = 0, t = 1; i >= 0; i--)
    {
        s += (b[i] - '0') * t;
        j++, t *= 10;
        if (j == 9 || i == 0)
        {
            B.push_back(s);
            s = j = 0;
            t = 1;
        }
    }
    auto C = add(A, B);
    cout << C.back(); //先输出第一个数
    for (int i = C.size() - 2; i >= 0; i--)
        printf("%09d", C[i]);
    return 0;
}