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
    bool hasCycle(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (head == NULL) return false;
        ListNode *tmp1 = head;
        ListNode *tmp2 = head->next;
        while (tmp1 != tmp2) {
            if (tmp2 == NULL || tmp2->next == NULL) return false;
            tmp1 = tmp1->next;
            tmp2 = tmp2->next->next;
        }
        return true;
    }
};
int main() {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = head->next->next->next;
    
    Solution so;
    bool ans = so.hasCycle(head);
    
    cout << ans << endl;
    
    return 0;
}