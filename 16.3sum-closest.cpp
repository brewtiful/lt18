/*
 * [16] 3Sum Closest
 *
 * https://leetcode.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (31.78%)
 * Total Accepted:    176.8K
 * Total Submissions: 556K
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * Given an array nums of n integers and an integer target, find three integers
 * in nums such that the sum is closest to target. Return the sum of the three
 * integers. You may assume that each input would have exactly one solution.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 2, 1, -4], and target = 1.
 * 
 * The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 * 
 * 
 */
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
	int n = nums.size();
	int ans = INT_MAX;
	int res = 0;
	sort(nums.begin(), nums.end());
	for (int i = 0; i < n-2; i++) {
		int l = i+1, r = n-1;
		while (l < r) {
			if (nums[i]+nums[l]+nums[r] == target) return target; 
			if (nums[i]+nums[l]+nums[r]-target > -ans && nums[i]+nums[l]+nums[r]-target < ans) {
				res = nums[i]+nums[l]+nums[r];
				ans = nums[i]+nums[l]+nums[r]-target > 0 ? nums[i]+nums[l]+nums[r]-target : -(nums[i]+nums[l]+nums[r]-target);
			}
			if (nums[i]+nums[l]+nums[r]-target > 0) {
				r--;
			} else if (nums[i]+nums[l]+nums[r]-target < 0) {
				l++;
			}
		}
	}
	return res;
    }
};
