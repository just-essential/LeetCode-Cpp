/*
Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1 ... n.

Example:

Input: 3
Output:
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
Explanation:
The above output corresponds to the 5 unique BST's shown below:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
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
    vector<TreeNode *> generateTrees(int n) {
        if (n < 1) return {};
        function<vector<TreeNode *>(int, int)> generator;
        generator = [&generator](int a, int b) {
            vector<TreeNode *> result;
            if (a > b) {
                result.push_back(nullptr);
            } else {
                for (int i = a; i <= b; ++i) {
                    for (auto l:generator(a, i - 1)) {
                        for (auto r:generator(i + 1, b)) {
                            result.push_back(new TreeNode(i));
                            result.back()->left = l;
                            result.back()->right = r;
                        }
                    }
                }
            }
            return result;
        };
        return generator(1, n);
    }

    void test() {
        vector<string> result;
        for (auto &item:generateTrees(3)) {
            result.push_back(treeNodeToString(item));
        }
        assert(result == vector<string>({"[1, null, 2, null, 3, null, null]", "[1, null, 3, 2, null, null, null]",
                                         "[2, 1, 3, null, null, null, null]", "[3, 1, null, null, 2, null, null]",
                                         "[3, 2, null, 1, null, null, null]"}));
    }
};