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
    ListNode *partition(ListNode *head, int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *top = new ListNode(0);
        top->next = head;
        
        ListNode *now = top;
        ListNode *last = top;
        while (head != NULL) {
            if (head->val < x) {
                if (last == now) {
                    last = last->next;
                }
                else {
                    last->next = last->next->next;
                    head->next = now->next;
                    now->next = head;
                }
                
                now = now->next;
                head = last->next;
            }
            else {
                last = last->next;
                head = head->next;
            }
        }
        
        return top->next;
    }
};

int main() {
    ListNode *head = new ListNode(4);
    //head->next = new ListNode(3);
    
    Solution so;
    ListNode *ans = so.partition(head, 5);
    
    while (ans != NULL) {
        cout << ans->val << " ";
        ans = ans->next;
    }
    
    return 0;
}