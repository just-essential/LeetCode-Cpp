/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

Example:

Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

Note:

Only constant extra memory is allowed.
You may not alter the values in the list's nodes, only nodes itself may be changed.
*/
class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode dummy(0);
        ListNode *prev, *rear, *next;
        dummy.next = head;
        prev = &dummy;
        rear = prev;
        while (rear->next) {
            for (int i = 0; i < k; ++i) {
                rear = rear->next;
                if (!rear) {
                    return dummy.next;
                }
            }
            head = prev->next;
            for (int i = 1; i < k; ++i) {
                next = head->next;
                head->next = next->next;
                next->next = prev->next;
                prev->next = next;
            }
            rear = prev = head;
        }
        return dummy.next;
    }

    void test() {
        assert(listNodeToString(reverseKGroup(stringToListNode("[1,2,3,4,5]"), 2)) == "[2, 1, 4, 3, 5]");
        assert(listNodeToString(reverseKGroup(stringToListNode("[1,2,3,4,5]"), 3)) == "[3, 2, 1, 4, 5]");
    }
};