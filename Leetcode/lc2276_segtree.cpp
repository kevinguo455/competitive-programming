/*
Leetcode 2276. Count Integers in Intervals
Key Concepts: Implicit Segment Tree
https://leetcode.com/problems/count-integers-in-intervals/
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

// Idea: Maintain an implicit segment tree that tracks the active intervals.
// This is possible since there are only at most 1e5 distinct nodes.

struct Interval {
    bool set;
    int l, r, cnt;
    Interval *_lc;
    Interval *_rc;

    Interval (int _l, int _r) {
        set = 0;
        l = _l;
        r = _r;
        cnt = 0;
        _lc = NULL;
        _rc = NULL;
    }

    inline int m() {
        return (l+r)/2;
    }

    inline Interval *lc() {
        if (_lc == NULL) _lc = new Interval(l, m());
        return _lc;
    }

    inline Interval *rc() {
        if (_rc == NULL) _rc = new Interval(m()+1, r);
        return _rc;
    }

};

class CountIntervals {
    Interval *root;

public:

    CountIntervals() {
        root = new Interval(1, (1<<30)-1);
    }

    // Standard segment tree insertion
    void update(Interval *cur, int ql, int qr) {
        if (cur->set || cur->l > qr || cur->r < ql) return;
        if (cur->l == ql && cur->r == qr) {
            cur->set = 1;
            cur->cnt = cur->r - cur->l + 1;
            return;
        }
        if (ql <= cur->m()) {
            update(cur->lc(), ql, min(cur->m(), qr));
        } 
        if (qr > cur->m()) {
            update(cur->rc(), max(cur->m()+1, ql), qr);
        }
        if (cur->_lc && cur->_rc && cur->lc()->set && cur->rc()->set) {
            cur->set = 1;
            cur->cnt = cur->r - cur->l + 1;
            return;
        }
        cur->cnt = 0;
        if (cur->_lc) cur->cnt += cur->lc()->cnt;
        if (cur->_rc) cur->cnt += cur->rc()->cnt;
    }
    
    void add(int left, int right) {
        update(root, left, right);
    }
    
    int count() {
        return root->cnt;
    }

};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */
