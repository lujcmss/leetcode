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

/* O(n^2) TLE
class Solution {
    public:
    void reorderList(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int step = 0;
        while (1) {
            ListNode *now = head;
            for (int i = 0; i < step; i++) {
                if (now != NULL);
                now = now->next;
            }
            if (now == NULL || now->next == NULL) return;
            
            ListNode *last = head;
            while (last->next->next != NULL) {
                last = last->next;
            }
            
            if (now != last) {
                last->next->next = now->next;
                now->next = last->next;
                last->next = NULL;
            }
            step += 2;
        }
    }
};
*/

class Solution {
    public:
    void reorderList(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (head == NULL) return;
        
        int n = 0;
        ListNode *tmp = head;
        while (tmp != NULL) {
            tmp = tmp->next;
            n++;
        }
        
        tmp = head;
        for (int i = 0; i < (n-1) / 2; i++) {
            tmp = tmp->next;
        }
        ListNode *now = tmp->next;
        
        while (now != NULL) {
            ListNode *ne = now->next;
            if (tmp->next != now) {
                now->next = tmp->next;
                tmp->next = now;
            } else {
                now->next = NULL;
            }
            now = ne;
        }
        
        tmp = head;
        for (int i = 0; i < (n-1) / 2; i++) {
            tmp = tmp->next;
        }
        now = tmp->next;
        tmp->next = NULL;
        tmp = head;
        
        while (tmp != NULL && now != NULL) {
            ListNode *tmpne = tmp->next;
            ListNode *nowne = now->next;
            
            tmp->next = now;
            now->next = tmpne;
            tmp = tmpne;
            now = nowne;
        }
    }
};

int main() {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    
    Solution so;
    so.reorderList(head);
    
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    
    return 0;
}