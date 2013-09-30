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
    void dfs(vector<TreeNode *> &re, int l, int r) {
        if (l == r) {
            re.push_back(NULL);
            return;
        }
        
        for (int i = l; i < r; i++) {
            vector<TreeNode *> left;
            vector<TreeNode *> right;
            left.clear(); right.clear();
            
            dfs(left, l, i);
            dfs(right, i+1, r);
            
            for (int j = 0; j < left.size(); j++)
                for (int k = 0; k < right.size(); k++) {
                    TreeNode *root = new TreeNode(i+1);
                    root->left = left[j];
                    root->right = right[k];
                    re.push_back(root);
                }
        }
    }
public:
    vector<TreeNode *> generateTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<TreeNode *> re;
        re.clear();
        dfs(re, 0, n);
        
        return re;
    }
};

int main() {
    int n = 3;
    
    Solution so;
    vector<TreeNode *> ans = so.generateTrees(n);
    
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i]->val << " ";
    
    cout << endl;
    
    return 0;
}