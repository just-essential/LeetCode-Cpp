/*
Given a binary tree

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

 

Example:



Input: {"$id":"1","left":{"$id":"2","left":{"$id":"3","left":null,"next":null,"right":null,"val":4},"next":null,"right":{"$id":"4","left":null,"next":null,"right":null,"val":5},"val":2},"next":null,"right":{"$id":"5","left":null,"next":null,"right":{"$id":"6","left":null,"next":null,"right":null,"val":7},"val":3},"val":1}

Output: {"$id":"1","left":{"$id":"2","left":{"$id":"3","left":null,"next":{"$id":"4","left":null,"next":{"$id":"5","left":null,"next":null,"right":null,"val":7},"right":null,"val":5},"right":null,"val":4},"next":{"$id":"6","left":null,"next":null,"right":{"$ref":"5"},"val":3},"right":{"$ref":"4"},"val":2},"next":null,"right":{"$ref":"6"},"val":1}

Explanation: Given the above binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B.
 

Note:

You may only use constant extra space.
Recursive approach is fine, implicit stack space does not count as extra space for this problem.
*/
// Definition for a Node.
class Node {
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() {}

    Node(int _val, Node *_left, Node *_right, Node *_next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};

class Solution {
public:
    Node *connect(Node *root) {
        Node *levelHead, *pre, *cur;
        cur = root;
        levelHead = pre = nullptr;
        while (cur != nullptr) {
            if (cur->left) {
                if (pre != nullptr) {
                    pre = pre->next = cur->left;
                } else {
                    levelHead = pre = cur->left;
                }
            }
            if (cur->right) {
                if (pre != nullptr) {
                    pre = pre->next = cur->right;
                } else {
                    levelHead = pre = cur->right;
                }
            }
            cur = cur->next;
            if (cur == nullptr) {
                cur = levelHead;
                pre = levelHead = nullptr;
            }
        }
        return root;
    }

//    Node *connect(Node *root) {
//        Node *levelHead = root, *parent, *pre;
//        while (levelHead != nullptr) {
//            parent = levelHead;
//            levelHead = nullptr;
//            // find the head of next level and init pre
//            while (parent != nullptr) {
//                if (parent->left != nullptr) {
//                    levelHead = parent->left;
//                    if (parent->right != nullptr) {
//                        pre = levelHead->next = parent->right;
//                    } else {
//                        pre = levelHead;
//                    }
//                    parent = parent->next;
//                    break;
//                }
//                if (parent->right != nullptr) {
//                    pre = levelHead = parent->right;
//                    parent = parent->next;
//                    break;
//                }
//                parent = parent->next;
//            }
//            // connect next level
//            while (parent != nullptr) {
//                if (parent->left != nullptr) {
//                    pre = pre->next = parent->left;
//                }
//                if (parent->right != nullptr) {
//                    pre = pre->next = parent->right;
//                }
//                parent = parent->next;
//            }
//        }
//        return root;
//    }
};