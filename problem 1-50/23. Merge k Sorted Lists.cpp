/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:

Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6
*/

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        int step = 1, len = static_cast<int>(lists.size());
        while (step < len) {
            for (int i = 0; i < len - step; i += step << 1) {
                lists[i] = mergeTwoLists(lists[i], lists[i + step]);
            }
            step <<= 1;
        }
        return len > 0 ? lists[0] : nullptr;
    }

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
        l3->next = l1 ? l1 : l2;
        return head.next;
    }

    void test() {
        vector<ListNode *> lists{stringToListNode("[1,4,5]"), stringToListNode("[1,3,4]"), stringToListNode("[2,6]")};
        assert(listNodeToString(mergeKLists(lists)) == "[1, 1, 2, 3, 4, 4, 5, 6]");
    }
};