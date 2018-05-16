/*
 * [19] Remove Nth Node From End of List
 *
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (33.95%)
 * Total Accepted:    250.3K
 * Total Submissions: 737.3K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given a linked list, remove the n-th node from the end of list and return
 * its head.
 * 
 * Example:
 * 
 * 
 * Given linked list: 1->2->3->4->5, and n = 2.
 * 
 * After removing the second node from the end, the linked list becomes
 * 1->2->3->5.
 * 
 * 
 * Note:
 * 
 * Given n will always be valid.
 * 
 * Follow up:
 * 
 * Could you do this in one pass?
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
	// how to do in one pass? need to count the length of the list first.
	int lenth = 0;
	ListNode* p = head;
	while (p) {
		p = p->next;
		lenth++;
	}
	int move = lenth-n;
	p = new ListNode(0);
	p->next = head;
	ListNode* ans = p;
	while (move--) {
		p = p->next;
	}        
	p->next = p->next->next;
	return ans->next;
    }
};
