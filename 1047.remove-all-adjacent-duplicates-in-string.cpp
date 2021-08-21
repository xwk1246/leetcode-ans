#include <string>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode id=1047 lang=cpp
 *
 * [1047] Remove All Adjacent Duplicates In String
 */

 // @lc code=start
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>s1;
        string out;
        for (auto i : s) {
            if (!s1.empty() && s1.top() == i) {
                s1.pop();
            }
            else {
                s1.push(i);
            }
        }
        while (!s1.empty()) {
            out += s1.top();
            s1.pop();
        }
        reverse(out.begin(), out.end());
        return out;
    }
};
// @lc code=end
int main() {
    Solution s1;
    cout << s1.removeDuplicates("abbaca");
    return 0;
}

