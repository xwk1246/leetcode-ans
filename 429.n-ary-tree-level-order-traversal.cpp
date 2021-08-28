#include <vector>
#include <queue>
using namespace std;
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
/*
 * @lc app=leetcode id=429 lang=cpp
 *
 * [429] N-ary Tree Level Order Traversal
 */

 // @lc code=start
 /*
 // Definition for a Node.
 class Node {
 public:
     int val;
     vector<Node*> children;

     Node() {}

     Node(int _val) {
         val = _val;
     }

     Node(int _val, vector<Node*> _children) {
         val = _val;
         children = _children;
     }
 };
 */

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (!root) return{};
        queue<Node*>q;
        vector<vector<int>>result;
        q.push(root);
        while (!q.empty()) {
            vector<int> tmp;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                for (auto j : q.front()->children) {
                    if (j != nullptr)q.push(j);
                }
                tmp.push_back(q.front()->val);
                q.pop();
            }
            result.push_back(tmp);
        }
        return result;
    }
};
// @lc code=end

int main() {
    Solution s;
    vector<Node*> v = { new Node(3), new Node(2), new Node(4) };

    Node* n = new Node(1, v);

    s.levelOrder(n);
    return 0;
}