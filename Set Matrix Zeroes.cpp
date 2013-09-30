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
    void setZeroes(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (matrix.size() == 0 || matrix[0].size() == 0) return;
        
        bool firstrow, firstcol;
        
        firstrow = firstcol = false;
        for (int i = 0; i < matrix.size(); i++)
            if (matrix[i][0] == 0) firstcol = true;
        for (int j = 0; j < matrix[0].size(); j++)
            if (matrix[0][j] == 0) firstrow = true;
        
        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < matrix[0].size(); j++)
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
        
        for (int i = 1; i < matrix.size(); i++)
            for (int j = 1; j < matrix[0].size(); j++)
                if (matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
        
        if (firstcol)
            for (int i = 0; i < matrix.size(); i++)
                matrix[i][0] = 0;
        if (firstrow)
            for (int j = 0; j < matrix[0].size(); j++)
                matrix[0][j] = 0;
    }
};

int main() {
    vector<vector<int> > matrix(2, vector<int>(2));
    matrix[0][0] = 1; matrix[0][1] = 1;
    matrix[1][0] = 0; matrix[1][1] = 1;
    
    Solution so;
    so.setZeroes(matrix);
    
    for (int i = 0; i < matrix.size(); i++, cout << endl)
        for (int j = 0; j < matrix[i].size(); j++)
            cout << matrix[i][j] << " ";
    
    return 0;
}