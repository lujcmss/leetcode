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
    int climbStairs(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> f(n+1);
        f[0] = 1; f[1] = 1;
        for (int i = 2; i <= n; i++)
            f[i] = f[i-1] + f[i-2];
        
        return f[n];
    }
};

int main() {
    int n = 10;
    
    Solution so;
    int ans = so.climbStairs(n);
    
    cout << ans << endl;
    
    return 0;
}