/**���⣺�� [��ʽ] �����ֳ� [��ʽ] �飬��ÿһ��͵���Сֵ���

��⣺���ִ�������Сֵ����ͨ����·�����Ƕ��������Сֵ���Ȼ��ȥ���ܲ��������ӷ�  [��ʽ] �鼴��
**/
#include <cstdio>
#include <algorithm>
#define N 100100
using namespace std;
int n, m, a[N];
inline bool check(int mid)
{
    int sum = 0, cnt = 0;
    for (int i = 0; i <= n; i++)
    {
        sum += a[i];
        if (sum > mid)
        {
            sum = a[i];
            ++cnt
        }
    }
    return cnt < m;
}
