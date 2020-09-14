/**
在链串中，设计一个算法把最先出现的子串“ab”
改为“xyz”。 … a b … p  查找：p->data='a' && p->next->data='b'
**/
typedef struct snode
{
    char data;
    struct snode *next;
} LiString;
void Repl(LiString *s)
{
    LiString *p = s->next, *q;
    int find = 0;
    while (p->next != NULL && find == 0) //查找ab子串
    {
        if (p->data == 'a' && p->next->data == 'b')
        {
            p->data = 'x';
            p->next->data = 'z';
            q = (LiString *)malloc(sizeof(LiString));
            q->data = 'y';
            q->next = p->next;
            p->next = q;
            find = 1;
        }
        else
            p = p->next;
    }
}