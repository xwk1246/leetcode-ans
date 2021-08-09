/*
 * @lc app=leetcode id=383 lang=cpp
 *
 * [383] Ransom Note
 */

 // @lc code=start
#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int>record(26, 0);
        for (auto a : magazine) {
            record[a - 'a']++;
        }
        for (auto a : ransomNote) {
            if (record[a - 'a'] <= 0) {
                return false;
            }
            record[a - 'a']--;
        }
        return true;
    }
};
// @lc code=end

int main() {
    Solution s;
    cout << s.canConstruct("aa", "ab");
}

