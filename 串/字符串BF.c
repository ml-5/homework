int index(SqString s, SqString t)
{
    int i = 0, j = 0;
    while (i < s.length && j < t.length)
    {
        if (s.data[i] == t.data[j]) //继续匹配下一个字符
        {
            i++; //主串和子串依次匹配下一个字符
            j++;
        }
        else //主串、子串指针回溯重新开始下一次匹配
        {
            i = i - j + 1; //主串从下一个位置开始匹配
            j = 0;         //子串从头开始匹配
        }
    }
    if (j >= t.length)
        return (i - t.length); //返回匹配的第一个字符的下标
    else
        return (-1); //模式匹配不成功
}
/**
BF算法分析：
算法在字符比较不相等，需要回溯（即i=i-j+1）：即退到s中
的下一个字符开始进行继续匹配。
最好情况下的时间复杂度为O(m)。
最坏情况下的时间复杂度为O(n×m)。
平均的时间复杂度为O(n×m)。
**/