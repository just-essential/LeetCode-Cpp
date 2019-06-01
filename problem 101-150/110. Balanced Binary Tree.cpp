/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example 1:

Given the following tree [3,9,20,null,null,15,7]:

    3
   / \
  9  20
    /  \
   15   7
Return true.

Example 2:

Given the following tree [1,2,2,3,3,null,null,4,4]:

       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
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
    bool isBalanced(TreeNode *root) {
        function<int(TreeNode *)> lambda;
        lambda = [&](TreeNode *root) {
            if (root != nullptr) {
                int leftDepth = lambda(root->left);
                int rightDepth = lambda(root->right);
                if (leftDepth == -1 || rightDepth == -1) {
                    // is not balanced
                    return -1;
                } else {
                    int depth = max(leftDepth, rightDepth) + 1;
                    return abs(leftDepth - rightDepth) <= 1 ? depth : -1;
                }
            } else {
                return 0;
            }
        };
        return lambda(root) != -1;
    }

    void test() {
        assert(isBalanced(stringToTreeNode("[3,9,20,null,null,15,7]")));
        assert(!isBalanced(stringToTreeNode("[1,2,2,3,3,null,null,4,4]")));
    }
};