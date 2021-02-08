/*
数组模拟单链表，用struct+指针的方式,每次需要调用new函数动态分配新节点，非常慢
    -单链表:用的最多的是邻接表
    -双链表:优化某些问题
    两个数组:e[N],ne[N]表示每个节点的值和下一个节点的位置，空节点下标用-1表示
*/
#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int head, e[N], ne[N],idx;
/*
head表示当前链表此时头结点的下标
e[]存储每个节点的值，下标表示当前节点的下标，数组中存储的是当前节点的值
ne[]存储每个节点的next指针，e和ne数组用下标关联
下标表示当前节点的下标，数组中存储的是当前节点的所指向下一个节点的下标
idx是下标，表示当前可以从哪儿开始分配新节点
也就是说两个数组中idx这个下标可以用来表示新的节点的值和next指针
*/
// 初始化
void init()
{
    head = -1; //空节点用-1表示
    idx = 0;   //当前可以从下标0开始分配新节点
}

// 在链表头插入一个值为a的节点
void add_to_head(int a)
{ /*
    e[idx] = a; 创建新节点
    ne[idx] = head; 令新节点指向当前链表此时的头结点
    head = idx ++ ; 更新当前链表头结点的下标和idx
    */
    e[idx] = a, ne[idx] = head, head = idx++;
}
/*
将值为x的节点插到下标是k的点后面
注意下标为k，则对应节点的下标就是k，所以如果题目中的描述是第k个输入，第k个插入的
节点的话，这个节点对应的下标是k-1
*/
void add(int k, int x)
{
    e[idx] = x, ne[idx] = ne[k], ne[k] = idx++;
}
// 将下标是k的点后面的点删掉，一定注意题目中所描述的节点的下标
void remove(int k)
{
    ne[k] = ne[ne[k]];
}
int main()
{
    int m;
    cin >> m;

    init();
    // head=-1;
    // idx=0;

    while (m--)
    {
        char op;
        int x, k;

        cin >> op;
        if (op == 'H')
        {
            cin >> x;
            add_to_head(x);
            // e[idx]=x;
            // ne[idx]=head;
            // head=idx++;
        }
        else if (op == 'D')
        {
            cin >> k;
            if (!k)
                head = ne[head];
            else
            {
                remove(k - 1);
                // ne[k-1]=ne[ne[k-1]];
            }
        }
        else
        {
            cin >> k >> x;
            add(k - 1, x);
            // e[idx]=x;
            // ne[idx]=ne[k-1];
            // ne[k-1]=idx++;
        }
    }

    for (int i = head; i != -1; i = ne[i])
        cout << e[i] << ' ';
    cout << endl;
    return 0;
}