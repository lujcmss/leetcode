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
    int maxArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int maxn = 0;
        
        int l, r;
        l = 0, r = (int)height.size() - 1;
        while (l < r) {
            maxn = max(maxn, (r - l) * min(height[l], height[r]));
            if (height[l] < height[r]) l++;
            else r--;
        }
        
        return maxn;
    }
};

int main() {
    vector<int> height;
    height.push_back(1);
    height.push_back(4);
    //height.push_back(3);
    
    Solution so;
    int ans = so.maxArea(height);
    
    cout << ans << endl;
    
    return 0;
}