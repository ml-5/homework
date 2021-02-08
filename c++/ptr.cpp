/*在c++ 03中 空指针用0来表示 0即是一个常量整数也是一个常量空指针
 c语言中空指针用(void*)0
 有时候用NULL表示空指针   #define NULL 0
 c++标准委员会引入了 nullptr作为空指针
 c++中的动态内存分配与释放
 new <类型> (初始值) //申请数组 new<类型>[常量表达式];
 delete <指针名>; 删除普通变量
 delete [] 指针名 //删除数组空间
 */
#include <iostream>
int main()
{
    int *p = nullptr;
    int *q{nullptr}; //c++11的列表初始化
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