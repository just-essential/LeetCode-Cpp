/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        if (root == nullptr) return {};
        vector<vector<int>> result;
        queue<TreeNode *> q;
        bool even_line = false;
        q.push(root);
        while (!q.empty()) {
            auto size = q.size();
            vector<int> cur_level(size);
            for (int i = 0; i < size; ++i) {
                auto node = q.front();
                q.pop();
                cur_level[even_line ? size - 1 - i : i] = node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            even_line = !even_line;
            result.push_back(cur_level);
        }
        return result;
    }

    void test() {
        assert(zigzagLevelOrder(stringToTreeNode("[3,9,20,null,null,15,7]")) == vector<vector<int>>({{3},
                                                                                                     {20, 9},
                                                                                                     {15, 7}}));
    }
};