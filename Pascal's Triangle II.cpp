#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ans(rowIndex+1);
        
        for (int i = 0; i <= rowIndex; i++)
            for (int j = 0; j <= i; j++)
                if (j == 0 || j == i) ans[i].push_back(1);
                else ans[i].push_back(ans[i-1][j]+ans[i-1][j-1]);
        
        return ans[rowIndex];
    }
};

int main() {
    
    Solution so;
    vector<int> ans = so.getRow(3);
    
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
        cout << endl;
}
