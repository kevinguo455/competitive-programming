/*
Leetcode 2296. Design a Text Editor
Key Concepts: Doubly Linked List
https://leetcode.com/problems/design-a-text-editor/
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

struct Node {
    char c;
    Node* l;
    Node* r;
};

// Idea: Implement a doubly linked list where each Node represents a character.

class TextEditor {
    Node* cur_l;    // Points to the Node immediately to the left of the cursor
    Node* cur_r;    // Points to the Node immediately to the right of the cursor

    // Gets the 10 characters to the left of the cursor
    string getLeft() {
        int k = 10;
        string ret = "";
        Node* p = cur_l;
        while (p != nullptr && k > 0) {
            ret = p->c + ret;
            p = p->l;
            --k;
        }
        return ret;
    }

public:
    // Initialize an empty text editor
    TextEditor() {
        cur_l = cur_r = nullptr;
    }
    
    // Add the contents of the text string into the text editor
    void addText(string text) {
        for (char c : text) {
            Node* n = new Node;
            n->c = c;
            n->l = cur_l;
            n->r = cur_r;
            if (cur_l != nullptr) cur_l->r = n;
            if (cur_r != nullptr) cur_r->l = n;
            cur_l = n;
        }
    }
    
    // Delete k characters
    int deleteText(int k) {
        int ans = 0;
        while (cur_l != nullptr && k > 0) {
            Node* p = cur_l;
            cur_l = p->l;
            cur_r->l = p->l;
            if (p->l != nullptr) p->l->r = cur_r;
            delete(p);
            ++ans;
            --k;
        }
        return ans;
    }
    
    // Move the cursor left by k characters
    string cursorLeft(int k) {
        while (cur_l != nullptr && k > 0) {
            cur_r = cur_l;
            cur_l = cur_l->l;
            --k;
        }
        return getLeft();
    }
    
    // Move the cursor right by k characters
    string cursorRight(int k) {
        while (cur_r != nullptr && k > 0) {
            cur_l = cur_r;
            cur_r = cur_r->r;
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
