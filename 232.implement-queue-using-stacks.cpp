#include <stack>
using namespace std;
/*
 * @lc app=leetcode id=232 lang=cpp
 *
 * [232] Implement Queue using Stacks
 */

 // @lc code=start
class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int>sIn;
    stack<int>sOut;
    MyQueue() {
    }
    /** Push element x to the back of queue. */
    void push(int x) {
        sIn.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int buf;
        if (sOut.empty()) {
            while (!sIn.empty()) {
                sOut.push(sIn.top());
                sIn.pop();
            }
            buf = sOut.top();
            sOut.pop();
            return buf;
        }
        else {
            buf = sOut.top();
            sOut.pop();
            return buf;
        }
    }

    /** Get the front element. */
    int peek() {
        int buf;
        buf = pop();
        sOut.push(buf);
        return buf;
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        if (!sIn.empty() || !sOut.empty()) {
            return false;
        }
        return true;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
 // @lc code=end

