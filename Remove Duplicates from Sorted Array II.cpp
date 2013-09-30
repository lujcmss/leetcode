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
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int re = 0;
        for (int i = 0; i < n; i++) {
            if (i + 2 >= n) A[re++] = A[i];
            else if (A[i] != A[i+2]) A[re++] = A[i];
        }
        
        return re;
    }
};

int main() {
    int a[6] = {1, 1, 1, 2, 2, 3};
    
    Solution so;
    int ans = so.removeDuplicates(a, 6);
    
    cout << ans << endl;
    
    return 0;
}