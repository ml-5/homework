/*const ����ָ��
const int *p(����ָ��) pָ������ݲ��ܸ���
int *const p(ָ�볣��) pָ��ĵ�ַ�������޸�
const int *const p (��ָ�볣��)ָ��ָ���ָ������ݶ������޸�
*/
#include <iostream>
using namespace std;
int main()
{
    //const
    int a = 10;
    int b = 10;
    const int *p = &a;
    //*p = 20;   ����ָ�� ָ������ݲ����޸�
    p = &b;
    int *const p1 = &b;
    //p1 = &a;  ָ�볣�� ָ���ָ�����޸�
    const int *const p3 = &a;
    //p3 = &b;��
    //*p = 20;��
    const int x = 10;
    //int &r=x;������const������ʼ������const������
    const int &r = x;
    int y = 3;
    const int &t = y;
}