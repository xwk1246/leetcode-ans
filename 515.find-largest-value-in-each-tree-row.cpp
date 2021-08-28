#include <vector>
#include <queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
/*
 * @lc app=leetcode id=515 lang=cpp
 *
 * [515] Find Largest Value in Each Tree Row
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
    vector<int> largestValues(TreeNode* root) {
        queue <TreeNode*>q;
        vector<int>result;
        if (!root)return {};
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            int max;
            max = q.front()->val;
            for (int i = 0; i < size; i++) {
                if (q.front()->val > max) {
                    max = q.front()->val;
                }
                if (q.front()->left)
                    q.push(q.front()->left);
                if (q.front()->right)
                    q.push(q.front()->right);
                q.pop();
            }
            result.push_back(max);
        }
        return result;
    }
};
// @lc code=end
int main() {
    Solution s;
    TreeNode* root = new TreeNode(1, new TreeNode(3), new TreeNode(2));
    s.largestValues(root);
    return 0;
}

