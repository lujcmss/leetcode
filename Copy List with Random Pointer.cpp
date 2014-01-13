#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
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
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
private:
    map<RandomListNode*, RandomListNode*> ma;
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (head == NULL) return NULL;
        ma.clear();
        
        RandomListNode* re = new RandomListNode(head->label);
        ma.insert(make_pair(head, re));
        RandomListNode* now = re;
        RandomListNode* tmp = head;
        while (tmp->next != NULL) {
            tmp = tmp->next;
            now->next = new RandomListNode(tmp->label);
            ma.insert(make_pair(tmp, now->next));
            now = now->next;
        }
        
        now = re;
        tmp = head;
        while (tmp != NULL) {
            if (tmp->random != NULL) {
                now->random = ma[tmp->random];
            }
            now = now->next;
            tmp = tmp->next;
        }
        
        return re;
    }
};

int main() {
    RandomListNode *head = new RandomListNode(0);
    head->next = new RandomListNode(1);
    head->next->next = new RandomListNode(1);
    head->next->next->next = new RandomListNode(1);
    
    Solution so;
    RandomListNode *ans = so.copyRandomList(head);
    
    while (ans != NULL) {
        cout << ans->label << " ";
        ans = ans->next;
    }
    
    return 0;
}