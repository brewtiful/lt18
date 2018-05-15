/*
 * [11] Container With Most Water
 *
 * https://leetcode.com/problems/container-with-most-water/description/
 *
 * algorithms
 * Medium (37.17%)
 * Total Accepted:    200.5K
 * Total Submissions: 539.2K
 * Testcase Example:  '[1,1]'
 *
 * Given n non-negative integers a1, a2, ..., an, where each represents a point
 * at coordinate (i, ai). n vertical lines are drawn such that the two
 * endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together
 * with x-axis forms a container, such that the container contains the most
 * water.
 * 
 * Note: You may not slant the container and n is at least 2.
 * 
 */
// set a variable to keep track of the current lowest height, then if a new line comes in, if it's even lower, then we may choose to start from that line+1 in the future, to exclude that line.
// But don't know what's the current lowest from that line.
// DP? Because the later solution is related to previous solution. But is it optimal subproblem? Yes, so we can't use dp?
// two pointer? How?
// I think too difficult. This only requires two lines and the base to form a container, it doesn't matter what are the lines between them.
// So time complexity is o(n).
class Solution {
public:
    int maxArea(vector<int>& height) {
	int ans = 0;
	int n = height.size();
	int l = 0, r = n-1;
	while (l < r) {
		ans = max(ans, min(height[l], height[r])*(r-l));
		height[l] < height[r] ? l++ : r--;
	}
	return ans;       
    }
};
