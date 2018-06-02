/*
 * [45] Jump Game II
 *
 * https://leetcode.com/problems/jump-game-ii/description/
 *
 * algorithms
 * Hard (26.09%)
 * Total Accepted:    118.1K
 * Total Submissions: 452.3K
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * Given an array of non-negative integers, you are initially positioned at the
 * first index of the array.
 * 
 * Each element in the array represents your maximum jump length at that
 * position.
 * 
 * Your goal is to reach the last index in the minimum number of jumps.
 * 
 * Example:
 * 
 * 
 * Input: [2,3,1,1,4]
 * Output: 2
 * Explanation: The minimum number of jumps to reach the last index is 2.
 * ⁠   Jump 1 step from index 0 to 1, then 3 steps to the last index.
 * 
 * Note:
 * 
 * You can assume that you can always reach the last index.
 */
// tle for this kind of dp. time complexity is o(n^2). how to improve?
class Solution {
public:
    int jump(vector<int>& nums) {
	int n = nums.size();
	if (! n) return 0;
	int lastReach = 0;
	int reach = 0;
	int step = 0;
	for (int i = 0; i <= reach && i < n; i++) {
		if (i > lastReach) {
			step++;
			lastReach = reach;
		}
		reach = max(reach, nums[i]+i);
	}        
	if (reach < n-1) return 0; 
	return step;
    }
};
