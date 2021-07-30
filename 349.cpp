#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int>record(nums1.begin(), nums1.end());
    unordered_set<int>output;
    for (auto i : nums2) {
        if (record.find(i) != record.end()) {
            output.insert(i);
        }
    }
    return vector<int>(output.begin(), output.end());
}

int main() {
    return 0;
}