/*
 * Longest Increasing Subsequence (LIS)
 * ------------------------------------
 * Given an array of integers, find the length of the longest strictly
 * increasing subsequence.
 *
 * Example:
 * Input:  [10, 9, 2, 5, 3, 7, 101, 18]
 * Output: 4
 * Explanation: The LIS is [2, 3, 7, 101]
 *
 * Time Complexity: O(n^2)
 * Space Complexity: O(n)
 */

#include <stdio.h>

int lengthOfLIS(int* nums, int n) {
    if (n == 0) return 0;
    int dp[n];
    for (int i = 0; i < n; i++) dp[i] = 1;

    int maxLen = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j] && dp[i] < dp[j] + 1)
                dp[i] = dp[j] + 1;
        }
        if (dp[i] > maxLen)
            maxLen = dp[i];
    }

    return maxLen;
}

int main() {
    int nums[] = {10, 9, 2, 5, 3, 7, 101, 18};
    int n = sizeof(nums) / sizeof(nums[0]);

    printf("Length of LIS: %d\n", lengthOfLIS(nums, n));
    return 0;
}
