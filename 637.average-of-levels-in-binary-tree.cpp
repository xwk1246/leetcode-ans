#include <vector>
#include <queue>
using namespace std;
/*
 * @lc app=leetcode id=637 lang=cpp
 *
 * [637] Average of Levels in Binary Tree
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector <double> result;
        if (root == nullptr) return {};
        queue<TreeNode*>q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            double sum = 0;
            for (int i = 0; i < size; i++) {
                if (q.front()->left != nullptr) q.push(q.front()->left);
                if (q.front()->right != nullptr) q.push(q.front()->right);
                sum += q.front()->val;
                if (i == size - 1) {
                    result.push_back(sum / size);
                }
                q.pop();
            }
        }
        return result;
    }
};
// @lc code=end

