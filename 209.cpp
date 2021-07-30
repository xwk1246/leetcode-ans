#include <iostream>
#include <vector>
using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
    int min = 0;
    int sum, tmp;
    int i = 0;
    int j = 0;
    int k;
    while (i < nums.size() && j < nums.size()) {
        sum = 0;
        for (k = i; k <= j; k++) {
            sum += nums[k];
        }
        if (sum >= target && (j - i + 1 < min || min == 0))min = j - i + 1;
        if (sum >= target) {
            i++;
        }
        else if (sum < target) {
            j++;
        }
    }
    return min;
}
int main() {
    vector <int> max = { 2,3,1,2,4,3 };
    int target = 7;
    cout << minSubArrayLen(target, max);
}