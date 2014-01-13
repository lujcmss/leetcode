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
    ListNode *insertionSortList(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        ListNode *top = new ListNode(0);
        top->next = head;
        
        ListNode *last = top;
        ListNode *now = top->next;
        while (now != NULL) {
            ListNode *tmp = top;
            while (now->val > tmp->next->val) tmp = tmp->next;
            
            if (tmp->next == now) {
                last = last->next;
                now = now->next;
            } else {
                last->next = last->next->next;
                now->next = tmp->next;
                tmp->next = now;
                now = last->next;
            }
        }
        return top->next;
    }
};

int main() {
    ListNode *head = new ListNode(3);
    head->next = new ListNode(2);
    //head->next->next = new ListNode(3);
    //head->next->next->next = new ListNode(4);
    
    Solution so;
    ListNode *ans = so.insertionSortList(head);
    
    while (ans != NULL) {
        cout << ans->val << " ";
        ans = ans->next;
    }
    
    return 0;
}