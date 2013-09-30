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
    ListNode *rotateRight(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (k == 0 || head == NULL) return head;
        
        int tot = 0;
        ListNode *top = new ListNode(0);
        top->next = head;
        
        while (head != NULL) {
            tot++;
            head = head->next;
        }
        k = (k-1)%tot+1;
        
        head = top;
        int num = tot-k;
        while (num--) {
            head = head->next;
        }
        ListNode *tmp = head->next;
        head->next = NULL;
        head = top->next;
        top->next = tmp;
        
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = head;
        
        return top->next;
    }
};

int main() {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    
    Solution so;
    ListNode *ans = so.rotateRight(head, 6);
    
    while (ans != NULL) {
        cout << ans->val << " ";
        ans = ans->next;
    }
    
    return 0;
}