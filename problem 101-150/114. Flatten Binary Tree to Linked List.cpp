/*
Given a binary tree, flatten it to a linked list in-place.

For example, given the following tree:

    1
   / \
  2   5
 / \   \
3   4   6
The flattened tree should look like:

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6
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
    void flatten(TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        function<TreeNode *(TreeNode *)> farRightOnTheLeft;
        farRightOnTheLeft = [&](TreeNode *root) -> TreeNode * {
            if (root->left != nullptr) {
                auto right = root->right;
                auto left = farRightOnTheLeft(root->left);
                root->right = root->left;
                root->left = nullptr;
                left->right = right;
                root = left;
            }
            if (root->right == nullptr) {
                return root;
            }
            return farRightOnTheLeft(root->right);
        };
        farRightOnTheLeft(root);
    }

//    void flatten_(TreeNode *root) {
//        while (root) {
//            if (root->left) {
//                TreeNode *temp = root->left;
//                while (temp->right) {
//                    temp = temp->right;
//                }
//                temp->right = root->right;
//                root->right = root->left;
//                root->left = nullptr;
//            }
//            root = root->right;
//        }
//    }

    void test() {
        auto root = stringToTreeNode("[1,2,5,3,4,null,6]");
        flatten(root);
        assert(treeNodeToString(root) == "[1, null, 2, null, 3, null, 4, null, 5, null, 6, null, null]");
    }
};