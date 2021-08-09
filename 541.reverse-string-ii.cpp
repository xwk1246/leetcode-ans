#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
/*
 * @lc app=leetcode id=541 lang=cpp
 *
 * [541] Reverse String II
 */

 // @lc code=start
class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.length(); i += 2 * k) {
            if ((s.end() - s.begin() - i) < k) {
                reverse(s.begin() + i, s.end());
                continue;
            }
            reverse(s.begin() + i, s.begin() + k + i);
        }
        return s;
    }
};
// @lc code=end
int main() {
    Solution S1;
    cout << S1.reverseStr("a", 1);
    return 0;

}

