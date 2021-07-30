#include <vector>
using namespace std;

int maxSubArray(vector<int>& nums) {
    vector<int>sub;
    int max = nums[0];
    for (int i = 0; i < nums.size();i++) {
        int sum = 0;
        for (int j = i; j < nums.size(); j++) {
            sum += nums[j];
            if (sum > max)max = sum;
        }
    }
    return max;
}