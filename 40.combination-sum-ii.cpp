/*
 * [40] Combination Sum II
 *
 * https://leetcode.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (36.42%)
 * Total Accepted:    155.3K
 * Total Submissions: 426K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * Given a collection of candidate numbers (candidates) and a target number
 * (target), find all unique combinations in candidates where the candidate
 * numbers sums to target.
 * 
 * Each number in candidates may only be used once in the combination.
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
 * Input: candidates = [10,1,2,7,6,1,5], target = 8,
 * A solution set is:
 * [
 * ⁠ [1, 7],
 * ⁠ [1, 2, 5],
 * ⁠ [2, 6],
 * ⁠ [1, 1, 6]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,5,2,1,2], target = 5,
 * A solution set is:
 * [
 * [1,2,2],
 * [5]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
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
                dfs(i+1,ans,tmp, candidates, target-candidates[i]);
                tmp.pop_back();
		while(i+1 < candidates.size() && candidates[i] == candidates[i+1]) i++;
        }
    }
};
