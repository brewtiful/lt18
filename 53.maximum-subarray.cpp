/*
 * [53] Maximum Subarray
 *
 * https://leetcode.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (40.52%)
 * Total Accepted:    319.2K
 * Total Submissions: 787.4K
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * Given an integer array nums, find the contiguous subarray (containing at
 * least one number) which has the largest sum and return its sum.
 * 
 * Example:
 * 
 * 
 * Input: [-2,1,-3,4,-1,2,1,-5,4],
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 * 
 * 
 * Follow up:
 * 
 * If you have figured out the O(n) solution, try coding another solution using
 * the divide and conquer approach, which is more subtle.
 * 
 */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
	int n = nums.size();
	int curSum = 0;
	int ans = INT_MIN;
	for (int i = 0; i < n; i++) {
		if (curSum < 0) curSum = 0;
		curSum += nums[i];
		ans = max(ans, curSum);
	}        
	return ans;
    }
};
