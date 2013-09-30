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
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (triangle.size() == 0) return 0;
        
        for (int i = 1; i < triangle.size(); i++)
            for (int j = 0; j <= i; j++)
                if (j == 0) triangle[i][j] += triangle[i-1][j];
                else if (j == i) triangle[i][j] += triangle[i-1][j-1];
                else triangle[i][j] += min(triangle[i-1][j-1], triangle[i-1][j]);
        
        int re = ~0U>>1;
        for (int i = 0; i < triangle.size(); i++) re = min(re, triangle[triangle.size()-1][i]);
        
        return re;
    }
};

int main() {
    vector<vector<int> > tri(2);
    for (int i = 0; i < 2; i++)
        for (int j = 0; j <= i; j++)
            tri[i].push_back(j+1);
    
    Solution so;
    int ans = so.minimumTotal(tri);
    cout << ans;
}
