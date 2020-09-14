/**
题目:给定一个长度为 n 的整数数组 nums，数组中所有的数字都在 0∼n−1 的范围内。

数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。

请找出数组中任意一个重复的数字。

注意：如果某些数字不在 0∼n−1 的范围内，或数组中不包含重复数字，则返回 -1；

样例
给定 nums = [2, 3, 5, 4, 3, 2, 6, 7]。

返回 2 或 3。 **/
//思路:此题按照题意即可
int duplicateInArray(int *nums, int numsSize)
{
    int i, j;
    for (i = 0; i < numsSize; i++)
    {
        if (nums[i] < 0 || nums[i] > numsSize)
            return -1;
    }
    for (i = 0; i < numsSize; i++)
        for (j = i + 1; j < numsSize; j++)
        {
            if (nums[i] == nums[j])
                return nums[i];
        }
    return -1;
}