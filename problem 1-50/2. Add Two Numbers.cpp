/*
You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order and each of their nodes contain a single digit.
Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode head(0), *p = &head;
        auto sum = 0;
        while (l1 || l2 || sum) {
            sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + sum;
            p = p->next = new ListNode(sum % 10);
            sum /= 10;
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
        }
        return head.next;
    }

    void test() {
        assert(listNodeToString(addTwoNumbers(stringToListNode("[2,4,3]"), stringToListNode("[5,6,4]"))) ==
               "[7, 0, 8]");
    }
};