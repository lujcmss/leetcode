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
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    bool findfirst;
    TreeNode *last;
    TreeNode *first, *second;
    
    void dfs(TreeNode *root) {
        if (root->left != NULL) dfs(root->left);
        
        if (last == NULL) last = root;
        else if (last->val > root->val) {
            if (!findfirst) first = last;
            findfirst = true;
            second = root;
        }
        last = root;
        
        if (root->right != NULL) dfs(root->right);
    }
public:
    void recoverTree(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        last = NULL;
        findfirst = false;
        dfs(root);
        int tmp;
        tmp = first->val;
        first->val = second->val;
        second->val = tmp;
    }
};

int main() {
    TreeNode *root;
    root = new TreeNode(1);
    //root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(2);
    
    Solution so;
    so.recoverTree(root);
    
    return 0;
}