/*��c++ 03�� ��ָ����0����ʾ 0����һ����������Ҳ��һ��������ָ��
 c�����п�ָ����(void*)0
 ��ʱ����NULL��ʾ��ָ��   #define NULL 0
 c++��׼ίԱ�������� nullptr��Ϊ��ָ��
 c++�еĶ�̬�ڴ�������ͷ�
 new <����> (��ʼֵ) //�������� new<����>[�������ʽ];
 delete <ָ����>; ɾ����ͨ����
 delete [] ָ���� //ɾ������ռ�
 */
#include <iostream>
int main()
{
    int *p = nullptr;
    int *q{nullptr}; //c++11���б��ʼ��
    p = new int(42);
    q = new int[4];
    std::cout << "Before: *p=" << *p << std::endl;
    *p = 24;
    std::cout << "After: *p=" << *p << std::endl;
    for (int i = 0; i < 4; i++)
    {
        *(q + i) = i;
        std::cout << *(q + i) << std::endl;
    }
    delete p;
    delete[] q;
    std::cin.get();
    return 0;
}