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

    // q1 stores all the elements such that popping an element from q1 is popping an element from the simulated stack.
    // q2 is an empty queue that temporarily stores elements during the push operation.
    queue<int> q1;
    queue<int> q2;
    
    MyStack() {}
    
    // push()
    // Time Complexity: O(n)
    // Push to the front of q1 by pushing the new element to q2 and moving all elements from q1 to q2
    //   then swapping q1 and q2.
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }
    
    // pop()
    // Time Complexity: O(1)
    int pop() {
        int ret = q1.front();
        q1.pop();
        return ret;
    }
    
    // top()
    // Time Complexity: O(1)
    int top() {
        return q1.front();
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
