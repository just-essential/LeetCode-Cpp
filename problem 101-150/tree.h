//
// Created by Jacob on 2019/5/26.
//

#ifndef PROBLEM_51_100_TREE_H
#define PROBLEM_51_100_TREE_H
#include <string>
#include <algorithm>
#include <queue>
#include <sstream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode *stringToTreeNode(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (input.empty()) {
        return nullptr;
    }
    string item;
    stringstream ss;
    ss.str(input);
    getline(ss, item, ',');
    auto *root = new TreeNode(stoi(item));
    queue<TreeNode *> nodeQueue;
    nodeQueue.push(root);
    while (true) {
        TreeNode *node = nodeQueue.front();
        nodeQueue.pop();
        if (!getline(ss, item, ',')) {
            break;
        }
        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }
        if (!getline(ss, item, ',')) {
            break;
        }
        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

string treeNodeToString(TreeNode *root) {
    if (root == nullptr) {
        return "[]";
    }
    string output;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode *node = q.front();
        q.pop();
        if (node == nullptr) {
            output += "null, ";
            continue;
        }
        output += to_string(node->val) + ", ";
        q.push(node->left);
        q.push(node->right);
    }
    return "[" + output.substr(0, output.length() - 2) + "]";
}
#endif //PROBLEM_51_100_TREE_H
