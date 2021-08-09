/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

 // @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        int right;
        int left;
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i - 1] == nums[i])continue;
            right = nums.size() - 1;
            left = i + 1;
            while (left < right) {
                if (nums[i] + nums[right] + nums[left] < 0) {
                    left++;
                }
                else if (nums[i] + nums[right] + nums[left] > 0) {
                    right--;
                }
                else {
                    result.push_back({ nums[i], nums[left], nums[right] });
                    while (left < right && nums[left] == nums[left + 1])left++;
                    while (left < right && nums[right - 1] == nums[right])right--;
                    left++;
                    right--;
                }
            }

        }
        return result;
    }
};
// @lc code=end
int main() {
    Solution s;
    vector<int> nums = { -1,0,1 };
    s.threeSum(nums);
    return 0;
}

