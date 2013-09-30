#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
    struct node {
        int val;
        int index;
    };
    class cmp {
    public:
        bool operator() (const node &x, const node &y) const{
            return (x.val > y.val);
        }
    };
    
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        priority_queue<node, vector<node>, cmp> pq;
        int finish;
        ListNode *re = new ListNode(0);
        ListNode *now = re;
        
        while (!pq.empty()) pq.pop();
        finish = 0;
        
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] == NULL) finish++;
            else {
                node tmp;
                tmp.val = lists[i]->val;
                tmp.index = i;
                pq.push(tmp);
                
                lists[i] = lists[i]->next;
            }
        }
        while (finish < lists.size()) {
            node top = pq.top();
            pq.pop();
            
            now->next = new ListNode(top.val);
            now = now->next;
            
            if (lists[top.index] == NULL) finish++;
            else {
                node tmp;
                tmp.val = lists[top.index]->val;
                tmp.index = top.index;
                pq.push(tmp);
                
                lists[top.index] = lists[top.index]->next;
            }
        }
        
        return re->next;
    }
};

int main() {
    ListNode *a = new ListNode(1);
    a->next = new ListNode(2);
    a->next->next = new ListNode(4);
    
    ListNode *b = new ListNode(2);
    b->next = new ListNode(3);
    b->next->next = new ListNode(3);

    ListNode *c = new ListNode(1);
    c->next = new ListNode(4);
    c->next->next = new ListNode(5);
    
    vector<ListNode *> lists;
    //lists.push_back(a);
    //lists.push_back(b);
    //lists.push_back(c);
    
    Solution so;
    ListNode *ans = so.mergeKLists(lists);
    
    while (ans != NULL) {
        cout << ans->val << " ";
        ans = ans->next;
    }
    
    return 0;
}