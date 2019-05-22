/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

Example 1:

Input: 1->2->3->3->4->4->5
Output: 1->2->5
Example 2:

Input: 1->1->1->2->3
Output: 2->3
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
        int temp;
        ListNode *cur, *pre = new ListNode(0);
        pre->next = head;
        head = pre;
        while (pre) {
            cur = pre->next;
            if (cur && cur->next && cur->val == cur->next->val) {
                temp = cur->val;
                cur = cur->next->next;
                while (cur && cur->val == temp) {
                    cur = cur->next;
                }
                pre->next = cur;
            } else {
                pre = pre->next;
            }
        }
        return head->next;
    }

    void test() {
        assert(listNodeToString(deleteDuplicates(stringToListNode("[1,2,3,3,4,4,5]"))) == "[1, 2, 5]");
        assert(listNodeToString(deleteDuplicates(stringToListNode("[1,1,1,2,3]"))) == "[2, 3]");
    }
};