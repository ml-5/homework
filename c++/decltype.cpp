/*
1.     �ؼ���decltype���÷�
decltype������֪���������±�����
����auto��Ϊʲô��Ҫ����һ��decltype��ԭ���ǣ�������ʱ����Ҫ�ӱ��ʽ�������ƶϳ�Ҫ����ı������ͣ��������øñ��ʽ��ֵ��ʼ��������
decltype���ڱ������Ƶ�һ�����ʽ�����ͣ���ֻ����̬��������������ᵼ����֪���ͱ��ʽִ�С�
decltype ��Ҫ���ڷ��ͱ�̣�ģ�壩
*/
#include <iostream>
using namespace std;
int fun1() { return 10; }
auto fun2() { return 'g'; } // C++14
int main()
{
    // Data type of x is same as return type of fun1()
    // and type of y is same as return type of fun2()
    decltype(fun1()) x; // ����ִ��fun1()����
    decltype(fun2()) y = fun2();
    cout << typeid(x).name() << endl;
    cout << typeid(y).name() << endl;
    return 0;
}
/*
3.     decltype��auto�ĶԱ�

decltype��auto����C++11�Զ������Ƶ��Ĺؼ��֡������кܶ���
auto�������ϲ��const��decltype�������ϲ��const
auto����ԭ�����͵����ã�decltype����ԭ�����͵�����
�Խ����ò�����auto�ƶϳ�ԭ�����ͣ�decltype�ƶϳ����ã�4.auto�ƶ�ʱ��ʵ��ִ�У�decltype����ִ�У�ֻ����������֮��ʹ���й����к�const�����ú�ָ����ʱ��Ҫ�ر�С�ġ�

 */