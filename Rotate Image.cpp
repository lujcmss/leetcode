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
    void dfs(vector<vector<int> > &matrix, int u, int d, int l, int r) {
        if (u >= d || l >= r) return;
        
        for (int i = 0; i < d - u - 1; i++) {
            int t = matrix[u][l+i];
            matrix[u][l+i] = matrix[d-1-i][l];
            matrix[d-1-i][l] = matrix[d-1][r-1-i];
            matrix[d-1][r-1-i] = matrix[u+i][r-1];
            matrix[u+i][r-1] = t;
        }
        dfs(matrix, u+1, d-1, l+1, r-1);
    }
public:
    void rotate(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (matrix.size() == 0) return;
        
        dfs(matrix, 0, (int)matrix.size(), 0, (int)matrix[0].size());
    }
};

int main() {
    vector<vector<int> > ma(1, vector<int>(1));
    ma[0][0] = 0; //ma[0][1] = 1; ma[0][2] = 2;
    //ma[1][0] = 3; ma[1][1] = 4; ma[1][2] = 5;
    //ma[2][0] = 6; ma[2][1] = 7; ma[2][2] = 8;
    
    Solution so;
    so.rotate(ma);
    
    for (int i = 0; i < ma.size(); i++, cout << endl)
        for (int j = 0; j < ma[i].size(); j++)
            cout << ma[i][j] << " ";
    
    return 0;
}