/*
Reverse a linked list from position m to n. Do it in one-pass.

Note: 1 ≤ m ≤ n ≤ length of list.

Example:

Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL
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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        stack<ListNode *> s;
        auto flag = new ListNode(0);
        flag->next = head;
        int i = 1;
        ListNode *start = head, *temp;
        // Note: 1 ≤ m ≤ n ≤ length of list.
        while (i < m) {
            start = start->next;
            i++;
        }
        temp = start;
        while (i < (m + n) / 2) {
            temp = temp->next;
            i++;
        }
        while (i < n) {
            temp = temp->next;
            s.push(temp);
            i++;
        }
        while (!s.empty()) {
            swap(s.top()->val, start->val);
            start = start->next;
            s.pop();
        }
        head = flag->next;
        delete flag;
        return head;
    }

    void test() {
        assert(listNodeToString(reverseBetween(stringToListNode("[1,2,3,4,5]"), 2, 4)) == "[1, 4, 3, 2, 5]");
    }
};