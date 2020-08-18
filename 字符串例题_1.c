/**
设计顺序串上实现串比较运算Strcmp(s,t)的算法。
思路:1.比较s和t两个共同串范围内对应字符：
若s字符>t字符 ，返回1
若s字符<t字符 ，返回-1
若s字符=t字符，继续比较
当字符均相同,比较s和t的长度
1.两者相等时返回0
2.大于返回1
3.小于返回-1
**/
int Strcmp(SqString s, SqString t)
{
    int i, comlen;
    if (s.length < t.length)
        comlen = s.length; //求s和t的共同长度
    else
        comlen = t.length;
    for (i = 0; i < comlen; i++) //在共同长度内逐个字符比较
        if (s.data[i] > t.data[i])
            return 1;
        else if (s.data[i] < t.data[i])
            return -1;
    if (s.length == t.length) //s==t
        return 0;
    else if (s.length > t.length) //s>t
        return 1;
    else
        return -1; //s<t
}