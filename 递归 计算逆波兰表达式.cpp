/**
1) 一个数是一个逆波兰表达式，值为该数
2) "运算符 逆波兰表达式 逆波兰表达式" 是逆波兰表达
式 ，值为两个逆波兰表达式的值运算的结果
一般教科书将本题中的“逆波兰表达式”称为“波兰表达式”，而将运
算符后置的表达式成为“逆波兰表达式
**/
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
double exp()
{
    char s[20];
    cin >> s;
    switch (s[0])
    {
    case '+':
        return exp() + exp();

    case '-':
        return exp() - exp();

    case '*':
        return exp() * exp();

    case '/':
        return exp() / exp();
        break;

    default:
        return atof(s);
        break;
    }
}
int main()
{
    printf("%lf", exp());
    return 0;
}