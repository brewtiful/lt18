/*
 * [21] Merge Two Sorted Lists
 *
 * https://leetcode.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (41.48%)
 * Total Accepted:    352K
 * Total Submissions: 845.8K
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * Merge two sorted linked lists and return it as a new list. The new list
 * should be made by splicing together the nodes of the first two lists.
 * 
 * Example:
 * 
 * Input: 1->2->4, 1->3->4
 * Output: 1->1->2->3->4->4
 * 
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	ListNode* head = new ListNode(-1);
	ListNode* p = head;
	while (l1 || l2) {
		if (! l1) {
			head->next = l2;
			return p->next;
		}
        	else if (! l2) {
			head->next = l1;
			return p->next;
		}
		if (l1->val < l2->val) {
			head->next = l1;
			l1 = l1->next;
		} else {
			head->next = l2;
			l2 = l2->next;
		}
		head = head->next;
	}
	return p->next;	
    }
};
