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
    bool search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int l = 0, r = n;
        while (l != r) {
            int mid = (l+r)/2;
            if (A[mid] == target) return true;
            if (A[mid] > A[l]) {
                if (target >= A[l] && target < A[mid]) r = mid;
                else l = mid+1;
            } else if (A[mid] < A[l]) {
                if (target >= A[l] || target <= A[mid]) r = mid;
                else l = mid+1;
            } else {
                l++;
            }
        }
        
        return false;
    }
};

int main() {
    int a[7] = {5, 3, 5, 5, 3, 5, 5};
    
    Solution so;
    bool ans = so.search(a, 2, 3);
    
    cout << ans << endl;
    
    return 0;
}