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
    vector<vector<int> > re;
    vector<int> tmp;
    
    void dfs(TreeNode *root, int sum) {
        if (root == NULL) return;
        if (root->left == NULL && root->right == NULL) {
            tmp.push_back(root->val);
            if (sum == root->val) re.push_back(tmp);
            tmp.pop_back();
            return;
        }
        tmp.push_back(root->val);
        if (root->left != NULL) dfs(root->left, sum - root->val);
        if (root->right != NULL) dfs(root->right, sum - root->val);
        tmp.pop_back();
    }
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        re.clear(); tmp.clear();
        dfs(root, sum);
        
        return re;
    }
};

int main() {
    TreeNode root(2);
    root.left = new TreeNode(2);
    root.right = new TreeNode(1);
    root.right->right = new TreeNode(1);
    
    Solution so;
    vector<vector<int> > ans = so.pathSum(&root, 4);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) cout << ans[i][j] << " ";
        cout << endl;
    }
}