/**��һ��������󣬾���߽�������Զ�������������¼��裺
a.ÿ��һ��ʱ��ֻ�ܴӵ�ǰ�����ƶ�һ���ߵ�ĳ�����ڵķ����ϣ�
b. �߹��ĸ������������޷����ߵڶ��Σ�
c. ֻ���򱱡����������������ߣ�
���ʣ���������ڷ����������n��(n<=20)�����ж����ֲ�ͬ�ķ�����
2���߷�ֻҪ��һ����һ����������Ϊ�ǲ�ͬ�ķ�����
˼·��
�ݹ�
�� (i,j) ��������n���ķ�������������������֮�ͣ�
��(i+1,j)��������n-1���ķ�������ǰ�᣺(i+1,j)��û�߹�
��(i,j+1)��������n-1���ķ�������ǰ�᣺(i,j+1)��û�߹�
��(i,j-1)��������n-1���ķ�������ǰ�᣺(i,j-1)��û�߹�
**/
#include <iostream>
#include <cstring>
using namespace std;
int visited[30][50];
int ways(int i, int j, int n)
{
    if (n == 0)
        return 1;
    visited[i][j] == 1;
    int num = 0;
    if (!visited[i][j - 1])
        num += ways(i, j - 1, n - 1);
    if (!visited[i][j + 1])
        num += ways(i, j + 1, n - 1);
    if (!visited[i + 1][j])
        num += ways(i + 1, j, n - 1);
    visited[i][j] = 0;
    return num;
}
int main()
{
    int n;
    cin >> n;
    memset(visited, 0, sizeof(visited));
    cout << ways(0, 25, n) << endl;
    return 0;
}