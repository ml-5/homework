/*
�������Ա�������У�
1���ÿձ� SETNULL��&L�������Ա� L �óɿձ�
2���󳤶� LENGTH��L�� ��������Ա� L �ĳ���
3��ȡԪ�� GET��L��i�� �� 1��i��length(L),��ȡ�� i ��λ���ϵ�Ԫ�أ�����ȡ�õ�Ԫ��
Ϊ NULL�� 
4����ֱ��ǰ�� PRIOR��L��X�������Ա� L ��Ԫ��ֵΪ X ��ֱ��ǰ������ X Ϊ��һ
��Ԫ�أ�ǰ��Ϊ NULL�� 
5����ֱ�Ӻ�� NEXT��L��X�������Ա� L ��Ԫ��ֵΪ X ֱ�Ӻ�̣��� X Ϊ���һ
��Ԫ�أ����Ϊ NULL�� 
6����λ���� LOCATE��L��X�� �����Ա� L �в���ֵΪ X ��Ԫ��λ�ã����ж��ֵ
Ϊ X�����Ե�һ��Ϊ׼����û�У�λ��Ϊ 0�� 
7������ INSERT��&L��X��i�������Ա� L �е� i ��λ���ϲ���ֵΪ X ��Ԫ�ء�
8��ɾ�� DELETE��&L��i�� ɾ�����Ա� L �е� i ��λ���ϵ�Ԫ�ء�
*/
#include <iostream>
using namespace std;
#define MaxSize 25
typedef int DataType;
class SeqList
{
private:
    DataType list[MaxSize];
    int length;

public:
    SeqList() { length = 0; }
    void SLCreat(int n);              //����˳���
    void SLInsert(int i, DataType x); //��˳���ĵ�i��λ�ò�������Ԫ��x
    void SLDelete(int i);             //��˳���L�еĵ�i��λ��ɾ��Ԫ��
    DataType SLGet(int i);            //��ȡ��i��λ�õ�Ԫ��λ��
    DataType SLSum();                 //���
    int SLIsEmpty();                  //�ж�˳����Ƿ�Ϊ��
    void SLPrint();                   //��˳�����ʾ����Ļ��
};
void SeqList::SLCreat(int n)
{
    DataType x;
    length = n;
    cout << "������Ԫ�ص�ֵ:";
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        list[i] = x;
    }
}
//��˳���L�е�iλ��ǰ��������Ԫ��x
void SeqList::SLInsert(int i, DataType x)
{
    int k;
    if (length >= MaxSize)
        cout << "���Ѿ�����,�޷�����" << endl;
    else if (i < 0 || i > length)
        cout << "����i������" << endl;
    else
    {
        for (k = length; k > i; k--)
            list[k] = list[k - 1];
        list[i] = list[i - 1];
        list[i - 1] = x;
        length++;
    }
}
void SeqList::SLDelete(int i)
{
    int k;
    if (!SLIsEmpty())
        cout << "���ѿ�,�޷�ɾ��!" << endl;
    else if (i < 0 || i > length)
    {
        cout << "����i������!" << endl;
    }
    else
    {
        for (k = i; k < length; k++)
            list[k] = list[k + 1];
        length--;
    }
}
DataType SeqList::SLGet(int i)
{
    if (i < 0 || i > length)
    {
        cout << "����i������" << endl;
        return 0;
    }
    else
    {
        return list[i - 1];
    }
}
int SeqList::SLIsEmpty()
{
    if (length <= 0)
        return 0;
    else
        return 1;
}
void SeqList::SLPrint()
{
    if (!SLIsEmpty())
        cout << "�ձ�!" << endl;
    else
        for (int i = 0; i < length; i++)
            cout << list[i] << " ";
    cout << endl;
}
//���
DataType SeqList::SLSum()
{
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += list[i];
    }
    return sum;
}
int main()
{
    SeqList mylist;
    int i, n, flag = 1, select;
    DataType x;
    cout << " 1.����˳���\n";
    cout << " 2.��� i ��λ���ϵ���ֵ\n";
    cout << " 3.�ڵ� i ��λ��ǰ�ϲ�����ֵԪ�� x\n";
    cout << " 4.ɾ���� i ��λ���ϵ���ֵ\n";
    cout << " 5.��˳����ϸ�Ԫ��֮��\n";
    cout << " 6.�����ʾ\n";
    cout << " 7.�˳�\n";
    while (flag)
    {
        cout << "��ѡ��: ";
        cin >> select;
        switch (select)
        {
        case 1:
            cout << "������˳�����:";
            cin >> n;
            mylist.SLCreat(n);
            cout << "˳���Ϊ�� ";
            mylist.SLPrint();
            break;
        case 2:
            cout << "������λ�� i: ";
            cin >> i;
            cout << "��" << i << "��λ���ϵ���ֵΪ: " << mylist.SLGet(i) << endl;
            break;
        case 3:
            cout << "������Ҫ����Ԫ�ص�λ�� i ����ֵ x: ";
            cin >> i >> x;
            mylist.SLInsert(i, x);
            mylist.SLPrint();
            break;
        case 4:
            cout << "������Ҫɾ������ֵ��λ��: ";
            cin >> i;
            mylist.SLDelete(i);
            cout << "ɾ�����˳���Ϊ: ";
            mylist.SLPrint();
            break;
        case 5:
            cout << "��͵�ֵ��" << mylist.SLSum() << endl;
            break;
        case 6:
            cout << "˳���Ϊ: ";
            mylist.SLPrint();
            break;
        case 7:
            flag = 0;
            break;
        }
    }
    return 0;
}