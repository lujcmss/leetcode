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
    
    int dfs(TreeNode *root) {
        if (root == NULL) return 0;
        
        int l = dfs(root->left);
        int r = dfs(root->right);
        if (abs(l-r) > 1) flag = false;
        
        return max(l, r)+1;
    }
public:
    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        flag = true;
        dfs(root);
        
        return flag;
    }
};

int main() {
    TreeNode root(2);
    //root.left = new TreeNode(2);
    root.right = new TreeNode(1);
    root.right->right = new TreeNode(1);
    
    Solution so;
    bool ans = so.isBalanced(&root);
    cout << ans;
}

