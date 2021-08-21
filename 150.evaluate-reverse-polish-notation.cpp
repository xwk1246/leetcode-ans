#include <vector>
#include <cctype>
#include <string>
#include <stack>
#include <iostream>
using namespace std;
/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 */

 // @lc code=start
class Solution {
public:
    stack<int>s1;
    int evalRPN(vector<string>& tokens) {
        for (auto i : tokens) {
            if (i == "+") {
                int tmp = s1.top();
                s1.pop();
                int result = s1.top() + tmp;
                s1.pop();
                s1.push(result);
            }
            else if (i == "-") {
                int tmp = s1.top();
                s1.pop();
                int result = s1.top() - tmp;
                s1.pop();
                s1.push(result);
            }
            else if (i == "*") {
                int tmp = s1.top();
                s1.pop();
                int result = s1.top() * tmp;
                s1.pop();
                s1.push(result);
            }
            else if (i == "/") {
                int tmp = s1.top();
                s1.pop();
                int result = s1.top() / tmp;
                s1.pop();
                s1.push(result);
            }
            else {
                s1.push(stoi(i));
            }
        }
        return s1.top();
    }
};
// @lc code=end
int main() {
    Solution s1;
    vector<string>input = { "10", "6","9","3", "+","-11","*","/","*","17","+","5","+" };
    cout << s1.evalRPN(input);
    return 0;
}

