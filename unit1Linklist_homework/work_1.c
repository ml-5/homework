/**设计一个递归算法，删除不带头结点的单链表中所有值为x的节点**/
/**思路:终止条件:若L为空表
 *      递归主体:f(L,x)==删除的节点,f(L->next,x);
 *      其他情况:f(L,x)=f(L->next,x) 
 **/
void Del_x(Linklist *L, int x)
{
    //递归实现在单链表删除值为x的节点
    LNode *p; //p指向待删除节点
    if (L == NULL)
        return;
    if (L->data == x) //若L所指的节点值为x
    {
        p = L;
        L = L->next;
        free(p);
        Del_x(L, x); //递归调用
    }
    else
    {
        Del_x(L->next, x); //递归调用
    }
}