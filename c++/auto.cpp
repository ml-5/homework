/**1.�ؼ���auto
C++11�У�auto�ؼ��ַ��ڱ���֮ǰ��
������������������ʱ����ݱ�����ʼֵ�������Զ�Ϊ�˱���ѡ��ƥ�������*/

#include <iostream>
using namespace std;
int main()
{
    int  a = 10;
    auto au_a = a; //�Զ������ƶ�
    cout << typeid(au_a).name() << endl;
    2.     auto��ʹ������
 

//2.1.auto ���������ڶ���ʱ��ʼ������������const�ؼ���
auto a1 = 10;  //��ȷ 
auto b1;   //����,�������޷��Ƶ�b1������
b1 = 10;

//2.2. ������һ��auto���еı�������ʼ���Ƶ���ͬһ����
 
auto a4 = 10, a5{20};   //��ȷ 
auto b4{10}, b5 = 20.0; //����,û���Ƶ�Ϊͬһ����
 
//2.3. �����ʼ�����ʽ�����û�const����ȥ�����û�const���塣
int a{10}; int &b = a;
auto c = b;   //c������Ϊint����int&��ȥ�����ã�
const int a1{10};
auto b1 = a1; //b1������Ϊint����const int��ȥ��const�� 

//2.4.���auto�ؼ��ִ���&�ţ���ȥ�����û�const����
int a = 10; int& b = a;
auto& d = b;//��ʱd�����Ͳ�Ϊint&
const int a2 = 10;
auto& b2 = a2;//��Ϊauto����&���ʲ�ȥ��const��b2����Ϊconst in

//2.5. ��ʼ�����ʽΪ����ʱ��auto�ؼ����Ƶ�����Ϊָ�롣
int a3[3] = { 1, 2, 3 };

auto b3 = a3;

cout << typeid(b3).name() << endl; //���int * �������������йأ�
//2.6. �����ʽΪ������auto����&�����Ƶ�����Ϊ�������͡�
int a7[3] = { 1, 2, 3 };
auto& b7 = a7;

cout << typeid(b7).name() << endl; //���int [3] �������������йأ�

//2.7. C++14�У�auto������Ϊ�����ķ���ֵ���ͺͲ�������
 

 


}