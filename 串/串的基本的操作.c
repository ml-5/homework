#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MaxSize 50
typedef struct
{
    char data[MaxSize]; //存放串字符
    int length;         //存放串长
} SqString;             //顺序串类型

void StrAssing(SqString *s, char cstr[]) //串的生成
{
    int i;
    for (i = 0; cstr[i] != '\0'; i++)
        s->data[i] = cstr[i];
    s->length = i; //设置串的长度
}
void StrCopy(SqString *s, SqString t) //串的复制
{
    int i;
    for (i = 0; i < t.length; i++) //复制t的所有字符
        s->data[i] = t.data[i];
    s->length = t.length; //设置串s的长度
}
bool StrEqual(SqString s, SqString t)
{
    bool same = true;
    int i;
    if (s.length != t.length)
        same = false;
    else
        for (i = 0; i < s.length; i++)
        {
            if (s.data[i] != t.data[i]) //判断每个字符是否相等
            {
                same = false;
                break;
            }
        }
    return same;
}
int StrLength(SqString s) //求串的长度
{
    return s.length;
}
SqString Concat(SqString s, SqString t) //复制
{
    SqString str; //定义结果串
    int i;
    str.length = s.length + t.length;
    for (i = 0; i < s.length; i++) //将s.data[0 ... s.length-1]复制到结果串
        str.data[i] = s.data[i];
    for (i = 0; i < t.length; i++)
        str.data[s.length + i] = t.data[i];
    return str;
}
SqString SubStr(SqString s, int i, int j)
{
    int k;
    SqString str;   //定义结果串
    str.length = 0; //设置str空串
    if (i <= 0 || i > s.length || j < 0 || i + j - 1 > s.length)
        return str; //参数不正确返回空串
    for (k = i - 1; k < i + j - 1; k++)
        str.data[k - i + 1] = s.data[k];
    str.length = j;
    return str;
}
SqString InStr(SqString s1, int i, SqString s2)
{
    int j;
    SqString str; //定义结果串
    str.length = 0;
    if (i <= 0 || i > s1.length + 1) //参数不正确返回空串
        return str;
    for (j = 0; j < i - 1; j++)
        str.data[j] = s1.data[j];
    for (j = 0; j < s2.length; j++)
        str.data[i + j - 1] = s2.data[j];
    for (j = i - 1; j < s1.length; j++)
        str.data[s2.length + j] = s1.data[j];
    str.length = s1.length + s2.length;
}
SqString DelStr(SqString s, int i, int j) //删除子串
{
    int k;
    SqString str;   //定义结果串
    str.length = 0; //设置str为空串
    if (i <= 0 || i > s.length || i + j > s.length + 1)
        return str;
    for (k = 0; k < i - 1; k++)
        str.data[k] = s.data[k];
    for (k = i + j - 1; k < s.length; k++) // data[ i+ j-1..s. length-1 复制到 str
        str.data[k - j] = s.data[k];
    str.length = s.length - j;
    return str;
}
SqString RepStr(SqString s, int i, int j, SqString t) //子串的替换
{
    int k;
    SqString str;
    str.length = 0;
    if (i <= 0 || i > s.length || i + j - 1 > s.length)
        return str;
    for (k = 0; k < i - 1; k++)
        str.data[k] = s.data[k];
    for (k = 0; k < t.length; k++)
        str.data[i + k - 1] = t.data[k];
    for (k = i + j - 1; k < s.length; k++)
        str.data[t.length + k - j] = s.data[k];
    str.length = s.length - j + t.length;
    return str;
}
void DispStr(SqString s)//输出
{
    int i;
    if (s.length > 0)
    {
        for (i = 0; i < s.length; i++)
            printf("¾c", s.data[i]);
        printf("\n");
    }
}