/*
栈：先进后出
队列：先进先出
*/
#include <iostream>
using namespace std;
const int N = 100010;

int m, stk[N], tt; //tt始终指向栈中最后一个进去，最先出来的元素
//插入：stk[++tt]=x
//删除：tt--
//判断是否为空：tt>0
//栈顶：stk[tt]

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