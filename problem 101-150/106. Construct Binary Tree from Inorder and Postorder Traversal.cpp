/*
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7
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
    TreeNode *buildTree(vector<int> &in_order, vector<int> &post_order) {
        unordered_map<int, int> in_order_map;
        int size = in_order.size();
        for (int i = 0; i < size; ++i) {
            in_order_map[in_order[i]] = i;
        }
        function<TreeNode *(int, int, int)> lambda;
        lambda = [&](int in_begin, int post_begin, int size) -> TreeNode * {
            if (size == 0) {
                return nullptr;
            }
            int root_val = post_order[post_begin + size - 1];
            auto root = new TreeNode(root_val);
            if (size == 1) {
                return root;
            }
            int in_root = in_order_map[root_val], left_size = in_root - in_begin;
            root->left = lambda(in_begin, post_begin, left_size);
            root->right = lambda(in_root + 1, post_begin + left_size, size - left_size - 1);
            return root;
        };
        return lambda(0, 0, size);
    }

    void test() {
        vector<int> in_order{9, 3, 15, 20, 7};
        vector<int> post_order{9, 15, 7, 20, 3};
        assert(treeNodeToString(buildTree(in_order, post_order)) ==
               "[3, 9, 20, null, null, 15, 7, null, null, null, null]");
    }
};