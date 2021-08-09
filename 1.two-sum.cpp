/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

 // @lc code=start
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> record;
        int index = 0;

        for (int num : nums) {
            auto tmp = record.find(target - num);
            if (tmp != record.end()) {
                return { index , tmp->second };
            }
            record.insert(pair<int, int>(num, index));
            index++;
        }
        return {};
    }
};
// @lc code=end

int main() {
    vector<int> nums = { 3, 2, 4 };
    int target = 6;
    Solution S1;
    S1.twoSum(nums, target);
}