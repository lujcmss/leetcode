#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
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
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
private:
    map<int, UndirectedGraphNode *> num;
    
    void dfs(UndirectedGraphNode *now, UndirectedGraphNode *node) {
        for (int i = 0; i < node->neighbors.size(); i++) {
            UndirectedGraphNode *tmp = node->neighbors[i];
            if (num.count(tmp->label) == 0) {
                UndirectedGraphNode *add = new UndirectedGraphNode(tmp->label);
                now->neighbors.push_back(add);
                num.insert(make_pair(tmp->label, add));
                dfs(add, tmp);
            } else {
                now->neighbors.push_back(num[tmp->label]);
            }
        }
    }
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (node == NULL) return NULL;

        num.clear();
        
        UndirectedGraphNode *re;
        re = new UndirectedGraphNode(node->label);
        num.insert(make_pair(re->label, re));
        dfs(re, node);
        
        return re;
    }
};

int main() {
    UndirectedGraphNode *node = new UndirectedGraphNode(0);
    node->neighbors.push_back(node);
    node->neighbors.push_back(node);
    
    Solution so;
    UndirectedGraphNode *ans = so.cloneGraph(node);
    
    cout << ans->label;
    
    return 0;
}