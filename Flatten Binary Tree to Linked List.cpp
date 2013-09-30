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
    TreeNode *now;
    void dfs1(TreeNode *root, int flag) {
        if (root == NULL) return;
        if (flag == 0) now = root;
        else {
            now->left = root;
            now = now->left;
        }
        if (root->left != NULL) dfs1(root->left, 0);
        if (root->right != NULL) dfs1(root->right, 1);
    }
    
    void dfs2(TreeNode *root) {
        if (root == NULL || root->left == NULL) return;
        root->right = root->left;
        root->left = NULL;
        dfs2(root->right);
    }
public:
    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        dfs1(root, 0);
        dfs2(root);
    }
};

int main() {
    TreeNode root(NULL);
    
    Solution so;
    so.flatten(&root);
}
