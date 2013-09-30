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
        if (rootl->val != rootr->val) flag = false;
        if (rootl->left == NULL && rootr->right != NULL) flag = false;
        if (rootl->left != NULL && rootr->right == NULL) flag = false;
        if (rootl->right == NULL && rootr->left != NULL) flag = false;
        if (rootl->right != NULL && rootr->left == NULL) flag = false;
        
        if (!flag) return;
        if (rootl->left != NULL) dfs(rootl->left, rootr->right);
        if (rootr->left != NULL) dfs(rootr->left, rootl->right);
    }
public:
    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        flag = true;
        if (root != NULL) dfs(root, root);
        
        return flag;
    }
};

int main() {
    TreeNode root(1);
    root.left = new TreeNode(2);
    root.right = new TreeNode(2);
    
    Solution so;
    bool ans = so.isSymmetric(&root);
    cout << ans << endl;
    
    return 0;
}