/*
 * [54] Spiral Matrix
 *
 * https://leetcode.com/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (27.49%)
 * Total Accepted:    147.3K
 * Total Submissions: 535K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * Given a matrix of m x n elements (m rows, n columns), return all elements of
 * the matrix in spiral order.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 4, 5, 6 ],
 * ⁠[ 7, 8, 9 ]
 * ]
 * Output: [1,2,3,6,9,8,7,4,5]
 * 
 * 
 * Example 2:
 * 
 * Input:
 * [
 * ⁠ [1, 2, 3, 4],
 * ⁠ [5, 6, 7, 8],
 * ⁠ [9,10,11,12]
 * ]
 * Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 * 
 */
class Solution {
public:
    int k = 0, m = 0, l = 0, n = 0;
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
	m = matrix.size();
	vector<int> ans;
	if (! m) return ans;
	n = matrix[0].size();
	while(k < m && l < n) {
		for (int i = l; i < n; i++) {
			ans.push_back(matrix[k][i]);
		}
		k++;
		for (int i = k; i < m; i++) {
			ans.push_back(matrix[i][n-1]);
		}
		n--;
		if (k < m) {
            		for (int i = n-1; i >= l; --i) {
                		ans.push_back(matrix[m-1][i]);
            		}
            		m--;
		}
		if (l < n) {
           		 for (int i = m-1; i >= k; --i) {
               			 ans.push_back(matrix[i][l]);
            		}
            		l++;
        	}
	}
	return ans;
    }
};
