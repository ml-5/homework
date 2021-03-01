/*
常见线性表的运算有：
1．置空表 SETNULL（&L）将线性表 L 置成空表
2．求长度 LENGTH（L） 求给定线性表 L 的长度
3．取元素 GET（L，i） 若 1≤i≤length(L),则取第 i 个位置上的元素，否则取得的元素
为 NULL。 
4．求直接前趋 PRIOR（L，X）求线性表 L 中元素值为 X 的直接前趋，若 X 为第一
个元素，前驱为 NULL。 
5．求直接后继 NEXT（L，X）求线性表 L 中元素值为 X 直接后继，若 X 为最后一
个元素，后继为 NULL。 
6．定位函数 LOCATE（L，X） 在线性表 L 中查找值为 X 的元素位置，若有多个值
为 X，则以第一个为准，若没有，位置为 0。 
7．插入 INSERT（&L，X，i）在线性表 L 中第 i 个位置上插入值为 X 的元素。
8．删除 DELETE（&L，i） 删除线性表 L 中第 i 个位置上的元素。
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
    void SLCreat(int n);              //创建顺序表
    void SLInsert(int i, DataType x); //在顺序表的第i个位置插入数据元素x
    void SLDelete(int i);             //在顺序表L中的第i个位置删除元素
    DataType SLGet(int i);            //获取第i个位置的元素位置
    DataType SLSum();                 //求和
    int SLIsEmpty();                  //判断顺序表是否为空
    void SLPrint();                   //将顺序表显示在屏幕上
};
void SeqList::SLCreat(int n)
{
    DataType x;
    length = n;
    cout << "请输入元素的值:";
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        list[i] = x;
    }
}
//在顺序表L中的i位置前插入数据元素x
void SeqList::SLInsert(int i, DataType x)
{
    int k;
    if (length >= MaxSize)
        cout << "表已经满了,无法插入" << endl;
    else if (i < 0 || i > length)
        cout << "参数i不合理" << endl;
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
        cout << "表已空,无法删除!" << endl;
    else if (i < 0 || i > length)
    {
        cout << "参数i不合理!" << endl;
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
        cout << "参数i不合理！" << endl;
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
        cout << "空表!" << endl;
    else
        for (int i = 0; i < length; i++)
            cout << list[i] << " ";
    cout << endl;
}
//求和
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
    cout << " 1.建立顺序表\n";
    cout << " 2.求第 i 个位置上的数值\n";
    cout << " 3.在第 i 个位置前上插入数值元素 x\n";
    cout << " 4.删除第 i 个位置上的数值\n";
    cout << " 5.该顺序表上各元素之和\n";
    cout << " 6.输出显示\n";
    cout << " 7.退出\n";
    while (flag)
    {
        cout << "请选择: ";
        cin >> select;
        switch (select)
        {
        case 1:
            cout << "请输入顺序表长度:";
            cin >> n;
            mylist.SLCreat(n);
            cout << "顺序表为： ";
            mylist.SLPrint();
            break;
        case 2:
            cout << "请输入位置 i: ";
            cin >> i;
            cout << "第" << i << "个位置上的数值为: " << mylist.SLGet(i) << endl;
            break;
        case 3:
            cout << "请输入要插入元素的位置 i 和数值 x: ";
            cin >> i >> x;
            mylist.SLInsert(i, x);
            mylist.SLPrint();
            break;
        case 4:
            cout << "请输入要删除的数值的位置: ";
            cin >> i;
            mylist.SLDelete(i);
            cout << "删除后的顺序表为: ";
            mylist.SLPrint();
            break;
        case 5:
            cout << "求和的值：" << mylist.SLSum() << endl;
            break;
        case 6:
            cout << "顺序表为: ";
            mylist.SLPrint();
            break;
        case 7:
            flag = 0;
            break;
        }
    }
    return 0;
}