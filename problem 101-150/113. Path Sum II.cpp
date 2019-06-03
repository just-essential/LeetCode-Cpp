/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1
Return:

[
   [5,4,11,2],
   [5,8,4,5]
]
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
    vector<vector<int>> pathSum(TreeNode *root, int sum) {
        vector<vector<int>> result;
        vector<int> temp;
        function<void(TreeNode *, int)> lambda;
        lambda = [&](TreeNode *root, int sum) {
            if (root != nullptr) {
                temp.push_back(root->val);
                if (root->left == nullptr && root->right == nullptr) {
                    if (root->val == sum) {
                        result.push_back(temp);
                    }
                } else {
                    lambda(root->left, sum - root->val);
                    lambda(root->right, sum - root->val);
                }
                temp.pop_back();
            }
        };
        lambda(root, sum);
        return result;
    }

    void test() {
        assert(pathSum(stringToTreeNode("[5,4,8,11,null,13,4,7,2,null,null,5,1]"), 22) ==
               vector<vector<int>>({{5, 4, 11, 2},
                                    {5, 8, 4,  5}}));
    }
};