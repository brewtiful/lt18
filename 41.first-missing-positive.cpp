/*
 * [41] First Missing Positive
 *
 * https://leetcode.com/problems/first-missing-positive/description/
 *
 * algorithms
 * Hard (26.04%)
 * Total Accepted:    136.9K
 * Total Submissions: 525.2K
 * Testcase Example:  '[1,2,0]'
 *
 * Given an unsorted integer array, find the smallest missing positive
 * integer.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,0]
 * Output: 3
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,4,-1,1]
 * Output: 2
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [7,8,9,11,12]
 * Output: 1
 * 
 * 
 * Note:
 * 
 * Your algorithm should run in O(n) time and uses constant extra space.
 * 
 */
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
	int n = nums.size();
	if (! n) return 1;
	for (int i = 0; i < n; i++) {
		while (nums[i] > 0 && nums[nums[i]] != nums[i] && nums[i] < n) swap(nums[nums[i]], nums[i]);
		if (nums[i] == n) nums.push_back(n);
	}
	for (int i = 1; i <= n; i++) {
		if (nums[i] != i) return i; 
	}
	return n+1;
    }
};
