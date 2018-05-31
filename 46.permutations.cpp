/*
 * [46] Permutations
 *
 * https://leetcode.com/problems/permutations/description/
 *
 * algorithms
 * Medium (47.95%)
 * Total Accepted:    242.6K
 * Total Submissions: 505.3K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a collection of distinct integers, return all possible permutations.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3]
 * Output:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
	int n = nums.size();
	vector<vector<int>> ans;
	if (! n) return ans;
	vector<int> visited(n);
	vector<int> tmp;
	find(nums, ans, visited, tmp);
	return ans;        
    }
    void find(vector<int>& nums, vector<vector<int>>& ans, vector<int>& visited, vector<int>& tmp) {
   	if (tmp.size() == nums.size()) {
		ans.push_back(tmp);
		return;
	}
	for (int i = 0; i < nums.size(); i++) {
		if (visited[i]) continue;
		tmp.push_back(nums[i]);
		visited[i] = 1;
		find(nums, ans, visited, tmp);
		visited[i] = 0;
		tmp.pop_back();
	}
    }
};
