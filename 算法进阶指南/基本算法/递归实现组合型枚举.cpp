/*
��1~n��n�����������ѡȡm��,������еĿ��ܵ�ѡ��
����
*/
#include <iostream>
#include <vector>
using namespace std;
int n = 10;
int m = 2;
vector<int> chosen;
void calc(int x)
{
    if (chosen.size() > m || chosen.size() + (n - x + 1) < m)
        return;
    if (x == n + 1)
    {
        for (int i = 0; i < chosen.size(); i++)
            cout << chosen[i];
        puts("");
        return;
    }
    calc(x + 1);         //���������
    chosen.push_back(x); //��¼x�ѱ�ѡ��
    calc(x + 1);         //���������
    chosen.pop_back();   //���ݣ���ԭ�ֳ�
}
int main()
{
    calc(1);
}
