/*
 * [59] Spiral Matrix II
 *
 * https://leetcode.com/problems/spiral-matrix-ii/description/
 *
 * algorithms
 * Medium (41.47%)
 * Total Accepted:    103.2K
 * Total Submissions: 248.4K
 * Testcase Example:  '3'
 *
 * Given a positive integer n, generate a square matrix filled with elements
 * from 1 to n2 in spiral order.
 * 
 * Example:
 * 
 * 
 * Input: 3
 * Output:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 8, 9, 4 ],
 * ⁠[ 7, 6, 5 ]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
	int l = 0, k = 0, t = n, m = n;
        if (! n) return ans;
	int count = 0;
        while(count < t*t) {
                for (int i = l; i < n && count < t*t; i++) {
                        ans[k][i] = ++count;
                }
		k++;
                for (int i = k; i < m && count < t*t; i++) {
                        ans[i][n-1] = ++count;
                }
                n--;
                for (int i = n-1; i >= l && count < t*t; --i) {
                        ans[m-1][i] = ++count;
                }
                m--;
                for (int i = m-1; i >= k && count < t*t; --i) {
                	ans[i][l] = ++count;
                }
                l++; 
        }
        return ans;        
    }
};
