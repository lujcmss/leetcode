#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
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
    int sum;
    void solve(TreeNode *root, int tsum) {
        tsum = tsum * 10 + root->val;
        if (root->left == NULL && root->right == NULL) {
            sum += tsum;
            return;
        }
        if (root->left != NULL) solve(root->left, tsum);
        if (root->right != NULL) solve(root->right, tsum);
    }
public:
    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sum = 0;
        if (root != NULL) solve(root, 0);
        return sum;
    }
};

int main() {
    TreeNode root(0);
    //root.left = new TreeNode(1);
    root.right = new TreeNode(1);
    
    Solution so;
    int ans = so.sumNumbers(&root);
    cout << ans << endl;
}
