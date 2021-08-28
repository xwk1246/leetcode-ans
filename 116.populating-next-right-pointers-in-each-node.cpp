#include <queue>
using namespace std;
/*
 * @lc app=leetcode id=116 lang=cpp
 *
 * [116] Populating Next Right Pointers in Each Node
 */

 // @lc code=start
 /*
 // Definition for a Node.
 class Node {
 public:
     int val;
     Node* left;
     Node* right;
     Node* next;

     Node() : val(0), left(NULL), right(NULL), next(NULL) {}

     Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

     Node(int _val, Node* _left, Node* _right, Node* _next)
         : val(_val), left(_left), right(_right), next(_next) {}
 };
 */

class Solution {
public:
    Node* connect(Node* root) {
        if (!root)return root;
        queue<Node*>q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            Node* tmp = nullptr;
            for (int i = 0; i < size; i++) {
                if (tmp) {
                    tmp->next = q.front();
                }
                tmp = q.front();
                if (q.front()->left)
                    q.push(q.front()->left);
                if (q.front()->right)
                    q.push(q.front()->right);
                q.pop();
            }
        }
        return root;
    }
};
// @lc code=end

