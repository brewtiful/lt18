/*
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (21.80%)
 * Total Accepted:    326K
 * Total Submissions: 1.5M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array nums of n integers, are there elements a, b, c in nums such
 * that a + b + c = 0? Find all unique triplets in the array which gives the
 * sum of zero.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate triplets.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 0, 1, 2, -1, -4],
 * 
 * A solution set is:
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
	int n = nums.size();
	vector<vector<int>> ans;
	sort(nums.begin(), nums.end());
	for (int i = 0; i < n-2; i++) {
		check2Sum(ans, nums, i);
		while(nums[i+1] == nums[i]) i++;
	} 
	return ans;
    }
    
    void check2Sum(vector<vector<int>>& ans, vector<int>& nums, int index) {
    	int l = index+1, r = nums.size()-1;
	while (l < r) {
		if (nums[l]+nums[r]+nums[index] == 0) {
			vector<int> v(3);
			v[0] = nums[index];
			v[1] = nums[l];
			v[2] = nums[r];
			ans.push_back(v);
			while (l < r && nums[l] == nums[l+1]) l++;
			while (r > l && nums[r] == nums[r-1]) r--;
			l++;
			r--;
		} else if (nums[l]+nums[r]+nums[index] < 0) {
			while (l < r && nums[l] == nums[l+1]) l++;
			l++;
		} else if (nums[l]+nums[r]+nums[index] > 0) {
			while (r > l && nums[r] == nums[r-1]) r--;
			r--; 
		}
	}
    }
};


































