/**右图是一个城堡的地形图
。请你编写一个程序，计算城堡一共有多少房间，最大的房间有多大。城堡被分割成m×n(m≤50，n≤50)个方块，每个方块可
以有0~4面墙。
输入输出
输入
程序从标准输入设备读入数据。
第一行是两个整数，分别是南北向、东西向的方块数。
在接下来的输入行里，每个方块用一个数字(0≤p≤50)描述。用一个数
字表示方块周围的墙，1表示西墙，2表示北墙，4表示东墙，8表示南
墙。每个方块用代表其周围墙的数字之和表示。城堡的内墙被计算两
次，方块(1,1)的南墙同时也是方块(2,1)的北墙。
输入的数据保证城堡至少有两个房间。
输出
城堡的房间数、城堡中最大房间所包括的方块数。
结果显示在标准输出设备上。
**/
/**解题思路
? 把方块看作是节点，相邻两个方块之间如果没
有墙，则在方块之间连一条边，这样城堡就能
转换成一个图。
? 求房间个数，实际上就是在求图中有多少个极
大连通子图。
? 一个连通子图，往里头加任何一个图里的其他
点，就会变得不连通，那么这个连通子图就是
极大连通子图。（如：(8,5,6))
解题思路
 对每一个房间，深度优先搜索，从而给这个房
间能够到达的所有位置染色。最后统计一共用
了几种颜色，以及每种颜色的数量。
比如
1 1 2 2 3 3 3
1 1 1 2 3 4 3 
1 1 1 5 3 5 3
1 5 5 5 5 5 3
 从而一共有5个房间，最大的房间（1）占据9
个格子
4 
7 
11 6 11 6 3 10 6 
7 9 6 13 5 15 5 
1 10 12 7 13 7 5 
13 11 10 8 10 12 13
? 样例输出
59
**/
#include <iostream>
#include <stack>
#include <cstring>
using namespace std;
int R, C; //行列数
int rooms[60][60];
int color[60][60];
int maxRoomArea = 0, roomNum = 0;
int roomArea;
void Dfs(int i, int k)
{
    if (color[i][k])
        return;
    ++roomArea;
    color[i][k] = roomNum;
    if ((rooms[i][k] & 1) == 0)
        Dfs(i, k - 1); //向西走
    if ((rooms[i][k] & 2) == 0)
        Dfs(i - 1, k); //向北
    if ((rooms[i][k] & 4) == 0)
        Dfs(i, k + 1); //向东
    if ((rooms[i][k] & 8) == 0)
        Dfs(i + 1, k); //向南
}
int main()
{
    cin >> R >> C;
    for (int i = 0; i < = R; i++)
    {
        for (int k = 1; k <= C; k++)
            cin >> room[i][k];
    }
    memset(color, 0, sizeof(color));
    for (int i = 1; i <= R; ++i)
        for (int k = 1; k <= C; k++)
            if (!color[i][k])
            {
                ++roomNum;
                roomArea = 0;
                Dfs(i, k);
                maxRoomArea = max(roomArea, maxRoomArea);
            }
    cout << roomNum << endl;
    cout << maxRoomArea << endl;
}