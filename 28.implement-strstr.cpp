/*
 * [28] Implement strStr()
 *
 * https://leetcode.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (29.18%)
 * Total Accepted:    276.5K
 * Total Submissions: 947.5K
 * Testcase Example:  '"hello"\n"ll"'
 *
 * Implement strStr().
 * 
 * Return the index of the first occurrence of needle in haystack, or -1 if
 * needle is not part of haystack.
 * 
 * Example 1:
 * 
 * 
 * Input: haystack = "hello", needle = "ll"
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: haystack = "aaaaa", needle = "bba"
 * Output: -1
 * 
 * 
 * Clarification:
 * 
 * What should we return when needle is an empty string? This is a great
 * question to ask during an interview.
 * 
 * For the purpose of this problem, we will return 0 when needle is an empty
 * string. This is consistent to C's strstr() and Java's indexOf().
 * 
 */
class Solution {
public:
    int strStr(string haystack, string needle) {
	int m = needle.size();
	if (! m) return 0;
	int n = haystack.size();
        if (!n) return -1;
	for (int i = 0; i <= n-m; i++) {
		int j = 0;
		for (; j < m; j++) {
			if (haystack[i+j] != needle[j]) break; 
		}
		if (j == m) return i;
	}        
	return -1;
    }
};
