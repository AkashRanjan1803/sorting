// You are given an integer array nums of length n and an integer target.
// Find three integers at distinct indices in nums such that the sum is closest to target.
// Return the sum of the three integers.
// You may assume that each input would have exactly one solution.
// Example 1:
// Input: nums = [-1,2,1,-4], target = 1
// Output: 2
// Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
// Example 2:
// Input: nums = [0,0,0], target = 1
// Output: 0
// Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).
// Constraints:
// 3 <= nums.length <= 500
// -1000 <= nums[i] <= 1000
// -104 <= target <= 104

#include <stdlib.h>
int compare(const void *a, const void *b)
{
    int x = *(int *)a;
    int y = *(int *)b;
    return (x > y) - (x < y);
}
int threeSumClosest(int* nums, int numsSize, int target)
{
    qsort(nums, numsSize, sizeof(int), compare);

    int closest = nums[0] + nums[1] + nums[2];

    for(int i = 0; i < numsSize - 2; i++)
    {
        int left = i + 1;
        int right = numsSize - 1;
        while(left < right)
        {
            int sum = nums[i] + nums[left] + nums[right];

            if(abs(target - sum) < abs(target - closest))
            {
                closest = sum;
            }

            if(sum == target)
            {
                return sum;
            }
            else if(sum < target)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }
    return closest;
}
