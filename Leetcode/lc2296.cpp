/*
Leetcode 2296. Design a Text Editor
Key Concepts: Stack
https://leetcode.com/problems/design-a-text-editor/
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

// Idea: Maintain a stack of characters to the left and to the right of the coursor.

class TextEditor {
    stack<char> l, r;

    // Gets the 10 characters to the left of the cursor
    string getLeft() {
        stack<char> tmp;
        int k = 10;
        while (!l.empty() && k > 0) {
            tmp.push(l.top());
            l.pop();
            --k;
        }
        string ret = "";
        while (!tmp.empty()) {
            l.push(tmp.top());
            ret += tmp.top();
            tmp.pop();
        }
        return ret;
    }

public:
    // Initialize an empty text editor
    TextEditor() {}
    
    // Add the contents of the text string into the text editor
    void addText(string text) {
        for (char c : text) {
            l.push(c);
        }
    }
    
    // Delete k characters
    int deleteText(int k) {
        int ans = 0;
        while (!l.empty() && k > 0) {
            l.pop();
            --k;
            ++ans;
        }
        return ans;
    }
    
    // Move the cursor left by k characters
    string cursorLeft(int k) {
        while (!l.empty() && k > 0) {
            r.push(l.top());
            l.pop();
            --k;
        }
        return getLeft();
    }
    
    // Move the cursor right by k characters
    string cursorRight(int k) {
        while (!r.empty() && k > 0) {
            l.push(r.top());
            r.pop();
            --k;
        }
        return getLeft();
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */
