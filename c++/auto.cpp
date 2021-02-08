/**1.关键字auto
C++11中，auto关键字放在变量之前，
作用是在声明变量的时候根据变量初始值的类型自动为此变量选择匹配的类型*/

#include <iostream>
using namespace std;
int main()
{
    int  a = 10;
    auto au_a = a; //自动类型推断
    cout << typeid(au_a).name() << endl;
    2.     auto的使用限制
 

//2.1.auto 变量必须在定义时初始化，这类似于const关键字
auto a1 = 10;  //正确 
auto b1;   //错误,编译器无法推导b1的类型
b1 = 10;

//2.2. 定义在一个auto序列的变量必须始终推导成同一类型
 
auto a4 = 10, a5{20};   //正确 
auto b4{10}, b5 = 20.0; //错误,没有推导为同一类型
 
//2.3. 如果初始化表达式是引用或const，则去除引用或const语义。
int a{10}; int &b = a;
auto c = b;   //c的类型为int而非int&（去除引用）
const int a1{10};
auto b1 = a1; //b1的类型为int而非const int（去除const） 

//2.4.如果auto关键字带上&号，则不去除引用或const语意
int a = 10; int& b = a;
auto& d = b;//此时d的类型才为int&
const int a2 = 10;
auto& b2 = a2;//因为auto带上&，故不去除const，b2类型为const in

//2.5. 初始化表达式为数组时，auto关键字推导类型为指针。
int a3[3] = { 1, 2, 3 };

auto b3 = a3;

cout << typeid(b3).name() << endl; //输出int * （输出与编译器有关）
//2.6. 若表达式为数组且auto带上&，则推导类型为数组类型。
int a7[3] = { 1, 2, 3 };
auto& b7 = a7;

cout << typeid(b7).name() << endl; //输出int [3] （输出与编译器有关）

//2.7. C++14中，auto可以作为函数的返回值类型和参数类型
 

 


}