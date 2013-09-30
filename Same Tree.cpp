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
    bool flag;
    
    void dfs(TreeNode *rootl, TreeNode *rootr) {
        if (rootl == NULL && rootr == NULL) return;
        if (rootl == NULL && rootr != NULL) flag = false;
        if (rootl != NULL && rootr == NULL) flag = false;
        if (!flag) return;
        
        if (rootl->val != rootr->val) flag = false;
        if (rootl->left == NULL && rootr->left != NULL) flag = false;
        if (rootl->left != NULL && rootr->left == NULL) flag = false;
        if (rootl->right == NULL && rootr->right != NULL) flag = false;
        if (rootl->right != NULL && rootr->right == NULL) flag = false;
        
        if (!flag) return;
        if (rootl->left != NULL) dfs(rootl->left, rootr->left);
        if (rootl->right != NULL) dfs(rootl->right, rootr->right);
    }
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        flag = true;
        dfs(p, q);
        
        return flag;
    }
};

int main() {
    TreeNode root(1);
    root.left = new TreeNode(2);
    root.right = new TreeNode(2);
    
    Solution so;
    bool ans = so.isSameTree(&root, &root);
    cout << ans << endl;
    
    return 0;
}