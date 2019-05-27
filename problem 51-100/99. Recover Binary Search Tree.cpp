/*
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Example 1:

Input: [1,3,null,null,2]

   1
  /
 3
  \
   2

Output: [3,1,null,null,2]

   3
  /
 1
  \
   2
Example 2:

Input: [3,1,4,null,null,2]

  3
 / \
1   4
   /
  2

Output: [2,1,4,null,null,3]

  2
 / \
1   4
   /
  3
Follow up:

A solution using O(n) space is pretty straight forward.
Could you devise a constant space solution?
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
    void recoverTree(TreeNode *root) {
        std::stack<TreeNode *> s;
        auto temp = root;
        TreeNode *first = nullptr, *second, *pre = nullptr;
        while (!s.empty() || temp) {
            if (temp) {
                s.push(temp);
                temp = temp->left;
            } else {
                temp = s.top();
                s.pop();
                if (pre && pre->val > temp->val) {
                    if (!first) {
                        first = pre;
                    }
                    second = temp;
                }
                pre = temp;
                temp = temp->right;
            }
        }
        std::swap(first->val, second->val);
    }

    void test() {
        auto root = stringToTreeNode("[1,3,null,null,2]");
        recoverTree(root);
        assert(treeNodeToString(root) == "[3, 1, null, null, 2, null, null]");
        root = stringToTreeNode("[3,1,4,null,null,2]");
        recoverTree(root);
        assert(treeNodeToString(root) == "[2, 1, 4, null, null, 3, null, null, null]");
    }
};