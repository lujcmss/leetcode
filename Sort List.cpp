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
    ListNode *sortList(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (head == NULL) return NULL;
        
        ListNode *top = new ListNode(0);
        top->next = head;
        
        ListNode *tmp1, *tmp2, *now, *nex, *tmp;
        int n = 1, tot = 0;
        
        tmp = head;
        while (tmp != NULL) {
            tmp = tmp->next;
            tot++;
        }
        
        while (n < tot) {
            now = top;
            nex = top->next;
            while (true) {
                tmp1 = nex;
                
                int k = 0;
                tmp2 = tmp1;
                while (tmp2 != NULL && k < n) {
                    if (k == n - 1) {
                        tmp = tmp2;
                    }
                    tmp2 = tmp2->next;
                    k++;
                }
                if (tmp != NULL) {
                    tmp->next = NULL;
                    tmp = NULL;
                }
                if (tmp2 == NULL) {
                    while (tmp1 != NULL) {
                        now->next = tmp1;
                        now = now->next;
                        tmp1 = tmp1->next;
                    }
                    break;
                }
                
                k = 0;
                nex = tmp2;
                while (nex != NULL && k < n) {
                    if (k == n - 1) {
                        tmp = nex;
                    }
                    nex = nex->next;
                    k++;
                }
                if (tmp != NULL) {
                    tmp->next = NULL;
                    tmp = NULL;
                }
                
                while (tmp1 != NULL || tmp2 != NULL) {
                    if (tmp2 == NULL || (tmp1 != NULL && tmp1->val < tmp2->val)) {
                        now->next = tmp1;
                        now = now->next;
                        tmp1 = tmp1->next;
                    } else {
                        now->next = tmp2;
                        now = now->next;
                        tmp2 = tmp2->next;
                    }
                }
            }
            n = n * 2;
        }
        
        return top->next;
    }
};

int main() {
    ListNode *head = new ListNode(9);
    head->next = new ListNode(8);
    head->next->next = new ListNode(7);
    head->next->next->next = new ListNode(6);
    //head->next->next->next->next = new ListNode(5);
    
    Solution so;
    ListNode *ans = so.sortList(head);
    
    while (ans != NULL) {
        cout << ans->val << " ";
        ans = ans->next;
    }
    
    return 0;
}