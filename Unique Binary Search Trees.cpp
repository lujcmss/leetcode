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
    int numTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> f;
        f.clear();
        
        f.push_back(0); f.push_back(1);
        for (int i = 2; i <= n+1; i++) {
            int x = 0;
            for (int j = 0; j < i; j++)
                x += f[j]*f[i-j];
            f.push_back(x);
        }
        return f[n+1];
    }
};

int main() {
    int n = 3;
    
    Solution so;
    int ans = so.numTrees(n);
    
    cout << ans << endl;
    
    return 0;
}