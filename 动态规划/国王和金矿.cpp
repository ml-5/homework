/**
从前有个国家，所有的国民都很诚实、正义
某天他们在自己的国家发现了十座金矿，并且这十座金矿在地图
上排成一条直线，国王知道这个消息后非常高兴，他希望能够把
这些金子都挖出来造福国民
首先他把这些金矿按照在地图上的位置从西至东进行编号，依次
为0、1、2、3、4、5、6、7、8、9，然后他命令他的手下去对
每一座金矿进行勘测，以便知道挖取每一座金矿需要多少人力以
及每座金矿能够挖出多少金子，接着动员国民来挖金子
已知1：挖每一座金矿需要的人数是固定的，多一个人少一个人都不行。国王知道每个金矿各需要多少人手，金矿i需要的人
数为peopleNeeded[i] 
已知2：每一座金矿所挖出来的金子数是固定的，当第i座金矿有peopleNeeded[i]
人去挖的话，就一定能恰好挖出gold[i]个金子。否则一个金子都挖不出来
已知3：开采一座金矿的人完成开采工作后，他们不会再次去开采其它金矿，因此一个人最多只能使用一次
挖金矿问题
已知4：国王在全国范围内仅招募到了10000名愿意为了国家去挖金子的人，这些人可能不够把所有的金子都挖出来，但是国
王希望挖到的金子越多越好
已知5：这个国家的每一个人都很老实（包括国王），不会私吞任何金子，也不会弄虚作假，不会说谎话
已知6：国王只想知道最多可以挖出多少金子，而不用关心哪些金矿挖哪些金矿不挖
**/

#include <iostream>
using namespace std;
int n;                        //金矿总个数
int array1[100];              //金矿含金量
int array3[100];              //金矿对应的工人数
int capacity;                 //矿工的总人数
int array2[100 + 1][100 + 1]; //最大金矿收益
int array4[100] = {0};        //记录采那些矿
int f(int n, int array1[], int array3[])
{
    for (int i = 0; i <= n; i++)
    {
        array2[i][0] = 0;
    }
    for (int j = 0; j <= capacity; j++)
    {
        array2[0][j] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= capacity; j++)
        {
            if (j < array3[i])
            {
                array2[i][j] = array2[i - 1][j];
            }
            else
            {
                array2[i][j] = max(array2[i - 1][j], array2[i - 1][j - array3[i]] + array1[i]);
            }
        }
    }
    int s = capacity;
    for (int j = n; j > 0; j--)
    {
        if (array2[j][s] > array2[j - 1][s])
        {
            array4[j] = 1;
            s = s - array3[j];
        }
    }
    return array2[n][capacity];
}
int main()
{
    cout << "请输入金矿的总个数" << endl;
    cin >> n;
    cout << "请依次输入每个的含金量" << endl;
    memset(array1, 0, sizeof(array1));//初始化数组为0
    for (int i = 1; i <= n; i++)
    {
        cin >> array1[i];
    }
    cout << "请依次输入没个金矿的工人数" << endl;
    memset(array3, 0, sizeof(array3));
    for (int i = 1; i <= n; i++)
    {
        cin >> array3[i];
    }
    cout << "请输入总共的工人数";
    cin >> capacity;
    memset(array2, 0, sizeof(array2));//初始金矿收益
    memset(array4, 0, sizeof(array4));//初始矿
    cout << "可获的最大金矿" << f(n, array1, array3) << endl;
    cout << "需要采的矿是:";
    for (int i = 1; i <= n; i++)
    {
        if (array4[i] == 1)
        {
            cout << "矿" << i << " ";
        }
    }

    return 0;
}