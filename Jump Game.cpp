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
    bool canJump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n == 0) return false;
        
        int maxn = 0;
        for (int i = 0; i < n; i++)
            if (maxn >= i) maxn = max(maxn, i+A[i]);
        
        return (maxn >= n -1) ? true : false;
    }
};

int main() {
    int a[20] = {1,1,1,1,4};
    
    Solution so;
    bool ans = so.canJump(a, 9);
    
    cout << ans << endl;
    
    return 0;
}