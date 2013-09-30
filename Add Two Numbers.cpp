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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *top = new ListNode(0);
        ListNode *now = top;
        
        int flag = 0;
        while (l1 != NULL || l2 != NULL) {
            int x = flag;
            if (l1 != NULL) {
                x += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL) {
                x += l2->val;
                l2 = l2->next;
            }
            
            if (x > 9) flag = 1;
            else flag = 0;
            
            now->next = new ListNode(x%10);
            now = now->next;
        }
        if (flag) now->next = new ListNode(1);
        
        return top->next;
    }
};

int main() {
    ListNode *a = new ListNode(2);
    a->next = new ListNode(3);
    a->next->next = new ListNode(9);
    
    ListNode *b = new ListNode(5);
    b->next = new ListNode(9);
    
    Solution so;
    ListNode *ans = so.addTwoNumbers(a, b);
    
    while (ans != NULL) {
        cout << ans->val;
        ans = ans->next;
    }
    
    return 0;
}