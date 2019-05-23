/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

Example 1:

Input: 1->1->2
Output: 1->2
Example 2:

Input: 1->1->2->3->3
Output: 1->2->3
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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *pre = head, *cur;
        while (pre) {
            cur = pre->next;
            if (cur && cur->val == pre->val) {
                pre->next = cur->next;
            } else {
                pre = pre->next;
            }
        }
        return head;
    }

    void test() {
        assert(listNodeToString(deleteDuplicates(stringToListNode("[1,1,2]"))) == "[1, 2]");
        assert(listNodeToString(deleteDuplicates(stringToListNode("[1,1,2,3,3]"))) == "[1, 2, 3]");
    }
};