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
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};


class Solution {
private:
    vector<TreeLinkNode*> layer;
    
    void dfs(TreeLinkNode* root, int deep) {
        if (root == NULL) return;
        if (layer.size() == deep) {
            layer.push_back(root);
        }
        else {
            layer[deep]->next = root;
            layer[deep] = root;
        }
        
        if (root->left == NULL && root->right == NULL) return;
        if (root->left != NULL) dfs(root->left, deep+1);
        if (root->right != NULL) dfs(root->right, deep+1);
    }
public:
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        dfs(root, 0);
    }
};

int main() {
    TreeLinkNode root(1);
    root.left = new TreeLinkNode(1);
    root.right = new TreeLinkNode(2);
    
    Solution so;
    so.connect(&root);
}
