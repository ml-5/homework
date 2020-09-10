/**设L为带头结点的单链表L,编写算法从尾到头反向输出每个节点的值**/
//思路:方法1.逆置输出 方法2.用栈 方法3.递归
void R_Print(Linklist L)
{
    //从尾到头输出单链表所有节点的值
    if (L->next != NULL)
    {
        R_Print(L->next); //递归
    }
    printf("L->data:%d", L->data);
}