/*
Ӧ�õĶ���:���þ�����һ�������ı���
�������ñ����ķ��� int x;int &rx=x; or int x,&rx=x;

���õ�����:1.ͨ�����������Ķ�д����ʵ������������ԭ�����ϵ�
2.����������������ʱ���ʼ��
3.����һ����ʼ���Ͳ��ܸ���
4.���������������Ĳ���:���ô���

*/
#include <iostream>
using namespace std;
void swap(int x, int y)
{
    int t;
    t = x;
    x = y;
    y = t;
}
void swap2(int *x, int *y)
{

    int t;
    t = *x;
    *x = *y;
    *y = t;
}
void swap3(int &x, int &y)
{
    int t;
    t = x;
    x = y;
    y = t;
}
int main(void)
{
    int x = 1, y = 2;
    swap(x, y);
    printf("%d %d\n", x, y);
    swap2(&x, &y);
    printf("%d %d\n", x, y);
    swap3(x, y);
    printf("%d %d\n", x, y);
}
/*
�������ʵĲ���
int a{0},b{1};
int &r{a};//���ñ���r��������ʱ���ʼ����rΪa�ı���
r=42;
r=b;
int &r2=a; //a�ı���
int &r3=r; //r�ı���
*/