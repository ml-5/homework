/*
ջ���Ƚ����
���У��Ƚ��ȳ�
*/
#include <iostream>
using namespace std;
const int N = 100010;

int m, stk[N], tt; //ttʼ��ָ��ջ�����һ����ȥ�����ȳ�����Ԫ��
//���룺stk[++tt]=x
//ɾ����tt--
//�ж��Ƿ�Ϊ�գ�tt>0
//ջ����stk[tt]

int main()
{
    cin >> m;
    while (m--)
    {
        string op;
        int x;

        cin >> op;
        if (op == "push")
        {
            cin >> x;
            stk[++tt] = x;
        }
        else if (op == "pop")
            tt--;
        else if (op == "empty")
            cout << (tt ? "NO" : "YES") << endl;
        else
            cout << stk[tt] << endl;
    }

    return 0;
}