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
    int search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int l = 0, r = n-1;
        while (l != r) {
            int mid = (l+r)/2;
            if (A[mid] >= A[0]) l = mid+1;
            else r = mid;
        }
        
        int index_min;
        if (A[0] < A[n-1]) index_min = 0;
        else index_min = l;
        
        l = 0; r = n;
        while (l != r) {
            int mid = (l+r)/2;
            if (A[(index_min+mid)%n] < target) l = mid+1;
            else r = mid;
        }
        
        if (A[(index_min+l)%n] == target) return (index_min+l)%n;
        else return -1;
    }
};

int main() {
    int a[7] = {4, 5, 6, 7, 0, 1, 2};
    
    Solution so;
    int ans = so.search(a, 7, 0);
    
    cout << ans << endl;
    
    return 0;
}