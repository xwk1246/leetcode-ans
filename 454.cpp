#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
    unordered_map<int, int> record;
    int count = 0;
    for (int i : nums1) {
        for (int j : nums2) {
            if (record.count(i + j) == 0) {
                record.insert(pair<int, int>(i + j, 1));
            }
            else {
                record[i + j]++;
            }
        }
    }
    for (int i : nums3) {
        for (int j : nums4) {
            if (record.count(0 - (i + j)) > 0) {
                count += record[0 - (i + j)];
            }
        }
    }
    return count;
}

int main() {
    vector<int>nums1 = { 1, -1 };
    vector<int>nums2 = { 1, 1 };
    vector<int>nums3 = { -1, 1 };
    vector<int>nums4 = { 1, -1 };
    cout << fourSumCount(nums1, nums2, nums3, nums4) << endl;
    return 0;
}