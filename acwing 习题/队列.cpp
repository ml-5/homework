#include<iostream>
using namespace std;
const int N=100010;
//在队尾插入元素，在队头删除元素
int q[N],hh,tt=-1;
//tt为0或者-1取决于在队尾插入元素，q[++tt]=x时，队列中是否已经有元素
//插入：q[++tt]=x  和栈一样
//弹出：hh++ 栈是tt--
//判断是否为空：hh<=tt 栈是tt>0

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
