/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
*/

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode head(0), *l3 = &head;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                l3->next = l1;
                l1 = l1->next;
            } else {
                l3->next = l2;
                l2 = l2->next;
            }
            l3 = l3->next;
        }
        if (l1) {
            l3->next = l1;
        } else {
            l3->next = l2;
        }
        return head.next;
    }

    void test() {
        assert(listNodeToString(mergeTwoLists(stringToListNode("[1,2,4]"), stringToListNode("[1,3,4]"))) ==
               "[1, 1, 2, 3, 4, 4]");
    }
};