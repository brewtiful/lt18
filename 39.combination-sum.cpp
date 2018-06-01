/*
 * [39] Combination Sum
 *
 * https://leetcode.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (41.95%)
 * Total Accepted:    224.5K
 * Total Submissions: 534.3K
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * Given a set of candidate numbers (candidates) (without duplicates) and a
 * target number (target), find all unique combinations in candidates where the
 * candidate numbers sums to target.
 * 
 * The same repeated number may be chosen from candidates unlimited number of
 * times.
 * 
 * Note:
 * 
 * 
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: candidates = [2,3,6,7], target = 7,
 * A solution set is:
 * [
 * ⁠ [7],
 * ⁠ [2,2,3]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,3,5], target = 8,
 * A solution set is:
 * [
 * [2,2,2,2],
 * [2,3,3],
 * [3,5]
 * ]
 * 
 * 
 */
// this problem can't use dp, so just normal dfs?
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	int n = candidates.size();
	vector<vector<int>> ans;
	if (! n) return ans;
	vector<int> tmp;
	sort(candidates.begin(), candidates.end());
	dfs(0, ans, tmp, candidates, target);
	return ans;        
    }
    void dfs(int start, vector<vector<int>>& ans, vector<int>& tmp, vector<int>& candidates, int target) {
	if (target == 0) {
		ans.push_back(tmp);
		return;
	}
	for (int i = start; i < candidates.size(); i++) {
		if (candidates[i] > target) return;
		tmp.push_back(candidates[i]);
		dfs(i,ans,tmp, candidates, target-candidates[i]);
		tmp.pop_back();  
	}
    }
};
