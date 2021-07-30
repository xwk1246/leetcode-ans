#include <iostream>
#include <vector>
using namespace std;

int removeElement(vector<int>& nums, int val) {
    int i, j;
    int cnt = 0;
    i = 0;
    for (j = 0; j < nums.size();j++) {
        if (nums[j] != val) {
            nums[i++] = nums[j];
            cnt++;
        }
    }
    return cnt;
}
int main() {
    vector<int>nums = { 3, 2, 2, 3 };
    cout << removeElement(nums, 2);
    return 0;
}