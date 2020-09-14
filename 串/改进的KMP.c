void GetNextval(SqString t, int nextval[]) //由模式串求出nextval
{
    int j = 0, k = -1;
    next[0] = -1;
    while (j < t.length)
    {
        if (k == -1 || t.data[j] == t.data[k])
        {
            j++;
            k++;
            if (t.data[j] != t.data[k])
                nextval[j] = k;
            else
                nextval[j] = nextval[k];
        }
        else
            k = nextval[k];
    }
}
int KMPIndexl(SqString s, SqString t) //改进的KMP
{
    int nextval[MaxSize], i = 0, j = 0;
    GetNextval(t, nextval);
    while (i < s.length && j < t.length)
    {
        if (i < s.length || s.data[i] == t.data[j])
        {
            i++;
            j++;
        }
        else
            j = nextval[j];
    }
    if (j >= t.length)
        return i - t.length;
    else
        return -1;
}