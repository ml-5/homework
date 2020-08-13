/**
编写一个算法判断输入的表达式中括号是否配
对（假设只含有左、右圆括号）。
算法思路:一个表达式中的左右括号按最近的位置配对的，所以用一个栈进行求解
**/
bool Match(char exp[], int n)
{
    int i = 0;
    char e;
    bool match = true; //配对是为true，否则为false
    LiStack *st;
    InitStack(st);         //初始化栈
    while (i < n && match) //扫描exp中的所有字符
    {
        if (exp[i] == '(') //遇到字符为左括号时候进栈
            Push(st, exp[i]);
        else if (exp[i] == ')')
        {
            if (GetTop(st, e) == true)
            {
                if (e != '(')
                    match = false;
                else
                    Pop(st, e); //将栈定元素出栈
            }
            else
                match = false;
        }
        i++; //继续处理其它字符
    }
    if (!StackEmpty(st))
        match = false; //栈不为空表示不匹配
    DestoryStack(st);  //销毁栈
    return match;
}