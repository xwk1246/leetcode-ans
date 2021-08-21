#include <string>
#include <iostream>
using namespace std;

/*
 * @lc app=leetcode id=459 lang=cpp
 *
 * [459] Repeated Substring Pattern
 */

 // @lc code=start
class Solution {
public:
    void buildNext(int* next, string s) {
        int j = 0;
        next[0] = 0;
        for (int i = 1; i < s.length(); i++) {
            while (j > 0 && s[i] != s[j]) {
                j = next[j - 1];
            }
            if (s[i] == s[j])j++;
            next[i] = j;
        }

    }
    bool repeatedSubstringPattern(string s) {
        int next[s.length()];
        buildNext(next, s);
        if (next[s.length() - 1] && s.length() % (s.length() - next[s.length() - 1]) == 0)return true;
        return false;
    }
};
// @lc code=end

int main() {
    Solution S1;
    string s = "abac";
    cout << S1.repeatedSubstringPattern(s);
    return 0;
}