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
    vector<int> re;
    
    void dfs(vector<vector<int> > &matrix, int u, int d, int l, int r) {
        if (u >= d || l >= r) return;
        
        for (int j = l; j < r; j++)
            re.push_back(matrix[u][j]);
        for (int i = u+1; i < d; i++)
            re.push_back(matrix[i][r-1]);
        if (u + 1 < d) {
            for (int j = r-2; j >= l; j--)
                re.push_back(matrix[d-1][j]);
        }
        if (l + 1 < r) {
            for (int i = d-2; i > u; i--)
                re.push_back(matrix[i][l]);
        }
        
        dfs(matrix, u+1, d-1, l+1, r-1);
    }
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        re.clear();
        if (matrix.size() == 0 || matrix[0].size() == 0) return re;
        
        dfs(matrix, 0, (int)matrix.size(), 0, (int)matrix[0].size());
        
        return re;
    }
};

int main() {
    vector<vector<int> > ma(3, vector<int>(1));
    ma[0][0] = 1; //ma[0][1] = 2; ma[0][2] = 3;
    ma[1][0] = 4; //ma[1][1] = 5; ma[1][2] = 6;
    ma[2][0] = 7; //ma[2][1] = 8; ma[2][2] = 9;
    
    Solution so;
    vector<int> ans = so.spiralOrder(ma);
    
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    
    return 0;
}