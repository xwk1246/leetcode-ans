#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 */

 // @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        int slow = 0, fast = 0;
        reverse(s.begin(), s.end());
        while (fast < s.size()) {
            if (fast == 0 && s[fast] == ' ' || (s[fast] == ' ' && s[fast - 1] == ' ')) {
                fast++;
                continue;
            }
            s[slow] = s[fast];
            slow++;
            fast++;
        }
        s.resize(slow);
        while (s.back() == ' ') {
            s.pop_back();
        }
        for (slow = 0, fast = 0; fast < (int)s.size(); ) {
            while (s[fast] != ' ' && fast < s.size()) {
                fast++;
            };
            reverse(s.begin() + slow, s.begin() + fast);
            fast++;
            slow = fast;
        }
        return s;
    }

};
// @lc code=end

int main() {
    Solution S1;
    cout << S1.reverseWords(" a ");
    return 0;

}