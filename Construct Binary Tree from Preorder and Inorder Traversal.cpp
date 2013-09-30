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
    TreeNode *dfs(TreeNode *&root, vector<int> &inorder, int lin, int rin,
                  vector<int> &preorder, int lpre, int rpre) {
        if (lin >= rin) return root;
        
        root = new TreeNode(preorder[lpre]);
        if (lin + 1 == rin) return root;
        
        int k = 0;
        for (int i = lin; i < rin; i++) {
            if (inorder[i] == preorder[lpre]) k = i;
        }
        dfs(root->left, inorder, lin, k, preorder, lpre+1, lpre+k-lin+1);
        dfs(root->right, inorder, k+1, rin, preorder, lpre+k-lin+1, rpre);
        return root;
    }
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        TreeNode *re = NULL;
        if (inorder.size() == 0) return re;
        
        re = dfs(re, inorder, 0, (int)inorder.size(), preorder, 0, (int)preorder.size());
        
        return re;
    }
};

int main() {
    vector<int> inorder;
    inorder.push_back(2); inorder.push_back(1); inorder.push_back(3);
    
    vector<int> preorder;
    preorder.push_back(1); preorder.push_back(2); preorder.push_back(3);
    
    Solution so;
    TreeNode *ans = so.buildTree(preorder, inorder);
    cout << ans->val << endl;
    
    return 0;
}