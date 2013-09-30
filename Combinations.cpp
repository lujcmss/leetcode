#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <stack>

using namespace std;

class Solution {
private:
    vector<vector<int> > re;
    vector<int> tmp;
    
    void dfs(int &n, int now, int k) {
        if (k == 0) {
            re.push_back(tmp);
            return;
        }
        
        for (int i = now; i <= n; i++) {
            tmp.push_back(i);
            dfs(n, i+1, k-1);
            tmp.pop_back();
        }
    }
public:
    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        re.clear();
        tmp.clear();
        
        dfs(n, 1, k);
        
        return re;
    }
};

int main() {
    int n = 4, k = 2;
    
    Solution so;
    vector<vector<int> > ans = so.combine(n, k);
    
    for (int i = 0; i < ans.size(); i++, cout << endl)
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
    
    return 0;
}