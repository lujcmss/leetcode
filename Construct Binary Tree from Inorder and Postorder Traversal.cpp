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
                  vector<int> &postorder, int lpost, int rpost) {
        if (lin >= rin) return root;
        
        root = new TreeNode(postorder[rpost-1]);
        if (lin + 1 == rin) return root;
        
        int k = 0;
        for (int i = lin; i < rin; i++) {
            if (inorder[i] == postorder[rpost-1]) k = i;
        }
        dfs(root->left, inorder, lin, k, postorder, lpost, lpost+k-lin);
        dfs(root->right, inorder, k+1, rin, postorder, lpost+k-lin, rpost-1);
        return root;
    }
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        TreeNode *re = NULL;
        if (inorder.size() == 0) return re;
        
        re = dfs(re, inorder, 0, (int)inorder.size(), postorder, 0, (int)postorder.size());
        
        return re;
    }
};

int main() {
    vector<int> inorder;
    inorder.push_back(2); inorder.push_back(1); inorder.push_back(3);
    
    vector<int> postorder;
    postorder.push_back(2); postorder.push_back(3); postorder.push_back(1);
    
    Solution so;
    TreeNode *ans = so.buildTree(inorder, postorder);
    cout << ans->val << endl;
    
    return 0;
}