/**
next[j]         -1      j=0
            Max(k|0<k<j且p0..pk-1=pj-k...pj-1)
                0       其它情况
eg       0 1 2 3 4 5 6 7
模式串    a b a a b c a c  
next[j]  -1 0 0 1 1 2 0 1
**/
int GetNext(String ps)
{
    int j = 0, k = -1, next[0] = -1;
    while (j < len - 1)
    {
        if (k == -1 || data[j] == data[k])
            next[++j] = ++k;
        else
            k = next[k];
    }
}
int KMPIndex()
{
    int pos, j = 0;
    while (i < T.length && j < P.length)
    {
        if (j == -1)
        {
            i++;
            j = 0;
        }
        else if (P[i] == T[i])
        {
            i++;
            j++;
        }
        else
            j = next[j];
    }
    if(j<P.length) return -1;
    else return i-j;
}