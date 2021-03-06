/*
 * @lc app=leetcode id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
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
    int minDepth(TreeNode* root) {
        if (!root)return 0;
        queue<TreeNode*>q;
        q.push(root);
        int minHeight = 0;
        while (!q.empty()) {
            minHeight++;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                if (!q.front()->left && !q.front()->right) return minHeight;
                if (q.front()->left)
                    q.push(q.front()->left);
                if (q.front()->right)
                    q.push(q.front()->right);
                q.pop();
            }
        }
        return minHeight;
    }
};
// @lc code=end

