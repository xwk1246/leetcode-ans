#include <queue>
#include <iostream>
using namespace std;
/*
 * @lc app=leetcode id=225 lang=cpp
 *
 * [225] Implement Stack using Queues
 */

 // @lc code=start
class MyStack {
public:
    queue<int>q1;
    queue<int>q2;
    /** Initialize your data structure here. */

    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        q1.push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int tmp;
        while ((int)q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        tmp = q1.front();
        q1.pop();
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
        return tmp;
    }

    /** Get the top element. */
    int top() {
        int tmp = pop();
        q1.push(tmp);
        return tmp;
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        if (!q1.empty() || !q2.empty())return false;
        return true;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
 // @lc code=end
int main() {
    MyStack s;
    s.push(1);
    s.push(2);
    cout << s.pop() << endl;
    cout << s.top() << endl;

    return 0;
}

