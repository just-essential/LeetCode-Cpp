/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
 

But the following [1,2,2,null,3,null,3] is not:

    1
   / \
  2   2
   \   \
   3    3
 

Note:
Bonus points if you could solve it both recursively and iteratively.
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
    bool isSymmetric(TreeNode *root) {
        function<bool(TreeNode *, TreeNode *)> isMirror;
        isMirror = [&isMirror](TreeNode *left, TreeNode *right) {
            if (left == nullptr || right == nullptr) {
                return left == right;
            }
            if (left->val == right->val) {
                return isMirror(left->left, right->right) && isMirror(left->right, right->left);
            }
            return false;
        };
        return root == nullptr || isMirror(root->left, root->right);
    }

    void test() {
        assert(isSymmetric(stringToTreeNode("[1,2,2,3,4,4,3]")));
        assert(!isSymmetric(stringToTreeNode("[1,2,2,null,3,null,3]")));
    }
};