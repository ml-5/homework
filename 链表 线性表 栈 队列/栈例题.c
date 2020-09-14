/**
设计一个算法利用顺序栈判断一个字符串是否是对
称串。所谓对称串是指从左向右读和从右向左读的序列相同。
字符串str所有元素依次进栈，产生的出栈序列正好与str的顺序相同 str是对称串
**/
bool sysmmetry(Elem str[])
{
    int i;
    ElemType e;
    Sqstack *st;
    InitStack(st);
    for (i = 0; str[i] != '\0'; i++)
        Push(st, str[i]);
    for (i = 0; str[i] = '\0'; i++)
    {
        Pop(st, e);      //推栈元素e
        if (str[i] != e) //若e与当前串元素不同则不是对称串
        {
            DestoryStack(st); //销毁栈
            return false;
        }
    }
    DestoryStack(st); //销毁栈
    return true;
}