/*
 * [22] Generate Parentheses
 *
 * https://leetcode.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (48.39%)
 * Total Accepted:    214.3K
 * Total Submissions: 441.7K
 * Testcase Example:  '3'
 *
 * 
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 * 
 * 
 * 
 * For example, given n = 3, a solution set is:
 * 
 * 
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]
 * 
 */
class Solution {
public:
    vector<string> generateParenthesis(int n) {
	int l = n, r = n;
	vector<string> ans;
	string tmp;
	f(l, r, ans, tmp);
	reverse(ans.begin(), ans.end());
	return ans;
    }
    void f(int l, int r, vector<string>& ans, string tmp) {
	if (l == 0 && r == 0) {
		ans.push_back(tmp);
		return;
	}
	if (l < r) {
		f(l, r-1, ans, tmp+')');
	}
	if (l > 0) f(l-1, r, ans, tmp+'(');
    }
};
