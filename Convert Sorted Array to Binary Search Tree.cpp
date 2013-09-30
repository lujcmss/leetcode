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
    void dfs(TreeNode *&root, vector<int> &num, int l, int r) {
        if (l >= r) return;
        if (l + 1 == r) {
            root = new TreeNode(num[l]);
            return;
        }
        
        int mid = (l+r)/2;
        root = new TreeNode(num[mid]);
        dfs(root->left, num, l, mid);
        dfs(root->right, num, mid+1, r);
    }
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        TreeNode *root = NULL;
        dfs(root, num, 0, (int)num.size());
        
        return root;
    }
};

int main() {
    vector<int> a;
    a.clear();
    for (int i = 0; i < 2; i++) a.push_back(i);
    
    Solution so;
    TreeNode *ans = so.sortedArrayToBST(a);
    cout << ans->val;
}

