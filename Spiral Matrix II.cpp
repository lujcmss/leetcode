#include <stdio.h>
#include <math.h>
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
    int num;
    
    void dfs(int u, int d, int l, int r) {
        if (u >= d || l >= r) return;
        
        for (int j = l; j < r; j++)
            re[u][j] = num++;
        for (int i = u+1; i < d; i++)
            re[i][r-1] = num++;
        if (u + 1 < d) {
            for (int j = r-2; j >= l; j--)
                re[d-1][j] = num++;
        }
        if (l + 1 < r) {
            for (int i = d-2; i > u; i--)
                re[i][l] = num++;
        }
        
        dfs(u+1, d-1, l+1, r-1);
    }
public:
    vector<vector<int> > generateMatrix(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        re.resize(n);
        for (int i = 0; i < n; i++)
            re[i].resize(n);
        
        num = 1;
        dfs(0, n, 0, n);
        
        return re;
    }
};

int main() {
    int n = 1;
    
    Solution so;
    vector<vector<int> > ans = so.generateMatrix(n);
    
    for (int i = 0; i < ans.size(); i++, cout << endl)
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
    
    return 0;
}