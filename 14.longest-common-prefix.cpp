/*
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (31.64%)
 * Total Accepted:    274.6K
 * Total Submissions: 867.7K
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 * 
 * If there is no common prefix, return an empty string "".
 * 
 * Example 1:
 * 
 * 
 * Input: ["flower","flow","flight"]
 * Output: "fl"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 * 
 * 
 * Note:
 * 
 * All given inputs are in lowercase letters a-z.
 * 
 */
// how to know the shortest word?
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
	int n = strs.size();
	string ans;
	if (! n) return ans;
	for (int i = 0; i < strs[0].size(); i++) { // which index
		for (int j = 1; j < n; j++) { // which string
			if (strs[j].size() < i || strs[j][i] != strs[0][i]) return ans;
		}
		ans = strs[0].substr(0, i+1);
	}
	return ans;        
    }
};
