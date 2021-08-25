#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
 */

 // @lc code=start
 /**
  * Definition for a binary tree node.
  * struct TreeNode {
  *     int val;
  *     TreeNode *left;
  *     TreeNode *right;
  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  * };
  */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>out;
        traverse(root, out);
        return out;
    }
    void traverse(TreeNode* root, vector<int>& out) {
        if (root == nullptr)return;
        out.push_back(root->val);
        traverse(root->left, out);
        traverse(root->right, out);
    }
};
// @lc code=end

