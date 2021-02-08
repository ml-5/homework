/*
注意最后两个操作是删除或修改第k个插入的元素(这里与单链表双链表中类似)
所以还需要快速找到第k个插入的元素
开额外两个数组
*/
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100010;
int h[N], ph[N], hp[N], cnt;
/*
ph[k]存的是第k个插入的元素在堆中的下标
hp[k]存的是堆中下标是k的节点是第几个插入的点
之前操作的时候，不涉及到第几个插入，所以仅交换值就行，而这里不行，
交换时候需要知道两个节点各自是第几个插入的节点，然后再把把第几个插入的元素在堆中的下标改变
*/

void heap_swap(int a, int b)
{
    swap(ph[hp[a]], ph[hp[b]]);
    swap(hp[a], hp[b]);
    swap(h[a], h[b]);
}

void down(int u)
{
    int t = u;
    if (u * 2 <= cnt && h[u * 2] < h[t])
        t = u * 2;
    if (u * 2 + 1 <= cnt && h[u * 2 + 1] < h[t])
        t = u * 2 + 1;
    if (u != t)
    {
        heap_swap(u, t);
        down(t);
    }
}

void up(int u)
{
    while (u / 2 && h[u] < h[u / 2])
    {
        heap_swap(u, u / 2);
        u >>= 1;
    }
}

int main()
{
    int n, m = 0; //m表示第几个插入的元素
    cin >> n;
    while (n--)
    {
        string op;
        int k, x;
        cin >> op;
        if (op == "I")
        {
            cin >> x;
            cnt++;
            m++;
            ph[m] = cnt, hp[cnt] = m;
            h[cnt] = x;
            up(cnt);
        }
        else if (op == "PM")
            cout << h[1] << endl;
        else if (op == "DM")
        {
            heap_swap(1, cnt);
            cnt--;
            down(1);
        }
        else if (op == "D")
        {
            cin >> k;  //此时的k是第k个插入
            k = ph[k]; //现在的k是第k个插入的元素在堆中的下标
            heap_swap(k, cnt);
            cnt--;
            up(k);
            down(k);
        }
        else
        {
            cin >> k >> x;
            k = ph[k];
            h[k] = x;
            up(k);
            down(k);
        }
    }

    return 0;
}