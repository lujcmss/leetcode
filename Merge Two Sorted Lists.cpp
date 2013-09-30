#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>
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
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *now = new ListNode(0);
        ListNode *re = now;
        
        while (l1 != NULL || l2 != NULL) {
            if (l2 == NULL || (l1 != NULL && l1->val < l2->val)) {
                now->next = new ListNode(l1->val);
                now = now->next;
                l1 = l1->next;
            } else {
                now->next = new ListNode(l2->val);
                now = now->next;
                l2 = l2->next;
            }
        }
        
        return re->next;
    }
};

int main() {
    ListNode *a = new ListNode(1);
    a->next = new ListNode(3);
    a->next->next = new ListNode(7);
    
    ListNode *b = new ListNode(3);
    b->next = new ListNode(6);
    
    Solution so;
    ListNode *ans = so.mergeTwoLists(a, b);
    
    while (ans != NULL) {
        cout << ans->val << endl;
        ans = ans->next;
    }
    
    return 0;
}