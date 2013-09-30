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
    int re;
    void dfs(TreeNode *root, int deep) {
        if (root->left == NULL && root->right == NULL) {
            re = min(re, deep);
            return;
        }
        if (root->left != NULL) dfs(root->left, deep+1);
        if (root->right != NULL) dfs(root->right, deep+1);
    }
public:
    int minDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL) return 0;
        
        re = ~0U>>1;
        dfs(root, 1);
        
        return re;
    }
};

int main() {
    TreeNode root(2);
    root.left = new TreeNode(2);
    root.right = new TreeNode(1);
    root.right->right = new TreeNode(1);
    
    Solution so;
    int ans = so.minDepth(&root);
    cout << ans;
}
