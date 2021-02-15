/*��Ϊ��ϡ��ͼ�����Դ洢��ʽ�ĳ��ڽӱ���ʽ
���ذ汾����Ϊÿ��Ҫ����С���������Կ����ö�ȥ�Ż���n^2�Ż���n��m�Ż���mlogn
����Ϊ�޸Ķ���Ԫ�ص�ʱ�临�Ӷ���logn��������ʱ�临���� O(mlogn), n ��ʾ������m ��ʾ������
�Ƚ��ʺ�ϡ��ͼ��Ҳ���Ǳ����϶��ͼ�����������O(n)��һ������
�ѿ����Լ�ʵ�֣���˫ӳ�䷽ʽ֧���޸Ķ������κ�һ��Ԫ�أ���ʼ�ձ��ֶ�����n��Ԫ�أ����ϸ���
Ҳ������stl�����ȶ��У������ȶ��в�֧���޸��κ�һ��Ԫ�أ�
����ÿ���޸Ķ������������һ���µ��������Զ�����m��Ԫ�أ�����ʱ�临�Ӷ���mlogm��
��mһ�㶼С��n^2�����Դ���ȥ��ʱ�临�Ӷȿ��Կ���mlogn�����������л���ںܶ����࣬
��Ӧһ���㣬���ܻ��кü�������ǰ��ľ��룬��˱��������У�
��ǰ�Ѿ��ҵ�����Сֵ����֮ǰ�Ѿ�ȷ�����ˣ�������st�����ж�һ�¾���

���Ż���dijkstra  Ҳ������spfaȥ��һ�㣬һ�㶼��ͨ��
ʱ�临�Ӷ�O(mlogn), n��ʾ������m��ʾ����
*/
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> PII; //���д洢ÿ����ľ���ͱ��

const int N = 1e6 + 10;

int n, m;                         // �������
int h[N], w[N], e[N], ne[N], idx; // �ڽӱ�洢���б�
int dist[N];                      // �洢���е㵽1�ŵ�ľ���
bool st[N];                       // �洢ÿ�������̾����Ƿ���ȷ��
void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}
/ ��1�ŵ㵽n�ŵ����̾��룬��������ڣ��򷵻� - 1 int dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> heap; //��֤��С����
    heap.push({0, 1});
    // �ȷ�����֪��̾����1�ŵ㣬first�洢���룬second�洢�ڵ���
    while (heap.size())
    {
        auto t = heap.top();
        heap.pop();

        int ver = t.second, distance = t.first;

        if (st[ver])
            continue; //˵����ǰ����������࣬����
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
        add(a, b, c);//�����ڽӱ���˵���ر�������ν��
    }

    cout << dijkstra() << endl;

    return 0;
}
