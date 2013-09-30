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
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    vector<vector<int> > level;
    int maxl;
    
    void dfs(TreeNode *root, int deep) {
        if (root == NULL) return;
        if (deep > maxl) {
            maxl = deep;
            vector<int> tmp;
            tmp.clear();
            level.push_back(tmp);
        }
        
        level[deep].push_back(root->val);
        dfs(root->left, deep+1);
        dfs(root->right, deep+1);
    }
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        level.clear();
        maxl = -1;
        dfs(root, 0);
        
        vector<vector<int> > ans;
        ans.clear();
        ans.resize(maxl+1);
        
        for (int i = 0; i < maxl+1; i++)
            for (int j = 0; j < level[i].size(); j++)
                ans[maxl-i].push_back(level[i][j]);
        return ans;
    }
};

int main() {
    TreeNode root(1);
    root.left = new TreeNode(2);
    root.right = new TreeNode(3);
    
    Solution so;
    vector<vector<int> > ans = so.levelOrderBottom(&root);
    
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) cout << ans[i][j] << " ";
        cout << endl;
    }
    
    return 0;
}