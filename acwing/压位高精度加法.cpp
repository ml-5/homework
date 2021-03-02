/*
ѹ9λ����˼��:���߾���ת��Ϊ���飬�����е�ÿ�����洢9λ
����������ĳ��Ȼ���С��ԭ����1/9��������ÿһ����0-9
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
    { //������ÿ�����洢9λ
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
    cout << C.back(); //�������һ����
    for (int i = C.size() - 2; i >= 0; i--)
        printf("%09d", C[i]);
    return 0;
}