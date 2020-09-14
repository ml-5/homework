/**
 * 输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。例如：输入数组{3，32，321}，则打印出这3个数字能排成的最小数字321323
 
 例如：输入数组{3，32，321}，则打印出这3个数字能排成的最小数字321323**/
/**
思路：
1.制定一种新的排序规则，数组根据这个规则排序之后能够排成一个最小的数字。 
2.要制定新的排序规则，就必须制定新的比较规则，即通过比较m和n，来确定哪一个应该排在前面（即哪一个更“小”）
新的比较规则：
两个数字m和n能够拼接成为数字mn和nm，如果mn < nm，那么我们应该打印出mn，也就是m应该排在n之前，我们定义此时m < n；反之我们应该打印出nm，定义n < m；如果mn == nm，则定义m=n
**/
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

//定义一个新的比较规则
//这里必须声明为静态函数
static bool compare(int item1, int item2)
{
    //使用to_string把int转换成为string
    string m = to_string(item1);
    string n = to_string(item2);
    //使用string的好处之一就是可以直接用加号（+）来进行拼接
    string mn = m + n;
    string nm = n + m;

    return mn < nm;
}

//按照新的比较规则对数组进行排序
//然后按照排序的顺序进行输出
string PrintMinNumber(vector<int> numbers)
{
    string resu;
    if (numbers.size() <= 0)
        return resu;

    sort(numbers.begin(), numbers.end(), compare);

    //使用范围for循环
    for (auto num : numbers)
    {
        resu += to_string(num);
    }

    return resu;
}

int main()
{
    vector<int> test{3, 32, 321};
    cout << PrintMinNumber(test) << endl;

    return 0;
}