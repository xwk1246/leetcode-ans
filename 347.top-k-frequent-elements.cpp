#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;
/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

 // @lc code=start
class Solution {
    class compare {
    public:
        bool operator()(pair<int, int>& a, pair<int, int>& b) {
            return a.second < b.second;
        }
    };
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>numMap;
        vector< int>out;
        for (auto i : nums) {
            numMap[i]++;
        }
        priority_queue < pair<int, int>, vector<pair<int, int>>, compare>q;
        for (auto i : numMap) {
            q.push(i);
        }
        while (k--) {
            out.push_back(q.top().first);
            q.pop();
        }
        return out;
    }
};
// @lc code=end

int main() {
    Solution s;
    vector<int>nums{ 1, 1, 1, 2, 2, 3 };
    s.topKFrequent(nums, 2);
    return 0;
}
