/**题目:
给定一个长度为 n+1 的数组nums，数组中所有的数均在 1∼n 的范围内，其中 n≥1。

请找出数组中任意一个重复的数，但不能修改输入的数组。

样例
给定 nums = [2, 3, 5, 4, 3, 2, 6, 7]。

返回 2 或 3。
思考题：如果只能使用 O(1) 的额外空间，该怎么做呢？**/
//思路桶排序法
int duplicateInArray(int *nums, int numsSize)
{
    int i, book[numsSize + 1];
     for (i = 1; i <= numsSize; i++)
    {
        book[i]=0;
    }
    for (i = 0; i < numsSize; i++)
    {
        book[nums[i]]++;
    }
    for (i = 1; i <=numsSize; i++)
    {
        if (book[i] > 1)
            return i;
    }
    return -1;
}