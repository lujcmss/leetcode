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
    
    void dfs(TreeNode *root) {
        if (root == NULL) return;
        if (root->left != NULL) dfs(root->left);
        
        if (last == NULL) last = root;
        else if (last->val >= root->val) findfirst = true;
        last = root;
        
        if (root->right != NULL) dfs(root->right);
    }
public:
    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        last = NULL;
        findfirst = false;
        dfs(root);
        
        return !findfirst;
    }
};

int main() {
    TreeNode *root;
    root = new TreeNode(1);
    root->left = new TreeNode(0);
    root->right = new TreeNode(3);
    //root->right->right = new TreeNode(2);
    
    Solution so;
    bool ans = so.isValidBST(root);
    
    cout << ans << endl;
    
    return 0;
}