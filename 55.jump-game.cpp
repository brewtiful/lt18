/*
 * [55] Jump Game
 *
 * https://leetcode.com/problems/jump-game/description/
 *
 * algorithms
 * Medium (29.69%)
 * Total Accepted:    170.7K
 * Total Submissions: 574.4K
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * Given an array of non-negative integers, you are initially positioned at the
 * first index of the array.
 * 
 * Each element in the array represents your maximum jump length at that
 * position.
 * 
 * Determine if you are able to reach the last index.
 * 
 * Example 1:
 * 
 * 
 * Input: [2,3,1,1,4]
 * Output: true
 * Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last
 * index.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,2,1,0,4]
 * Output: false
 * Explanation: You will always arrive at index 3 no matter what. Its
 * maximum
 * jump length is 0, which makes it impossible to reach the last index.
 * 
 * 
 */
// why init with n-2 doesn't work?
class Solution {
public:
    bool canJump(vector<int>& nums) {
	int n = nums.size();
	int goodPosition = n-1;
        for (int i = n-2; i >= 0; i--) {
		if (i+nums[i] >= goodPosition) {
			goodPosition = i;
		}
        }
        return goodPosition == 0;        
    }
};
