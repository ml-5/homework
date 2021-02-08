/*
用来高效存储和查找字符串集合的数据结构
*/
#include <iostream>
using namespace std;
const int N = 100010;
/*
son[][]存储树中每个节点的子节点，题目告诉字符串仅包含小写英文字母
所以每一个节点最多有26个子节点
*/
int son[N][26];
//表示当前以N结尾的单词有多少个
int cnt[N];
/*
idx与单链表中idx不一样，这里的idx表示最后一个插入字母的下标，新字母创建时
对应的下标是++idx，而单链表中的idx直接就可以用来分配给新的节点
下标是0的点，既是根节点，也是空节点
注意这里先++idx别死记硬背，这里是因为要用idx=0表示空节点，因此当你初始化idx为0时
给新节点的赋值必须先++之后再赋值，所以你也完全可以先初始化idx=1，之后赋值是idx++
*/
int idx;
void insert(char str[])
{
    int p = 0; //从根节点向下探索
    for (int i = 0; str[i]; i++)
    {
        int u = str[i] - 'a'; //当前遍历字母对应的子节点编号
        if (!son[p][u])
            son[p][u] = ++idx;
        p = son[p][u];
    }
    cnt[p]++;
}
int query(char str[])
{

    int p = 0;
    for (int i = 0; str[]; i++)
    {
        int u = str[i] - 'a';
        if (!son[p][u])
            return 0;
        p = son[p][u];
    }
    return cnt[p];
}
int main()
{
    int n;
    cin >> n;
    char str[N];
    while (n--)
    {
        string op;
        cin >> op >> str;
        if (op == "I")
            insert(str);
        else
            cout << "query(str)" << endl;
    }
    return 0;
}
