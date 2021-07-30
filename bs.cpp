#include <iostream>
#include <vector>
using namespace std;

int search(vector<int>& nums, int target) {
    int left, right;
    int mid;
    left = 0;
    right = nums.size() - 1;
    while (left <= right) {
        mid = (left + right) / 2;
        if (target > nums[mid]) {
            left = mid + 1;
        }
        else if (target < nums[mid]) {
            right = mid - 1;
        }
        else {
            return mid;
        }
    }
    return -1;
}
int main() {
    vector <int> nums = 5;
    int target;
    target = 5;
    cout << search(nums, target);
    return 0;
}