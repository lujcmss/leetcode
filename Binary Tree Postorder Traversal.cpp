#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <stack>
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
    
    void post(TreeNode *root) {
        if (root == NULL) return;
        post(root->left);
        post(root->right);
        re.push_back(root->val);
    }
public:
    vector<int>postorderTraversal(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        re.clear();
        if (root == NULL) return re;
        post(root);
        
        return re;
    }
};

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    
    Solution so;
    vector<int> ans = so.postorderTraversal(root);
    
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    
    return 0;
}