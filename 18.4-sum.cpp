#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 */

 // -2,-1,0,0,1,2
  // @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>result;
        for (int i = 0; i < nums.size(); i++) {
            while (i > 0 && i < nums.size() && nums[i] == nums[i - 1])i++;
            for (int j = i + 1; j < nums.size(); j++) {
                while (j > i + 1 && j < nums.size() && nums[j] == nums[j - 1])j++;
                int left, right;
                left = j + 1;
                right = nums.size() - 1;
                while (left < right) {
                    long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[left] + (long long)nums[right];
                    if (sum > target)right--;
                    else if (sum < target)left++;
                    else {
                        while (left < right && nums[left] == nums[left + 1])left++;
                        while (left < right && nums[right] == nums[right - 1])right--;
                        result.push_back({ nums[i], nums[j], nums[left], nums[right] });
                        left++;
                        right--;
                    }
                }
            }
        }
        return result;

    }
};
// @lc code=end
int main() {
    Solution S1;
    vector<int>tmp = { 1000000000,1000000000,1000000000,1000000000 };
    S1.fourSum(tmp, 0);

}
