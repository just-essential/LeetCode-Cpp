/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
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
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        if (root == nullptr) return {};
        struct Node {
            TreeNode *node;
            int level;
        };
        queue<Node> q;
        vector<vector<int>> result;
        Node temp;
        q.push({root, 0});
        while (!q.empty()) {
            temp = q.front();
            q.pop();
            if (result.size() == temp.level) {
                result.emplace_back();
            }
            result[temp.level].push_back(temp.node->val);
            if (temp.node->left) {
                q.push({temp.node->left, temp.level + 1});
            }
            if (temp.node->right) {
                q.push({temp.node->right, temp.level + 1});
            }
        }
        return {result.rbegin(), result.rend()};
    }

    void test() {
        assert(levelOrderBottom(stringToTreeNode("[3,9,20,null,null,15,7]")) == vector<vector<int>>({{15, 7},
                                                                                                     {9,  20},
                                                                                                     {3}}));
    }
};