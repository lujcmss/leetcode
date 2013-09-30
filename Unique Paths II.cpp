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
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (obstacleGrid.size() == 0) return 0;
        
        int m = (int)obstacleGrid.size();
        int n = (int)obstacleGrid[0].size();
        
        vector<vector<int> > f(m+1, vector<int>(n+1));
        
        if (obstacleGrid[0][0] == 0) f[1][1] = 1;
        else f[1][1] = 0;
        
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                if (i + j > 2) {
                    if (obstacleGrid[i-1][j-1] == 0) f[i][j] = f[i-1][j] + f[i][j-1];
                    else f[i][j] = 0;
                }
        
        return f[m][n];
    }
};

int main() {
    vector<vector<int> > grid(2, vector<int>(2));
    grid[0][1] = 1;
    
    Solution so;
    int ans = so.uniquePathsWithObstacles(grid);
    
    cout << ans << endl;
    
    return 0;
}