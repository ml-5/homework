/*const 修饰指针
const int *p(常量指针) p指向的内容不能更改
int *const p(指针常量) p指向的地址不可以修改
const int *const p (常指针常量)指针指向和指向的内容都不能修该
*/
#include <iostream>
using namespace std;
int main()
{
    //const
    int a = 10;
    int b = 10;
    const int *p = &a;
    //*p = 20;   常量指针 指向的内容不能修改
    p = &b;
    int *const p1 = &b;
    //p1 = &a;  指针常量 指针的指向不能修改
    const int *const p3 = &a;
    //p3 = &b;错
    //*p = 20;错
    const int x = 10;
    //int &r=x;不能用const常量初始化不带const的引用
    const int &r = x;
    int y = 3;
    const int &t = y;
}