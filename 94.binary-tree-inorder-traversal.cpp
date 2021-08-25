/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>out;
        traverse(root, out);
        return out;
    }
    void traverse(TreeNode* root, vector<int>& out) {
        if (root == nullptr)return;
        traverse(root->left, out);
        out.push_back(root->val);
        traverse(root->right, out);
    }


};
// @lc code=end

