/*
应用的定义:引用就是另一个变量的别名
声明引用变量的方法 int x;int &rx=x; or int x,&rx=x;

引用的性质:1.通过引用所做的读写操作实际上是作用于原变量上的
2.必须在声明变量的时候初始化
3.引用一旦初始化就不能更改
4.引用类型做函数的参数:引用传递

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
引用性质的补充
int a{0},b{1};
int &r{a};//引用变量r在声明的时候初始化，r为a的别名
r=42;
r=b;
int &r2=a; //a的别名
int &r3=r; //r的别名
*/