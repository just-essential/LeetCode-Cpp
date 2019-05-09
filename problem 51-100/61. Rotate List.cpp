/*
Given a linked list, rotate the list to the right by k places, where k is non-negative.

Example 1:

Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL
Explanation:
rotate 1 steps to the right: 5->1->2->3->4->NULL
rotate 2 steps to the right: 4->5->1->2->3->NULL
Example 2:

Input: 0->1->2->NULL, k = 4
Output: 2->0->1->NULL
Explanation:
rotate 1 steps to the right: 2->0->1->NULL
rotate 2 steps to the right: 1->2->0->NULL
rotate 3 steps to the right: 0->1->2->NULL
rotate 4 steps to the right: 2->0->1->NULL
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
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head || !k)
            return head;
        int length = 1;
        ListNode *p, *rear = head;
        while (rear->next) {
            rear = rear->next;
            length++;
        }
        int n = k % length + 1, m;
        m = length - n;
        p = head;
        while (m--) {
            p = p->next;
        }
        rear->next = head;
        head = p->next;
        p->next = nullptr;
        return head;
    }

    void test() {
        assert(listNodeToString(rotateRight(stringToListNode("[1,2,3,4,5]"), 2)) == "[4, 5, 1, 2, 3]");
        assert(listNodeToString(rotateRight(stringToListNode("[0,1,2]"), 4)) == "[2, 0, 1]");
    }
};