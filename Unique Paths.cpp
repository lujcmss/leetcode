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
    int uniquePaths(int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<vector<int> > f(m+1, vector<int>(n+1));
        
        f[1][1] = 1;
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                if (i + j > 2) f[i][j] = f[i-1][j] + f[i][j-1];
        
        return f[m][n];
    }
};

int main() {
    int m = 100, n = 100;
    
    Solution so;
    int ans = so.uniquePaths(m, n);
    
    cout << ans << endl;
    
    return 0;
}