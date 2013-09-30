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
    int minPathSum(vector<vector<int> > &grid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (grid.size() == 0) return 0;
        
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[i].size(); j++)
                if (i == 0 && j == 0) continue;
                else if (i == 0 && j != 0) grid[i][j] += grid[i][j-1];
                else if (i != 0 && j == 0) grid[i][j] += grid[i-1][j];
                else grid[i][j] += min(grid[i][j-1], grid[i-1][j]);
        
        return grid[grid.size()-1][grid[0].size()-1];
    }
};

int main() {
    vector<vector<int> > grid(2, vector<int>(2));
    grid[0][0] = 1; grid[0][1] = 3;
    grid[1][0] = 2; grid[1][1] = 2;
    
    Solution so;
    int ans = so.minPathSum(grid);
    
    cout << ans << endl;
    
    return 0;
}