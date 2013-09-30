#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <vector>
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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int tot = 1;
        
        ListNode *top = new ListNode(0);
        top->next = head;
        
        ListNode *last = top;
        while (tot < m) {
            tot++;
            head = head->next;
            last = last->next;
        }
        while (tot < n) {
            tot++;
            ListNode *tmp = last->next;
            last->next = head->next;
            head->next = last->next->next;
            last->next->next = tmp;
        }
        
        return top->next;
    }
};

int main() {
    ListNode *head;
    head = new ListNode(1);
    head->next = new ListNode(2);
    
    Solution so;
    ListNode *ans = so.reverseBetween(head, 1, 2);
    
    while (ans != NULL) {
        cout << ans->val << " ";
        ans = ans->next;
    }
    
    return 0;
}