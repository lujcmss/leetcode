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
    ListNode *reverseKGroup(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *nextStart;
        ListNode *top = new ListNode(0);
        ListNode *last;
        int count;
        
        top->next = head;
        last = top;
        while (true) {
            nextStart = head;
            count = 0;
            while (count < k && nextStart != NULL) {
                nextStart = nextStart->next;
                count++;
            }
            if (count < k) break;
            
            for (int i = 1; i < k; i++) {
                ListNode *tmp = head->next;
                head->next = nextStart;
                nextStart = head;
                head = tmp;
                last->next = head;
            }
            head->next = nextStart;
            
            for (int i = 0; i < k; i++) {
                last = head;
                head = head->next;
            }
        }
        
        return top->next;
    }
};

int main() {
    ListNode *head = new ListNode(1);
    //head->next = new ListNode(2);
    //head->next->next = new ListNode(3);
    //head->next->next->next = new ListNode(4);
    //head->next->next->next->next = new ListNode(5);
    //head->next->next->next->next->next = new ListNode(6);
    //head->next->next->next->next->next->next = new ListNode(7);
    
    Solution so;
    ListNode *ans = so.reverseKGroup(head, 1);
    
    while (ans != NULL) {
        cout << ans->val << " ";
        ans = ans->next;
    }
    
    return 0;
}