/**
eg:设计不带头结点的单链表递归算法
1.求单链表中的数据节的个数
设F(L)为单链表数据节点中的个数
空链表个数为0
对于非空单链表
F(L)=F(L->next)+1

2.
正向显示所有节点的值
假设F（L->next)已经求解
F(L)->F(L->next);输出L->data;

3.反向显示所有节点的值

**/
int count(Node *L)
{
    if (L == NULL)
        return 0;
    else
        return count(L->next) + 1;
}

void traverse(Node *L)
{
    if (L == NULL)
        return;
    printf("%d", L->data);
    traverse(L->next);
}

void traverseR(Node *L)
{
    if (L == NULL)
        return;
    traverseR(L->next);
    printf("%d", L->data);
}