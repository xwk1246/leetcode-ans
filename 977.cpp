#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int front, end;
        vector <int> out(nums.size());
        front = 0;
        end = nums.size() - 1;
        int i = nums.size() - 1;
        while (front <= end) {
            if (nums[front] * nums[front] >= nums[end] * nums[end]) {
                out[i--] = nums[front] * nums[front];
                front++;
            }
            else {
                out[i--] = nums[end] * nums[end];
                end--;
            }
        }
        return out;
    }
};

int main() {
    Solution solution;
    vector <int> nums = { -3, -2, 0, 1,2 };
    solution.sortedSquares(nums);
    return 0;
}