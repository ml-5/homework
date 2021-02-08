#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int N, K;
const int MAXN = 1e5;
int visited[MAXN + 10]; //���ر��
struct Step
{
    int x;    //λ��
    int step; // ��������Ҫ�Ĳ���
    Step(int xx, int s)::x(xx), steps(s) {}
};
queue<Step> q; //����
int main()
{
    cin >> N >> K;
    memset(visited, 0, sizeof(visited));
    q.push(step(N, 0));
    visited[N] = 1;
    while (!q.empty())
    {
        Step s = q.front();
        if (s.x == k)
        {
            cout << s.step << endl;
            return 0;
        }
        else
        {
            if (s.x - 1 >= 0 && !visited[s.x - 1])
            {
                q.push(Step(s.x - 1, s.steps + 1));
                visited[s.x - 1] = 1;
            }
            if (s.x + 1 <= MAXN && !visited[s.x + 1])
            {
                q.push(Step.(s.x + 1, s.steps + 1));
                visited[s.x + 1] = 1;
            }
            if (s.x * 2 <= MAXN && !visited[s.x * 2])
            {
                q.push(Step(s.x * 2, s.step + 1));
                visited[s.x * 2] = 1;
            }
            q.pop();
        }
    }
    return 0;
}

/**�����������(Breadth First Search, BFS)
�Ƕ�����������������˵���Ƕ����ĺ��������bfs��äĿ�ġ�

    bfs�����������ﵽĳĿ������� ���ٲ�����������poj3278������������Ȼ��n��k��ÿһ�����ƶ������ֿ��ܣ�n +
    1��n - 1��n * 2���ʣ���n����������k����Ҫ����С�ƶ��������ٸ����ӣ�n = 5��k = 17����bfs�������£� �� ���� ��Ҫ˵���� 1.ע���ɫ�Ĳ棬�����������п��ܲ����Ѿ��������Ľڵ㣬��ʱҪ������ 2.�Ѿ���������i��Ľڵ㣬��ô��i +
                                                                                  1����������ĸ��ڵ㿪ʼ����ʱ��Ҫ����һ�����У�i���Ѿ��������Ľڵ���ӣ��ڶԵ�i - 1��Ľڵ�ֲ�ʱ����Ȼ��������Ϊ��i + 1��ڵ�ĸ��ڵ���ӡ�

                                                                                  �����Ǵ��룺 int step[MAX]; //���ʵ�ָ���ڵ�����Ĳ���
bool visited[MAX];                                                                                            //ָ���ڵ��Ƿ��ѱ�����
queue<int> bfstree;                                                                                           //�ѷ��ʵĽڵ���ӣ���������Ҫ���ʵ���һ��ڵ�

memset(visited, false, sizeof(visited)); //��ʼʱ�����нڵ㶼δ������

int bfs()
{
    int head, next;

    visited[n] = 1;  //��һ���ڵ㱻����
    step[n] = 0;     //��Ҫ0�������һ���ڵ�
    bfstree.push(n); //���ӣ�����������һ��

    while (!bfstree.empty())
    {
        head = bfstree.front();
        bfstree.pop();

        //���ڵ���������֧
        for (int i = 0; i < 3; ++i)
        {
            if (i == 0)
                next = head - 1;
            else if (i == 1)
                next = head + 1;
            else
                next = head * 2;

            if (next < 0 || next >= MAX)
                continue; //��ֹ���ʵĽڵ�Խ��

            if (!visited[next]) //�ѷ��ʵĽڵ���Ҫ������
            {
                visited[next] = 1;
                step[next] = step[head] + 1;
                bfstree.push(next);
            }

            if (next == k)
                return step[next];
        }
    }

    return -1;
}
**/