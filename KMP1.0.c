/**
该算法较BF算法有较大改进，主要是消除了主串指针的回
溯，从而使算法效率有了某种程度的提高。
next[j]是指t[j]字符前有多少个字符与t开头的字符相同。
模式串t在某个k(0<k<j),使得以下成立
例如，t= “a b a b c” 考虑t[4]='c'
0 1 2 3 4
有t0t1＝ t2t3 = "ab"  k=2
所以next[4]=k=2
**/
void GetNext(SqString t, int next[])
{
    int k, j;
    j = 0;
    k = -1;
    next[0] = -1;
    while(j<t.length-1)
    {
        if
    }
}
