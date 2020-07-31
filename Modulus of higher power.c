//高次幂取模
//方法：
//1.(a + b) % p = (a % p + b % p) % p
//2.(a - b) % p = (a % p - b % p ) % p
//3.(a * b) % p = (a % p * b % p) % p
//题目 eg:求2的100次的最后3位数
/**
 * 普通的求幂函数
 *  base 底数
 *  power  指数
 *   求幂结果的最后3位数表示的整数
 */
//对于a方法来说数据溢出无法求得正确结果
#include <stdio.h>
long long a_normalPower(long long base, long long power)
{
    long long result = 1;
    for (int i = 1; i <= power; i++)
    {
        result = result * base;
    }
    return result % 1000;
}
//由上面的3可得法b
long long b_normalPower(long long base, long long power)
{
    long long result = 1;
    for (int i = 1; i <= power; i++)
    {
        result = result * base;
        result = result % 1000;
    }
    return result % 1000;
}
//此方法耗时长，数据过大时，可能会判超时

//快速幂算法
//思路:速幂算法能帮我们算出指数非常大的幂，传统的求幂算法之所以时间复杂度非常高（为O(指数n)），
//就是因为当指数n非常大的时候，需要执行的循环操作次数也非常大。
//所以我们快速幂算法的核心思想就是每一步都把指数分成两半，而相应的底数做平方运算。
//这样不仅能把非常大的指数给不断变小，所需要执行的循环次数也变小，而最后表示的结果却一直不会变。让我们先来看一个简单的例子：
/**
3^10=3*3*3*3*3*3*3*3*3*3
尽量想办法把指数变小来，这里的指数为10
3^10=(3*3)*(3*3)*(3*3)*(3*3)*(3*3)
3^10=(3*3)^5
3^10=9^5
此时指数由10缩减一半变成了5，而底数变成了原来的平方，求3^10原本需要执行10次循环操作，
求9^5却只需要执行5次循环操作，但是3^10却等于9^5,我们用一次（底数做平方操作）的操作减少了原本一半的循环量，
特别是在幂特别大的时候效果非常好，例如2^10000=4^5000,底数只是做了一个小小的平方操作，
而指数就从10000变成了5000，减少了5000次的循环操作。
现在我们的问题是如何把指数5变成原来的一半，5是一个奇数，5的一半是2.5，但是我们知道，指数不能为小数，
因此我们不能这么简单粗暴的直接执行5/2，然而，这里还有另一种方法能表示9^5
9^5=（9^4）*（9^1）
此时我们抽出了一个底数的一次方，这里即为9^1，这个9^1我们先单独移出来,剩下的9^4又能够在执行“缩指数”操作了，把指数缩小一半，底数执行平方操作
9^5=（81^2）*(9^1)
把指数缩小一半，底数执行平方操作
9^5=（6561^1）*(9^1)
此时，我们发现指数又变成了一个奇数1，按照上面对指数为奇数的操作方法，应该抽出了一个底数的一次方，这里即为6561^1，
这个6561^1我们先单独移出来，但是此时指数却变成了0，也就意味着我们无法再进行“缩指数”操作了。
9^5=（6561^0）*(9^1)*(6561^1)=1*(9^1)*(6561^1)=(9^1)*(6561^1)=9*6561=59049
我们能够发现，最后的结果是9*6561，而9是怎么产生的？是不是当指数为奇数5时，此时底数为9。
那6561又是怎么产生的呢？是不是当指数为奇数1时，此时的底数为6561。
所以我们能发现一个规律：最后求出的幂结果实际上就是在变化过程中所有当指数为奇数时底数的乘积
**/

long long a_fastPower(long long base, long long power)
{
    long long result = 1;
    while (power > 0)
    {
        if (power % 2 == 0)
        {
            //如果指数为偶数
            power = power / 2;         //把指数缩小为一半
            base = base * base % 1000; //底数变大成原来的平方
        }
        else
        {
            //如果指数为奇数
            power = power - 1;             //把指数减去1，使其变成一个偶数
            result = result * base % 1000; //此时记得要把指数为奇数时分离出来的底数的一次方收集好
            power = power / 2;             //此时指数为偶数，可以继续执行操作
            base = base * base % 1000;
        }
    }
    return result;
}
//继续优化
long long b_fastPower(long long base, long long power)
{
    long long result = 1;
    while (power > 0)
    {
        if (power % 2 == 1)
        {
            result = result * base % 1000;
        }
        power = power / 2;
        base = (base * base) % 1000;
    }
    return result;
}
//最终优化
long long c_fastPower(long long base, long long power)
{
    long long result = 1;
    while (power > 0)
    {
        if (power & 1)
        { //此处等价于if(power%2==1)
            result = result * base % 1000;
        }
        power >>= 1; //此处等价于power=power/2
        base = (base * base) % 1000;
    }
    return result;
}
int main()
{

    printf("%d", c_fastPower(2, 100));
}