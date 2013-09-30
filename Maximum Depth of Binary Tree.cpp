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
    int maxl;
    
    void dfs(TreeNode *root, int deep) {
        if (root == NULL) return;
        if (deep > maxl) maxl = deep;
        
        dfs(root->left, deep+1);
        dfs(root->right, deep+1);
    }
public:
    int maxDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        maxl = -1;
        dfs(root, 0);

        return maxl+1;
    }
};

int main() {
    TreeNode root(1);
    root.left = new TreeNode(2);
    root.right = new TreeNode(3);
    
    Solution so;
    int ans = so.maxDepth(&root);
    cout << ans << endl;
    
    return 0;
}