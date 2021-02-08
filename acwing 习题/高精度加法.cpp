#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<int> add(vector<int> &A, vector<int> &B)
{
    int t=0;
    vector<int> C;
    if(A.size()<B.size()) return add(B,A);
    for (int i = 0; i < A.size(); i++)
    {
            t += A[i];
        if (i < B.size())
            t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }
    if(t) C.push_back(1);
    return C;
}
int main()
{
    string a, b;
    vector<int> A, B;
    cin >> a >> b; //a="123456"
    for (int i = a.size() - 1; i >= 0; i--)
        A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i--)
        B.push_back(b[i] - '0');
    auto C = add(A, B);
    for (int i = C.size() - 1; i >= 0; i--)
        printf("%d", C[i]);
    return 0;
}