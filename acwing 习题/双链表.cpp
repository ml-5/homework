#include <iostream>
using namespace std;
const int N = 1e5 + 10;
// e[]表示节点的值，l[]表示节点的左指针，r[]表示节点的右指针
//idx是下标，表示当前可以从哪儿开始分配新节点
//不定义头节点的下标head，下标0,1表示左右端点
int e[N], l[N], r[N], idx;

// 初始化
void init()
{
    //0是左端点，1是右端点，用来处理边界条件
    r[0] = 1, l[1] = 0;
    idx = 2;
    //这里注意第一个输入的节点所分配的下标是2，所以第i个输入的点，下标为i+1
}

// 在下标为a的节点的右边插入一个值为x的节点
//这里是在右边插入一个节点，如果题目要求在左边插入一个值为x的节点
//则等同于在下标的l[a]的节点右边插入一个值为x的节点
void insert(int a, int x)
{
    e[idx] = x; //创建新节点
    l[idx] = a, r[idx] = r[a];
    //新节点左右指针指向创建的先后顺序没有任何影响，lr是为了下面先l后r对齐
    l[r[a]] = idx, r[a] = idx++;
    //原链表中节点指向要特别注意，它可以被很多节点指向
    //但他自己一边只能指向一个节点，所以这里先l再r（先不确定的点，再确定的点）
    //最后注意更新idx
}

// 删除下标为a的节点
void remove(int a)
{
    l[r[a]] = l[a];
    r[l[a]] = r[a];
}

int main()
{
    int m;
    cin >> m;

    // init();//注意链表记得初始化
    l[1] = 0, r[0] = 1;
    idx = 2;

    while (m--)
    {
        string op;
        int k, x;

        cin >> op;
        if (op == "L")
        {
            cin >> x;
            insert(0, x);
            //在链表最左端插入一个节点，代表在左端点也就是下标为0的右边插入一个值为x的节点
        }
        else if (op == "R")
        {
            cin >> x;
            insert(l[1], x);
            //在链表最右端插入一个节点，代表在右端点也就是下标为1的左边插入一个值为x的节点
            //也就是在下标为l[1]的节点的右边插入一个值为x的节点
        }
        else if (op == "D")
        {
            cin >> k;
            remove(k + 1);
        }
        else if (op == "IL")
        {
            cin >> k >> x;
            insert(l[k + 1], x);
        }
        else
        {
            cin >> k >> x;
            insert(k + 1, x);
        }
    }

    for (int i = r[0]; i != 1; i = r[i])
        cout << e[i] << ' ';
    cout << endl;
    return 0;
}