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
    int jump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n == 0) return 0;
        
        vector<int> minn;
        minn.resize(n);
        for (int i = 0; i < n; i++) minn[i] = -1;
        
        minn[0] = 0;
        int maxn = 0;
        for (int i = 0; i < n; i++) {
            for (int j = max(maxn - i + 1, 1); j <= A[i]; j++)
                if (i + j < n) {
                    if (minn[i+j] == -1) minn[i+j] = minn[i] + 1;
                    else minn[i+j] = min(minn[i+j], minn[i] + 1);
                }
            maxn = max(maxn, i + A[i]);
        }
        
        return minn[n-1];
    }
};

int main() {
    int a[20] = {2, 1, 1, 1, 4};
    
    Solution so;
    int ans = so.jump(a, 5);
    
    cout << ans << endl;
    
    return 0;
}