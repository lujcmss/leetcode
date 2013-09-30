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
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (matrix.size() == 0) return false;
        int l = 0, r = (int)(matrix.size()*matrix[0].size())-1;
        while (l < r) {
            int mid = (l+r)>>1;
            int x = mid / matrix[0].size();
            int y = mid % matrix[0].size();
            if (matrix[x][y] < target) l = mid+1;
            else r = mid;
        }
        
        if (matrix[l / matrix[0].size()][l % matrix[0].size()] == target) return true;
        return false;
    }
};

int main() {
    vector<vector<int> > matrix(1, vector<int>(2));
    matrix[0][0] = 1; matrix[0][1] = 1;
    //matrix[1][0] = 1; matrix[1][1] = 1;
    
    Solution so;
    bool ans = so.searchMatrix(matrix, 2);
    
    cout << ans << endl;
    
    return 0;
}