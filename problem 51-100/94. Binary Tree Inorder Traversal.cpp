/*
Given a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]
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
    vector<int> inorderTraversal(TreeNode *root) {
        stack<TreeNode *> s;
        vector<int> result;
        TreeNode *temp = root;
        while (!s.empty() || temp) {
            if (temp) {
                s.push(temp);
                temp = temp->left;
            } else {
                temp = s.top();
                s.pop();
                result.push_back(temp->val);
                temp = temp->right;
            }
        }
        return result;
    }

    void test() {
        assert(inorderTraversal(stringToTreeNode("[1,null,2,3]")) == vector<int>({1, 3, 2}));
    }
};