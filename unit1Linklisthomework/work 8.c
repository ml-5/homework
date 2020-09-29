/** 给定两个单链表，编写算法找出两个链表的公共节点**/
LinkList Search_lstCommon(Linklist L1, LinkList L2)
{                                             //本算法实现在线性时间内找到两个单链表的第一个公共节点
    int len1 = Length(L1), len2 = Length(L2); //计算两个单链表的表长度
    LinkList longList, shortList;             //L1表长较长
    if (len1 > len2)
    {
        longList = L1->next;
        shortList = L2->next;
        dist = len1 - len2; //表长只差
    }
    else
    {
        longList = L2->next;
        shortList = L1->next;
        dist = len2 - len1;
    }
    while (dist--)
        longList = longList->next;
    while (longList != NULL)
    {                              //同步寻找共同结点
        if (longList == shortList) //找到第一个公共结点
            return longList;
        else
        { //继续同步寻找
            longList = longList->next;
            shortList = shortList->next;
        }
    } //while
    return NULL;
}