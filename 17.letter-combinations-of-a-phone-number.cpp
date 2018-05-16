/*
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (36.75%)
 * Total Accepted:    238K
 * Total Submissions: 647.2K
 * Testcase Example:  '"23"'
 *
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent.
 * 
 * A mapping of digit to letters (just like on the telephone buttons) is given
 * below. Note that 1 does not map to any letters.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * Note:
 * 
 * Although the above answer is in lexicographical order, your answer could be
 * in any order you want.
 * 
 */
class Solution {
public:
    vector<string> letterCombinations(string digits) {
	int n = digits.size();
	vector<vector<char>> numToChar(8);
	vector<string> ans;
	if (!n) return ans;
	string tmp;
	numToChar[0] = {'a','b','c'};
	numToChar[1] = {'d','e','f'};
	numToChar[2] = {'g','h','i'};
	numToChar[3] = {'j','k','l'};
	numToChar[4] = {'m','n','o'};
	numToChar[5] = {'p','q','r','s'};
	numToChar[6] = {'t','u','v'};
	numToChar[7] = {'w','x','y','z'};
	f(0, digits, numToChar, ans, tmp);
	return ans;
    }
    void f(int index, string digits, vector<vector<char>>& numToChar, vector<string>& ans, string tmp) {
		if (index == digits.size()) {
			ans.push_back(tmp);
			return;
		}
		for (char t : numToChar[digits[index]-'0'-2]) {
			f(index+1, digits, numToChar, ans, tmp+t);
		}
    }
};
