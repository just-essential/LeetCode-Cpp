/*
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
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
//    TreeNode *buildTree(vector<int> &pre_order, vector<int> &in_order) {
//        function<TreeNode *(int, int, int)> lambda;
//        lambda = [&](int pre_begin, int in_begin, int size) -> TreeNode * {
//            if (size == 0) {
//                return nullptr;
//            }
//            if (size == 1) {
//                return new TreeNode(pre_order[pre_begin]);
//            }
//            int left_size = 0, left_end = in_begin, root_val = pre_order[pre_begin];
//            while (in_order[left_end] != root_val) {
//                left_size++;
//                left_end++;
//            }
//            auto root = new TreeNode(root_val);
//            root->left = lambda(pre_begin + 1, in_begin, left_size);
//            root->right = lambda(pre_begin + left_size + 1, left_end + 1, size - left_size - 1);
//            return root;
//        };
//        return lambda(0, 0, pre_order.size());
//    }
    TreeNode *buildTree(vector<int> &pre_order, vector<int> &in_order) {
        unordered_map<int, int> in_order_map;
        int size = pre_order.size();
        for (int i = 0; i < size; ++i) {
            in_order_map[in_order[i]] = i;
        }
        function<TreeNode *(int, int, int)> lambda = [&](int pre_begin, int in_begin, int size) -> TreeNode * {
            if (size == 0) {
                return nullptr;
            }
            if (size == 1) {
                return new TreeNode(pre_order[pre_begin]);
            }
            int root_val = pre_order[pre_begin], left_end = in_order_map[root_val], left_size = left_end - in_begin;
            auto root = new TreeNode(root_val);
            root->left = lambda(pre_begin + 1, in_begin, left_size);
            root->right = lambda(pre_begin + left_size + 1, left_end + 1, size - left_size - 1);
            return root;
        };
        return lambda(0, 0, size);
    }

    void test() {
        vector<int> pre_order{3, 9, 20, 15, 7};
        vector<int> in_order{9, 3, 15, 20, 7};
        assert(treeNodeToString(buildTree(pre_order, in_order)) ==
               "[3, 9, 20, null, null, 15, 7, null, null, null, null]");
    }
};