/*
Leetcode 225. Implement Stack using Queues
Key Concepts: Data Structures (stack, queue)
https://leetcode.com/problems/implement-stack-using-queues/
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

class MyStack {
public:

    // q1 stores all the elements in queue order.
    // q2 stores at most one element -- the top of the simulated stack.
    queue<int> q1;
    queue<int> q2;
    
    MyStack() {}
    
    // push()
    // Time Complexity: O(1)
    void push(int x) {
        q1.push(x);
        if (!q2.empty()) q2.pop();
        q2.push(x);
    }
    
    // pop()
    // Time Complexity: O(n)
    // Pop from the back of q1 and update the new "top" element accordingly.
    int pop() {
        int ret = q2.front(); 
        q2.pop();
        while (q1.size() > 2) {
            q2.push(q1.front());
            q1.pop();
        }
        if (q1.size() == 2) {
            int new_top = q1.front();
            q2.push(new_top);
            q1.pop();
            q1.pop();
            q1.push(new_top);
        }
        swap(q1, q2);
        return ret;
    }

    // top()
    // Time Complexity: O(1)
    int top() {
        return q2.front();
    }

    // empty()
    // Time Complexity: O(1)
    bool empty() {
        return q1.empty();
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
