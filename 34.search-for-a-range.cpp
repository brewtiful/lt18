/*
 * [34] Search for a Range
 *
 * https://leetcode.com/problems/search-for-a-range/description/
 *
 * algorithms
 * Medium (31.69%)
 * Total Accepted:    194.8K
 * Total Submissions: 614.7K
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * Given an array of integers nums sorted in ascending order, find the starting
 * and ending position of a given target value.
 * 
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * 
 * If the target is not found in the array, return [-1, -1].
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [5,7,7,8,8,10], target = 8
 * Output: [3,4]
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [5,7,7,8,8,10], target = 6
 * Output: [-1,-1]
 * 
 */
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
	int n = nums.size();
	if (! n) return {-1,-1};
	vector<int> ans;
	int l = 0, r = n-1;
	while (l <= r) {
		int m = (l+r)/2;
		if (nums[m] == target) {
			find(m, nums, target, ans);
			return ans;
		}
		else if (nums[m] < target) l = m+1;
		else r = m-1;
	}
	return {-1, -1};
    }
    void find(int m, vector<int>& nums, int target, vector<int>& ans) {
	int l = m, r = m;
	while (l >= 0 && nums[l] == target) l--;
	while (r < nums.size() && nums[r] == target) r++;
	ans.push_back(l+1);
	ans.push_back(r-1); 
	return;       
    }
};
