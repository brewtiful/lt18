/*
 * [6] ZigZag Conversion
 *
 * https://leetcode.com/problems/zigzag-conversion/description/
 *
 * algorithms
 * Medium (27.51%)
 * Total Accepted:    210.9K
 * Total Submissions: 765.8K
 * Testcase Example:  '"PAYPALISHIRING"\n3'
 *
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number
 * of rows like this: (you may want to display this pattern in a fixed font for
 * better legibility)
 * 
 * 
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * 
 * 
 * And then read line by line: "PAHNAPLSIIGYIR"
 * 
 * Write the code that will take a string and make this conversion given a
 * number of rows:
 * 
 * 
 * string convert(string s, int numRows);
 * 
 * Example 1:
 * 
 * 
 * Input: s = "PAYPALISHIRING", numRows = 3
 * Output: "PAHNAPLSIIGYIR"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "PAYPALISHIRING", numRows = 4
 * Output: "PINALSIGYAHRPI"
 * Explanation:
 * 
 * P     I    N
 * A   L S  I G
 * Y A   H R
 * P     I
 * 
 */
class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
	int k = 0;
	string ans;
	if (numRows == 1) return s;
	int curRow = 0;
	string v[numRows];
	for (int i = 0; i < n; i++) {
		v[curRow].push_back(s[i]);
		if (curRow == numRows-1) k = -1;
		else if (curRow == 0) k = 1;
		k == 1 ? curRow++ : curRow--;		
	}
	for (int i = 0; i < numRows; i++) {
		ans += v[i];
	}
	return ans;
    }
};
