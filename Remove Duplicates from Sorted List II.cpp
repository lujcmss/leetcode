#include <stdio.h>
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
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *top = new ListNode(0);
        ListNode *now = top;
        ListNode *head1 = head;
        ListNode *re = new ListNode(0);
        
        int last;
        int flag = true;
        while (head != NULL) {
            if (flag || last != head->val) {
                flag = false;
                now->next = new ListNode(head->val);
                now = now->next;
            }
            last = head->val;
            head = head->next;
        }
        
        now = re;
        top = top->next;
        while (top != NULL) {
            int x = top->val;
            int num = 0;
            while (head1 != NULL && head1->val == x) {
                num++;
                head1 = head1->next;
            }
            
            if (num == 1) {
                now->next = new ListNode(x);
                now = now->next;
            }
            
            top = top->next;
        }
        
        return re->next;
    }
};

int main() {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(3);
    head->next->next = new ListNode(2);
    
    Solution so;
    ListNode *ans = so.deleteDuplicates(head);
    
    while (ans != NULL) {
        cout << ans->val << " ";
        ans = ans->next;
    }
    return 0;
}