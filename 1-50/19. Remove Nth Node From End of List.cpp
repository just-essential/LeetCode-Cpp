/*
Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

Given n will always be valid.

Follow up:

Could you do this in one pass?
*/
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        decltype(head) current, nTh, pre;
        current = nTh = head;
        pre = nullptr;
        for (int i = 1; current != nullptr; ++i) {
            if (i > n) {
                pre = nTh;
                nTh = nTh->next;
            } else if (i == n) {
                nTh = head;
            }
            current = current->next;
        }
        if (pre != nullptr) {
            pre->next = nTh->next;
        } else {
            head = nTh->next;
        }
        return head;
    }

    void test() {
        assert(listNodeToString(removeNthFromEnd(stringToListNode("[1,2,3,4,5]"), 2)) == "[1, 2, 3, 5]");
    }
};