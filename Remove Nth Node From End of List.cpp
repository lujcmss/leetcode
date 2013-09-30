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
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *top = new ListNode(0);
        ListNode *last, *first;
        top->next = head;
        last = first = top;
        
        for (int i = 0; i <= n; i++) {
            first = first->next;
        }
        
        while (first != NULL) {
            first = first->next;
            last = last->next;
        }
        
        last->next = last->next->next;
        
        return top->next;
    }
};

int main() {
    ListNode *a = new ListNode(1);
    a->next = new ListNode(2);
    a->next->next = new ListNode(4);
    
    Solution so;
    ListNode *ans = so.removeNthFromEnd(a, 3);
    
    while (ans != NULL) {
        cout << ans->val << " ";
        ans = ans->next;
    }
    
    return 0;
}