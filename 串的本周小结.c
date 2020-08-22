/**
串的存储结构
1.串是一种特殊的线性表, 是线性表的一个子集
顺序串 链串

2.链串只能采用单链表吗？ 
不一定。需要根据需要根据情况而定
如果需要从某个节点出发前后查找，可以采用双链表。 
如果需要快速查找尾节点，可以采用循环双链表。

2.串的算法设计
BF算法
KMP算法
eg:
假设串采用顺序结构存储。
设计一个算法求串s中出现的第一个最长重复子串的下标和长度。
**/
void MaxSubstr(SqString s, SqString *t)
{
    int maxi = 0, maxlen = 0, len, i, j, k;
    i = 0;
    while (i < s.length) //从下标i的字符开始
    {
        j = i + 1; //从i的下一个位置开始找开始重复子串
        while (j < s.length)
        {
            if (s.data[i] == s.data[j]) //找一个子串，其起始下标为i，长度为len
            {
                len = 1;
                for (k = 1; s.data[i + k] == s.data[j + k]; k++)
                    len++;
                if (len > maxlen) //将较大长度者赋给maxi与maxlen
                {
                    maxi = i;
                    maxlen = len;
                }
                j += len;
            }
            else
                j++;
        }
        i++; //继续扫描第i字符之后的字符
    }
    t.length = maxlen; //将最长重复的子串赋给t
    for (i = 0; i < maxlen; i++)
        t.data[i] = s.data[maxi + i];
}
