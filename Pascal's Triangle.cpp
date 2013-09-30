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
    vector<vector<int> > generate(int numRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ans(numRows);
        for (int i = 0; i < numRows; i++)
            for (int j = 0; j <= i; j++)
                if (j == 0 || j == i) ans[i].push_back(1);
                else ans[i].push_back(ans[i-1][j]+ans[i-1][j-1]);
        
        return ans;
    }
};

int main() {
    
    Solution so;
    vector<vector<int> > ans = so.generate(5);
    
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) cout << ans[i][j] << " ";
        cout << endl;
    }
}
