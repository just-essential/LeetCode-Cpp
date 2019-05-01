/*
Given a linked list, swap every two adjacent nodes and return its head.

You may not modify the values in the list's nodes, only nodes itself may be changed.


Example:

Given 1->2->3->4, you should return the list as 2->1->4->3.
*/

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *next, *prev;
        prev = &dummy;
        while (head && head->next) {
            next = head->next;
            head->next = next->next;
            next->next = head;
            head = head->next;
            prev->next = next;
            prev = next->next;
        }
        return dummy.next;
    }

    void test() {
        assert(listNodeToString(swapPairs(stringToListNode("[1,2,3,4]"))) == "[2, 1, 4, 3]");
    }
};