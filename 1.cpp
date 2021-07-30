#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int>record;
    for (int i = 0; i < nums.size(); i++) {
        unordered_map<int, int>::iterator result;
        if ((result = record.find(target - nums[i])) != record.end()) {
            return { i, result->second };
        }
        record.insert(pair<int, int>(nums[i], i));
    }
    return {};
}