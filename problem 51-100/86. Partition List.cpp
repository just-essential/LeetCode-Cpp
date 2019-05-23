/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

Example:

Input: head = 1->4->3->2->5->2, x = 3
Output: 1->2->2->4->3->5
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
    ListNode *partition(ListNode *head, int x) {
        auto flag = new ListNode(0);
        flag->next = head;
        head = flag;
        while (flag->next && flag->next->val < x) {
            flag = flag->next;
        }
        auto pre = flag, temp = pre->next;
        while (temp) {
            if (temp->val < x) {
                pre->next = temp->next;
                temp->next = flag->next;
                flag = flag->next = temp;
            } else pre = pre->next;
            temp = pre->next;
        }
        temp = head->next;
        delete head;
        return temp;
    }

    void test() {
        assert(listNodeToString(partition(stringToListNode("[1,4,3,2,5,2]"), 3)) == "[1, 2, 2, 4, 3, 5]");
    }
};