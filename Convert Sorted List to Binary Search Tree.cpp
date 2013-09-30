#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
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

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    void dfs(TreeNode *&root, vector<int> &num, int l, int r) {
        if (l >= r) return;
        if (l + 1 == r) {
            root = new TreeNode(num[l]);
            return;
        }
        
        int mid = (l+r)/2;
        root = new TreeNode(num[mid]);
        dfs(root->left, num, l, mid);
        dfs(root->right, num, mid+1, r);
    }
public:
    TreeNode *sortedListToBST(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> num;
        num.clear();
        while (head != NULL) {
            num.push_back(head->val);
            head = head->next;
        }
        
        TreeNode *root = NULL;
        dfs(root, num, 0, (int)num.size());
        
        return root;
    }
};

int main() {
    ListNode *head = NULL, *tmp;
    tmp = new ListNode(0);
    head = tmp;
    for (int i = 1; i < 10; i++) {
        tmp->next = new ListNode(i);
        tmp = tmp->next;
    }
    
    Solution so;
    TreeNode *ans = so.sortedListToBST(head);
    cout << ans->val;
}

