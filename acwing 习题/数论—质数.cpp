/*
����(����)��ָ�ڴ���1����Ȼ���У�����1�����������ⲻ������������(Լ��)����Ȼ��
1.�ϸ����1��������ڵ���2
2.����1������֮��û������������Ҳ����ֻ��������������
//���� O(n)
bool is_prime(int x)
{
    if (x < 2) return false;//�ϸ����1
    for (int i = 2; i < x; i ++ )//��2��n-1�д���ĳ������x����
        if (x % i == 0)
            return false;
    return true;
}
*/
#include <iostream>
using namespace std;
//�Ż� ÿ������Լ�����ǳɶԳ��֣����i��n��Լ������n/iҲ��n��Լ��
bool is_prime(int x)
{
    if (x < 2) return false;
/*
����ö��ÿһ��Լ���н�С���Ǹ������ɣ���С��Լ���ķ�Χ��1������n(��2��ʼö��)
Ҳ����������⣬��С����ö��ÿ��������Լ��������ѭ�����������������Լ������
С��������Ե��Ǹ�Լ��
i<=sqrt(x)���Ƽ�����Ϊÿ�ζ�Ҫִ����������Ĳ���
i*i<=nҲ���Ƽ�����n����ӽ�int���ֵʱ��i*i���������ɸ���
ʱ�临�Ӷ�sqrt(n)
*/
    for (int i = 2; i <= x / i; i ++ )
        if (x % i == 0)
            return false;
    return true;
}

int main()
{
    int n;
    cin >> n;

    while (n -- )
    {
        int x;
        cin >> x;
        if (is_prime(x)) puts("Yes");//����һ���
        else puts("No");
    }

    return 0;
}