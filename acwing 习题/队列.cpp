#include<iostream>
using namespace std;
const int N=100010;
//�ڶ�β����Ԫ�أ��ڶ�ͷɾ��Ԫ��
int q[N],hh,tt=-1;
//ttΪ0����-1ȡ�����ڶ�β����Ԫ�أ�q[++tt]=xʱ���������Ƿ��Ѿ���Ԫ��
//���룺q[++tt]=x  ��ջһ��
//������hh++ ջ��tt--
//�ж��Ƿ�Ϊ�գ�hh<=tt ջ��tt>0

int main()
{
    int m;
    cin >> m;

    while (m -- )
    {
        string op;
        int x;

        cin >> op;
        if (op == "push")
        {
            cin >> x;
            q[ ++ tt] = x;
        }
        else if (op == "pop") hh ++ ;
        else if (op == "empty") cout <<(hh <= tt ? "NO" : "YES") << endl;
        else cout << q[hh] << endl;
    }

    return 0;
}
