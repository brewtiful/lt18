/*
 * [1] Two Sum
 *
 * https://leetcode.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (38.17%)
 * Total Accepted:    908.7K
 * Total Submissions: 2.4M
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * Given an array of integers, return indices of the two numbers such that they
 * add up to a specific target.
 * 
 * You may assume that each input would have exactly one solution, and you may
 * not use the same element twice.
 * 
 * Example:
 * 
 * 
 * Given nums = [2, 7, 11, 15], target = 9,
 * 
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
	unordered_map<int, int> um;
	vector<int> ans;
	for (int i = 0; i < nums.size(); i++) {
		if (um.find(target-nums[i]) != um.end()) {
			ans.push_back(um[target-nums[i]]);
			ans.push_back(i);
			return ans;
		}	
		else um[nums[i]] = i;
	}
    }
};
