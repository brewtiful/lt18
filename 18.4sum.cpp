/*
 * [18] 4Sum
 *
 * https://leetcode.com/problems/4sum/description/
 *
 * algorithms
 * Medium (27.65%)
 * Total Accepted:    158K
 * Total Submissions: 571.2K
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * Given an array nums of n integers and an integer target, are there elements
 * a, b, c, and d in nums such that a + b + c + d = target? Find all unique
 * quadruplets in the array which gives the sum of target.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate quadruplets.
 * 
 * Example:
 * 
 * 
 * Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
 * 
 * A solution set is:
 * [
 * ⁠ [-1,  0, 0, 1],
 * ⁠ [-2, -1, 1, 2],
 * ⁠ [-2,  0, 0, 2]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
	int n = nums.size();
	vector<vector<int>> ans;
	if (! n) return ans;
	sort(nums.begin(), nums.end());
	for (int i = 0; i < n-3; i++) {
		for (int j = i+1; j < n-2; j++) {
			int l = j+1, r = n-1;
			while (l < r) {
				if (nums[i]+nums[j]+nums[l]+nums[r] == target) {
					vector<int> tmp = {nums[i], nums[j], nums[l], nums[r]};
					ans.push_back(tmp);
					// while (l+1 < n && nums[l] == nums[++l]) l++;
					// while (r-1 >= 0 && nums[r] == nums[--r]) r--;
					while (l+1 < n && nums[l] == nums[l+1]) l++;
					l++;
					while (r-1 >= 0 && nums[r] == nums[r-1]) r--;
					r--;
				} 
				else if (nums[i]+nums[j]+nums[l]+nums[r] < target) l++;
				else if (nums[i]+nums[j]+nums[l]+nums[r] > target) r--;
			}
			while (nums[j] == nums[j+1]) j++;
		}
		while (nums[i] == nums[i+1]) i++;
	}
	return ans;        
    }
};
