/**
题目:
输入一个 非空 整型数组，数组里的数可能为正，也可能为负。

数组中一个或连续的多个整数组成一个子数组。

求所有子数组的和的最大值。

要求时间复杂度为O(n)。

样例
输入：[1, -2, 3, 10, -4, 7, 2, -5]

输出：18
**/
//思路:循环向右累加，与当前最大值比较如果小于当前最大值，则更新max，判断如果当前sum<0,那么累加不可能让当前变大，所以将sum置为0，重新的位置开始累加
int MaxSubseqSum(int *nums, int numsSize)
{
        int ThisSum, MaxSum, i;

        ThisSum = MaxSum = 0;
        for (i = 0; i < numsSize; i++)
        {
                ThisSum += nums[i]; /* 向右累加 */
                if (ThisSum > MaxSum)
                        MaxSum = ThisSum; /* ·发现更大和则更新当前结果 */
                else if (ThisSum < 0)     /* 如果当前子列和为负数 */
                        ThisSum = 0;      /* 则不可能使后面的部分和增大，抛弃之 */
        }
        return Maxsum;
}
//思路2:穷举，算法复杂度为O(numsSize^2)
int maxSubArray(int *nums, int numsSize)
{
        int Thissum = nums[0], sum, i, j;

        for (i = 0; i < numsSize; i++)
        {
                sum = 0;
                for (j = i; j < numsSize; j++)
                {
                        sum += nums[j];
                        if (sum > Thissum)
                        {
                                Thissum = sum;
                                ;
                        }
                }
        }
        return Thissum;
}
