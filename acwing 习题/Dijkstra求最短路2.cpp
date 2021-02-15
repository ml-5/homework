/*因为是稀疏图，所以存储方式改成邻接表形式
朴素版本，因为每次要找最小的数，所以可以用堆去优化，n^2优化成n，m优化成mlogn
（因为修改堆中元素的时间复杂度是logn），所以时间复杂是 O(mlogn), n 表示点数，m 表示边数，
比较适合稀疏图，也就是边数较多的图，比如边数与O(n)是一个级别
堆可以自己实现，用双映射方式支持修改堆里面任何一个元素，能始终保持堆中有n个元素，但较复杂
也可以是stl的优先队列，但优先队列不支持修改任何一个元素，
它是每次修改都往堆里面插入一个新的数，所以堆中有m个元素，所以时间复杂度是mlogm，
但m一般都小于n^2，所以带进去，时间复杂度可以看成mlogn，但这样堆中会存在很多冗余，
对应一个点，可能会有好几个更新前后的距离，因此遍历过程中，
当前已经找到的最小值可能之前已经确定过了，所以用st数组判断一下就行

堆优化版dijkstra  也可以用spfa去做一般，一般都能通过
时间复杂度O(mlogn), n表示点数，m表示边数
*/
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> PII; //堆中存储每个点的距离和编号

const int N = 1e6 + 10;

int n, m;                         // 点的数量
int h[N], w[N], e[N], ne[N], idx; // 邻接表存储所有边
int dist[N];                      // 存储所有点到1号点的距离
bool st[N];                       // 存储每个点的最短距离是否已确定
void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}
/ 求1号点到n号点的最短距离，如果不存在，则返回 - 1 int dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> heap; //保证是小根堆
    heap.push({0, 1});
    // 先放入已知最短距离的1号点，first存储距离，second存储节点编号
    while (heap.size())
    {
        auto t = heap.top();
        heap.pop();

        int ver = t.second, distance = t.first;

        if (st[ver])
            continue; //说明当前这个点是冗余，跳过
        st[ver] = true;

        for (int i = h[ver]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > distance + w[i])
            {
                dist[j] = distance + w[i];
                heap.push({dist[j], j});
            }
        }
    }
    if (dist[n] == 0x3f3f3f3f)
        return -1;
    return dist[n];
}
int main()
{
    cin>>n>>m;

    memset(h, -1, sizeof h);
    while (m -- )
    {
        int a, b, c;
        cin>>a>>b>>c;
        add(a, b, c);//对于邻接表来说，重边是无所谓的
    }

    cout << dijkstra() << endl;

    return 0;
}
