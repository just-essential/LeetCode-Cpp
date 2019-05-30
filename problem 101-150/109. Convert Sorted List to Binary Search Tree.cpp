/*
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example:

Given the sorted linked list: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        auto ptr = head;
        int size = 0;
        while (ptr != nullptr) {
            ptr = ptr->next;
            ++size;
        }
        function<TreeNode *(int, int)> lambda;
        lambda = [&](int begin, int end) -> TreeNode * {
            if (begin == end) {
                return nullptr;
            }
            int mid = (begin + end) / 2;
            auto left = lambda(begin, mid);
            auto root = new TreeNode(head->val);
            root->left = left;
            head = head->next;
            root->right = lambda(mid + 1, end);
            return root;
        };
        return lambda(0, size);
    }

    void test() {
        assert(treeNodeToString(sortedListToBST(stringToListNode("[-10,-3,0,5,9]"))) ==
               "[0, -3, 9, -10, null, 5, null, null, null, null, null]");
    }
};