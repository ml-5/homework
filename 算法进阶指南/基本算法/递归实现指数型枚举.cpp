/*
�� 1~n��n�����������ѡ��������������еĿ��ܷ���
*/
#include <iostream>
#include <vector>
using namespace std;
int n=6;
vector<int> chosen;
void calc(int x)
{
    if (x == n + 1)
    {
        for (auto x : chosen)
            cout << x;
        puts("");
        return;
    }
    calc(x + 1);         //��������ⲻѡx
    chosen.push_back(x); //��¼x�ѱ�ѡ��
    calc(x + 1);
    chosen.pop_back(); //���ݣ���ԭ�ֳ�
}
int main()
{
    calc(1);
}
