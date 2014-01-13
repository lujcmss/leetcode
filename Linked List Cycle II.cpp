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
    ListNode *detectCycle(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (head == NULL || head->next == NULL) return NULL;
        ListNode *a = head->next;
        ListNode *b = head->next->next;
        
        while (a != b) {
            if (b == NULL || b->next == NULL) return NULL;
            a = a->next;
            b = b->next->next;
        }
        a = head;
        
        while (a != b) {
            a = a->next;
            b = b->next;
        }
        
        return a;
    }
};
int main() {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = head->next->next->next;
    
    Solution so;
    ListNode* ans = so.detectCycle(head);
    
    cout << ans->val << endl;
    
    return 0;
}