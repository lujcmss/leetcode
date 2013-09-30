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
    int maxSubArray(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n == 0) return 0;
        
        int minn = 0;
        int maxn = A[0];
        int sum = 0;
        
        for (int i = 0; i < n; i++) {
            sum += A[i];
            if (i != 0) maxn = max(maxn, sum - minn);
            minn = min(minn, sum);
        }
        
        return maxn;
    }
};

int main() {
    int a[20] = {-11, -1, -3, -4, -1, -2, -1, -5, 5};
    
    Solution so;
    int ans = so.maxSubArray(a, 9);
    
    cout << ans << endl;
    
    return 0;
}