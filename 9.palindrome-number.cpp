/*
 * [9] Palindrome Number
 *
 * https://leetcode.com/problems/palindrome-number/description/
 *
 * algorithms
 * Easy (36.24%)
 * Total Accepted:    332.8K
 * Total Submissions: 917.5K
 * Testcase Example:  '121'
 *
 * Determine whether an integer is a palindrome. An integer is a palindrome
 * when it reads the same backward as forward.
 * 
 * Example 1:
 * 
 * 
 * Input: 121
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: -121
 * Output: false
 * Explanation: From left to right, it reads -121. From right to left, it
 * becomes 121-. Therefore it is not a palindrome.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 10
 * Output: false
 * Explanation: Reads 01 from right to left. Therefore it is not a
 * palindrome.
 * 
 * 
 * Follow up:
 * 
 * Coud you solve it without converting the integer to a string?
 * 
 */
class Solution {
public:
    bool isPalindrome(int x) {
	if (x < 0) return false;
	if (x == 0) return true;
	vector<int> tmp;
	while (x > 0) {
		tmp.push_back(x%10);
		x /= 10;
	}
	int i = 0, j = tmp.size() -1;
	while (i <= j) {
		if (tmp[i] != tmp[j]) return false;
		i++;
		j--;
	}
	return true;     
    }
};
