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
    int maxn;
    
    void dfs(TreeNode *root) {
        if (root->left == NULL && root->right == NULL) {
            maxn = max(maxn, root->val);
            return;
        }
        if (root->left != NULL) dfs(root->left);
        if (root->right != NULL) dfs(root->right);
        
        int tmpl = -(~0U>>1), tmpr = -(~0U>>1);
        if (root->left != NULL) tmpl = root->left->val;
        if (root->right != NULL) tmpr = root->right->val;
        maxn = max(maxn, root->val+max(0,tmpl)+max(0,tmpr));
        root->val += max(max(0,tmpl), max(0,tmpr));
    }
public:
    int maxPathSum(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        maxn = -(~0U>>1);
        dfs(root);
        return maxn;
    }
};

int main() {
    TreeNode root(-2);
    root.left = new TreeNode(1);
    //root.right = new TreeNode(-3);
    
    Solution so;
    int ans = so.maxPathSum(&root);
    cout << ans;
}
