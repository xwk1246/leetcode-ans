#include <vector>
#include <deque>
#include <iostream>
using namespace std;
/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 */

 // @lc code=start
class myqueue {
public:
    deque<int>data;
    int push(int num) {
        if (data.empty()) {
            data.push_back(num);
            return num;
        }
        while (!data.empty() && num > data.back()) {
            data.pop_back();
        }
        data.push_back(num);
        return num;
    }
    int pop(int num) {
        if (data.front() == num) {
            data.pop_front();
        }
        return num;
    }
    int max() {
        return data.front();
    }
};
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        myqueue mq;
        vector<int> out;
        int front = 0;
        for (int i = 0; i < k; i++) {
            mq.push(nums[i]);
        }
        out.push_back(mq.max());
        for (int i = 0; i + k < nums.size(); i++) {
            mq.pop(nums[i]);
            mq.push(nums[i + k]);
            out.push_back(mq.max());
        }
        return out;
    }
};
// @lc code=end
int main() {
    Solution S1;
    vector<int>nums = { 1,3,1,2,0,5 };
    int k = 3;
    auto tmp = S1.maxSlidingWindow(nums, k);
    for (auto i : tmp) {
        cout << i << endl;
    }
    return 0;
}

