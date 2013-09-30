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
    bool hasPathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        re.clear(); tmp.clear();
        dfs(root, sum);
        
        return (re.size() == 0) ? false : true;
    }
};

int main() {
    TreeNode root(2);
    root.left = new TreeNode(2);
    root.right = new TreeNode(1);
    root.right->right = new TreeNode(1);
    
    Solution so;
    bool ans = so.hasPathSum(&root, 5);
    cout << ans;
}
