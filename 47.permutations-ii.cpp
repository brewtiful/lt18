/*
 * [47] Permutations II
 *
 * https://leetcode.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (35.48%)
 * Total Accepted:    167.5K
 * Total Submissions: 471.6K
 * Testcase Example:  '[1,1,2]'
 *
 * Given a collection of numbers that might contain duplicates, return all
 * possible unique permutations.
 * 
 * Example:
 * 
 * 
 * Input: [1,1,2]
 * Output:
 * [
 * ⁠ [1,1,2],
 * ⁠ [1,2,1],
 * ⁠ [2,1,1]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
	int n = nums.size();
	vector<vector<int>> ans;
	if (! n) return ans;
	sort(nums.begin(), nums.end());
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
		while (i < nums.size() && nums[i] == nums[i+1]) i++;
        }
    }
};
