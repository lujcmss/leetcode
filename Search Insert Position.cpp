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
    int searchInsert(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int l = 0, r = n;
        while (l < r) {
            int mid = (l+r)/2;
            if (A[mid] < target) l = mid+1;
            else r = mid;
        }
        
        return l;
    }
};

int main() {
    int a[20] = {1,3,5,6};
    
    Solution so;
    int ans = so.searchInsert(a, 4, 7);
    
    cout << ans << endl;
    
    return 0;
}