#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>
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
    vector<int> re;
    void dfs(TreeNode *root) {
        if (root == NULL) return;
        dfs(root->left);
        re.push_back(root->val);
        dfs(root->right);
    }
public:
    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        re.clear();
        dfs(root);
        
        return re;
    }
};

int main() {
    TreeNode *root;
    root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    
    Solution so;
    vector<int> ans = so.inorderTraversal(root);
    
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    
    return 0;
}