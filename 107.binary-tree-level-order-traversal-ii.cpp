#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode id=107 lang=cpp
 *
 * [107] Binary Tree Level Order Traversal II
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*>q;
        vector<vector<int>>result;
        if (root == nullptr)return {};
        q.push(root);
        while (!q.empty()) {
            vector <int>tmp;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                if (q.front()->left != nullptr)q.push(q.front()->left);
                if (q.front()->right != nullptr)q.push(q.front()->right);
                tmp.push_back(q.front()->val);
                q.pop();
            }
            result.push_back(tmp);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
// @lc code=end

