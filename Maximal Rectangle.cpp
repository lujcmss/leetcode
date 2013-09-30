#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (matrix.size() == 0) return 0;
        
        vector<vector<int> > f(matrix.size()+1, vector<int>(matrix[0].size()+1));
        int maxn = 0;
        for (int i = 1; i <= matrix.size(); i++)
            for (int j = 1; j <= matrix[i-1].size(); j++) {
                if (matrix[i-1][j-1] == '1')
                    if (j == 1) f[i][j] = 1;
                    else f[i][j] = f[i][j-1]+1;
                else f[i][j] = 0;
                
                int tmp = f[i][j];
                for (int k = i; k >= 1; k--) {
                    maxn = max(maxn, (i-k+1) * tmp);
                    tmp = min(tmp, f[k-1][j]);
                }
            }
        
        return maxn;
    }
};

int main() {
    vector<vector<char> > matrix(1, vector<char>(1));
    matrix[0][0] = '1';
    //matrix[1][1] = '1'; matrix[1][2] = '1';
    //matrix[2][1] = '1'; matrix[2][2] = '1';
    
    Solution so;
    int ans = so.maximalRectangle(matrix);
    
    cout << ans << endl;
    return 0;
}